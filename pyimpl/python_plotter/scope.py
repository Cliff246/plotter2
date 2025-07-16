
from frame import Frame
from stick import Stick, StickType
import p2bundler 

class Scope:
	"""
	a scope in which a stick exists
	should effectively be the 'in movement' type
	"""

	def __init__(self, stick: Stick):

		#current stick
		self.stick: Stick = stick
		#current frame
		self.frame: Frame = Frame(stick.stick)
		#current bundle
		self.bundle: p2bundler.Bundler = None


	def has_bundle(self) -> bool:
		"""
		checks whether or not this scope has a bundle
		returns true on a bundle(not deeply checked) and false on if the bundle is unset
		"""
		if self.bundle == None or not isinstance(self.bundle, p2bundler.Bundler):
			return False
		return True

	def is_virtual(self) -> bool:
		"""
		checks if the frame is virtual
		returns True if yes and false if no
		"""
		if self.stick.stype == StickType.VIRTUAL_STICK or self.stick.stype == StickType.FAKE_STICK:
			return True
		return False

	def release_scope(self) -> bool:
		"""
		releases the scope from it's current bind
		returns true on success and false on failure
		not a delete just a move
		"""
		#TODO actually saftey check not this joke
		if self.has_bundle():
			#very brute forcey but it works
			self.bundle.relinquish_scope()
		self.bundle = None


		return True


