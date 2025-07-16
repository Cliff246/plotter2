
from random import randint
from enum import Enum
from commons import MAX_ID

class StickType(Enum):

	NO_STICK = 0
	REAL_STICK = 1
	VIRTUAL_STICK = 2
	FAKE_STICK = 3



class Stick:

	def __init__(self, stick: int = -1):

		self.id: int = randint(0, MAX_ID)
		self.perms: str = ""
		self.stype: StickType = StickType.NO_STICK
		#the cannonical 'key' this Stick class has
		self.stick: int = stick


	def handoff(self):

		pass

	def share(self):
		pass

	def get_perms(self) -> str:
		return self.perms

	def can_write(self) -> bool:
		#write = w like flags in a stick
		if("w" in self.perms):
			return True
		return False

	def __str__(self) -> str:

		string: str = "ID: %d | PERMS: %s | STYPE: %s" % (self.id, self.perms, self.stype.name )
		return string