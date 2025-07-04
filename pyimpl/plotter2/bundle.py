import random
import copy
class FrameData:

	def __init__(self,owner = -1, orgin = -1, data = None):
		self.framedata = [data]
		self.lock_key = owner
		self.orgin = orgin

	def set_owner_key(self, override_key, owner_key):
		oldlock = self.lock_key
		if(override_key == self.lock_key or self.lock_key < 0):
			self.lock_key = owner_key
			print("orgin:%d lock:%d old_lock:%d" % (self.orgin, self.lock_key, oldlock))

	def get_framedata(self):
		return self.framedata

	def set_framedata(self, data, owner_key):
		if(self.lock_key == owner_key):
			self.framedata.add(data)
		else:
			return

	def copy(self):
		return FrameData(self.lock_key, self.orgin, self.framedata)

	def __str__(self):
		return "data: " + str(self.framedata) + " lock: %d orgin: %d" % (self.lock_key, self.orgin)

class Frame:

	def __init__(self, key: int, orgin: int = -1, framedata = None):

		self.frame: list[FrameData] = [FrameData(owner= key, orgin=orgin, data=framedata)]
		self.available: list[FrameData] = self.frame.copy()

	def move(self):
		self.available.clear()

	def edit_owner(self, override, owner):

		for elem in self.frame:
			elem.set_owner_key(override,owner)



	def add_new_frame(self, new: "Frame"):
		new.move()
		self.frame.extend(new.frame)

	def add_alias_frame(self, new: "Frame"):
		new.move()
		#print(new.frame)
		self.frame.extend(new.frame)

	def edit_frame(self, data_to_add, override):

		for fr in self.frame:
			if(data_to_add in fr.get_framedata()):
				fr.set_framedata(data_to_add, override)

	def collect_frame(self):
		collected: set = []
		for fr in self.frame:
			collected.append(str(fr))
		return collected

	def access(self, frame_data, key):
		toremove = []
		for frame in self.frame:
			if(frame_data in frame.get_framedata()):
				if key != frame.lock_key:
					self.available.append(FrameData(self.key, frame.orgin, frame.get_framedata()))
				else:
					self.available.append(self.frame)
					toremove.append(frame)

		for i in toremove:
			self.frame.remove(i)
		return self.available
name_count = 0

class Bundle:

	def __init__(self, neighbours, data):
		global name_count
		self.name = name_count
		name_count += 1
		#owned by self
		self.owned = -1
		#key is unique
		self.key = random.randint(0, 1000)

		if not isinstance(neighbours, list):
			self.neighbours: list[Bundle] = [neighbours]
		elif(isinstance(neighbours, list)):

			self.neighbours: list[Bundle] = neighbours

		self.frame = Frame(self.key,self.name,  data)
		self.sticks_held = []
		self.stick = 0
		self.stick_type = "none"

	def share(self, other: "Bundle"):
		if(self.stick == 0):
			return
		temp: Frame = Frame(self.key, self.name)
		for i in self.frame.frame:
			temp.frame.append(i.copy())
		temp.edit_owner(self.key, other.key)
		other.frame.add_alias_frame(temp)
		if(self.owned == -1):
			self.owned
		#stick
		other.stick_type = "rock"
		other.stick = self.stick
		other.sticks_held.append(self.stick)
		if(self.stick_type == "stick"):
			self.stick_type = "holder"
		else:
			self.stick_type = "holder_sub"
		print("share")


	def handoff(self, other: "Bundle", key):
		if(self.stick == 0):
			return
		if(self.owned == -1):

			self.frame.edit_owner(self.key, key)
			other.frame.edit_owner(other.key, self.key)

			other.owned = self.name
			other.key = key

		else:

			other.frame.edit_owner(other.key, self.key)

		other.frame.add_new_frame(self.frame)

		#stick works

		other.sticks_held.append(self.stick)
		other.stick_type = self.stick_type
		other.stick = self.stick
		self.stick = 0
		self.stick_type = "none"
		print("handoff")



	def add_to_frame(self, add_to):
		self.frame.edit_frame(add_to, self.key)

	def do_something(self, incoming):
		"""does bundle stuff"""



		self.handoff(incoming, self.key)
		return

	def do_something1(self, incoming):


		self.handoff(incoming, self.key)



	def transform(self):


		self.add_to_frame("hello")
		for n in self.neighbours:

			if(random.randint(0, 1) != 1):
				self.share(n)



				n.transform()
			else:
				print("tried handoff")

				self.handoff(n, self.key)
				self.stick = 0
				n.transform()
		self.stick = 0
	def __str__(self):
		s= "bundle[ name: %d, key: %d, owned: %d, stickid: %d, stick_type: %s, children length: %d] " % (self.name, self.key, self.owned, self.stick, self.stick_type, len(self.neighbours))
		for i in self.frame.collect_frame():
			s+= "\n\t" + str(i)
		return s
def random_data():
	lines = []
	with open("res.csv", 'r') as f:
		for line in f.readlines():
			lines.append(line)
	return lines[random.randint(0, len(lines) - 1)]

def generate_tree(size: int = 5, range_nodes: int = 5):
	if(size == 0):
		return	Bundle([], random_data())
	neigbours = []
	for i in range(random.randint(0,range_nodes)):
		neigbours.append(generate_tree(size - 1, range_nodes))
	head = Bundle(neigbours, random_data())

	return head

def print_tree(tree, size = 0):
	offset = "" if size == 0 else "\t" * size
	print()
	for st in str(tree).splitlines():
		print(offset + st)
	for i in tree.neighbours:
		print_tree(i, size+1)

sticks = []

tree =generate_tree(2, 4)
print_tree(tree)

b = Bundle(tree, "any")
b.stick = 1
b.stick_type = "stick"
b.share(b.neighbours[0])
#b.handoff(b.neighbours[0], b.key)
tree.transform()
print_tree(b, 0)


tree.transform()
print_tree(tree, 0)
