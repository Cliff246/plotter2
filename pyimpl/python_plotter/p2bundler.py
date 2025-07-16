from frame import Frame
from tasks import Task
from link import Link
from tasksignal import TaskSignal
from scope import Scope

class Bundler:
	def __init__(self):


		#frames stored by this bundle
		self.frames: list[Frame] = [Frame()]
		#tasks held by class
		self.tasks: dict[str, Task] = dict()

		self.links: list[Link] = []
		self.scope: Scope = None


		#signals sent to this
		self.signals: list[TaskSignal] = []

	def holds_scope(self) -> bool:
		"""
		Quick helper to determine if a bundle is holding a stick
		"""
		if self.scope == None or not isinstance(self.scope, Scope):
			return False
		return True

	def set_scope(self, scope: Scope ) -> None:
		"""
		this returns none but tries to safely set a scope to the current bundle
		if the bundle or scope if not ready then it will error out.
		scope: Scope(valid scope)
		"""
		if self.holds_scope():
			raise RuntimeError("A bundle cannot hold a scope when it already has one")
		if scope.has_bundle():
			raise RuntimeError("cannot set to a scope that's already set")
		#sets the scope as current
		self.scope = scope
		#sets the scope's bundle to this
		scope.bundle = self
		return

	def relinquish_scope(self) -> None:
		"""
		just gives up a scope... does nothing besides that.
		don't do it if it's not ready but datter should track all scopes anyways
		"""
		self.scope = None
		return

	def run_task(self, key: str):
		"""
		runs a task in the given scope
		key: str(key of task will not run if not valid)
		returns nothing all results will be poluted in scope
		"""

		if not self.holds_scope():
			raise ValueError("no scope held")
		if key in self.tasks:
			self.tasks[key].run(self.scope)
		return


	def pull_content(self, path):
		"""
		pulls content from a bundle file
		"""
		self.path = path

