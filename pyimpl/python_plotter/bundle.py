from frame import Frame
from tasks import Task
from link import Link


class Bundle:

	def __init__(self):


		#frames stored by this bundle
		self.frame: list[Frame] = [Frame()]
		self.tasks: dict[str, Task] = dict()

		self.links: list[Link] = []
