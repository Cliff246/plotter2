from scope import Scope
import p2bundler as p2



class Link:
	"""Basic graph traversal edge"""

	def __init__(self, task_key, task_end, transition_fn: callable = None):
		self.tast



class LinkCollection:

	def __init__(self, start, end, key):
		self.start: p2.Bundler = start
		self.end: p2.Bundler = end
		self.key: str = key

	#TODO
	def transfer_link(self, scope: Scope):
		"""
		transfers a scope to another scope through the link
		"""

		if self.start != scope.bundle:
			raise RuntimeError("cannot link a random bundle")

		if not scope.release_scope():
			raise RuntimeError("cannot release a scope that's active")

		if not self.end.set_scope(scope):
			raise RuntimeError("could not set scope to another bundle")
		return