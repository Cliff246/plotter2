from scope import Scope
import p2bundler

class Task:
	"""
	parent class of all Task's
	is
	"""

	def __init__(self, local_bundle: "p2bundler.Bundler"):
		self.local_bundle: "p2bundler.Bundler" = local_bundle
		self.implements = []
		pass


	def run(self, scope: Scope):
		"""
		base runner of a task
		"""
		raise NotImplementedError()


	def get_token(self) -> tuple[int, str]:
		return (0, "default")

	def get_implements(self) -> list[str]:
		return []


class TaskConfig:
	"""
	default basic task that just 'does' something from a basic call
	"""

	def run(self, scope: Scope):
		"""
		base runner of a task
		"""
		raise NotImplementedError()


	def get_token(self) -> tuple[int, str]:
		return (0, "default")

	def get_implements(self) -> list[str]:
		return []





class TaskPipeline:
	"""
	A pipe line of linked calls
	"""
	def __init__(self):
		pass

	def run(self, scope: Scope):
		"""
		base runner of a task
		"""
		raise NotImplementedError()


	def get_token(self) -> tuple[int, str]:
		return (0, "default")

	def get_implements(self) -> list[str]:
		return []

class TaskScript:
	"""
	A python script for doing calls and the most complicated type of task
	"""
	def __init__(self):

		pass

	def run(self, scope: Scope):
		"""
		base runner of a task
		"""
		raise NotImplementedError()


	def get_token(self) -> tuple[int, str]:
		return (0, "default")

	def get_implements(self) -> list[str]:
		return []