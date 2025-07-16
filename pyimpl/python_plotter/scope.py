
from frame import Frame
from stick import Stick

class Scope:


	def __init__(self, stick: Stick):


		self.stick: Stick = stick
		self.scope: Frame = Frame(stick.stick)

		pass