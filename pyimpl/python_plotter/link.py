

class Link:
	"""Basic graph traversal edge"""

	def __init__(self, start, end, key):
		self.start = start
		self.end = end
		self.key: str = key

	#TODO
	def transfer_link(self, scope):
		"""
		transfers a scope to another scope through the link
		"""
		pass