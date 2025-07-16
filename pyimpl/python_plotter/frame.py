from random import randint
from commons import MAX_ID
from stick import Stick, StickType

from copy import deepcopy

class Frame:
	"""The content of datter in a scope frame"""

	def __init__(self, key: int = -1, owner: int = -1, content: dict[str] = {}):
		self.content: dict[str] = content
		self.key: int = key
		#THIS IS TODO
		self.owner: int = owner
		#log of int to int. ie -> stick id to stick id.
		#or simply the lock to the locl
		self.log: list[tuple[int, int]] = []


	def validate_key(self, test_key: Stick) -> bool:
		"""
		tests whether a stick contains the lock key
		returns true on success and false on failure
		"""
		if self.key == test_key.stick or self.key < 0:
			return True
		return False

	def try_set_key(self, key: Stick, newkey: int) -> bool:
		"""
		Should be stick to int or the stick to the int of another sticks INTEGER KEY
		weird I know but it's decent since I don't think I want that to be done that way

		does not let you set a Valid to invalid... that's not allowed cause you could lose a access key that way

		key: Stick(needed and to test)
		newkey: int(essentually Stick.stick but can be else)


		returns: true on a set and false on a fail
		"""
		if self.validate_key(key):

			if self.newkey < 0 and self.key >= 0:
				return False
				#don't let me set to empty that's really weird unless already empty?
			self.log.append((self.key, newkey))
			self.key = newkey

			return True
		return False

	def write(self, stick: Stick, content_key: str = "", content_value = None) -> bool:
		"""
		write data to this frame if the key is valid... you should copy first then write if it's not valid
		stick: Stick(needed for writing)
		content_key: str(optional but recomended to use for data)
		content_value: anything but defaults to nothing
		"""

		if stick.can_write() and self.validate_key(stick):
			#can over write information
			isin: bool = True if content_key in self.content else False

			self.content[content_key] = content_value
			return isin
		else:
			raise RuntimeError("cannot write to a frame that's not owned")


	def read(self,stick: Stick = None, content_key: str = ""):
		"""
		give's you a ref copy if the stick is valid
		gives you a deep copy if you have permisions... could be bad if you forget.
		stick: Stick(optional)
		content_key: str(optional but use)
		returns: none if not in the content
		"""
		if isinstance(stick, Stick):
			if stick.can_write() and self.validate_key(stick):
				#shallow ref return
				#allows failure cause it's not important and we should allow reading
				return self.content[content_key]
		if content_key in self.content:
			#return content
			return deepcopy(self.content[content_key])
		#nothing to return
		return

	def copy(self)-> "Frame":

		copy_data: dict[str] = deepcopy(self.content)

		newframe = Frame(content=copy_data)
		return newframe

	#TODO
	def serialize(self) -> bytes:
		"""
		serialzie into bytes.
		this should be compatable with the c++ version

		returns a list of bytes
		"""
		raise NotImplementedError()

		pass

#TODO
def deserialize(info: bytes) -> Frame:
	"""
	deserialzie into frame.
	this should be compatable with the c++ version
	"""
	raise NotImplementedError()

	frame = Frame()

	return frame