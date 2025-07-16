from frame import Frame
from bundle import Bundle


class DatterCall:
	"""
	A call on datter to do something to a frame on a subject layer
	"""

	def __init__(self):
		pass

class Datter:
	"""
	Main holder of resources and god themselves

	stores a list of frames and dictonary of bundles 
	"""
	def __init__(self):

		self.frames: list[Frame] = []

		self.bundles: dict[int, Bundle] = dict()



		pass


	#cycle something.
	def cycle(self):

		pass

