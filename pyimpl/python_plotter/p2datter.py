import os


from frame import Frame
from p2bundler import Bundler


class DatterCall:
	"""
	A call on datter to do something to a frame on a subject layer
	"""

	NOTHING = 0
	HANDIN = 1

	#TODO a call on datter to do something
	def __init__(self):
		self.call_id = 0
		pass

	def __call__(self, *args, **kwds):
		call_name, call_type, call_args = args



class Datter:
	"""
	Main holder of resources and god themselves

	stores a list of frames and dictonary of bundles
	"""
	def __init__(self):

		self.frames: list[Frame] = []

		self.bundles: list[Bundler] = []

		self.scopes = []

		self.calls = []


		pass



	def init_calls(self):
		pass

	def find_bundles(self, fp: str):

		directory: list[str] = os.listdir(fp)

		for item in directory:
			if item.endswith(".bnd"):
				bnd = Bundler()
				bnd.pull_content(item)
				self.bundles.append(bnd)
			#keep going down
			#unsafe if we have a link but whatever PAH
			if os.path.isdir(item):
				self.find_bundles(item)



	#cycle something.
	def cycle(self):

		pass


