from multiprocessing import Process, Queue
from enum import Enum

class InstructionType(Enum):
	LOG = 0
	COMMAND = 1
	SHUTDOWN = 2


class Instruction:


	def __init__(self, instruction_type: InstructionType, content ):


		self.itype: InstructionType = instruction_type
		self.content = content





def childproc_startup(info, worker_id, instructions):
	"""
	the function of the child proccess
	dumb yes...
	but simple and easy to do

	returns nothing
	"""
	class ChildProc:
		"""
		starts the child proccess of the plotter2 server
		"""
		def __init__(self, info: dict, worker_id: int, instructions: Queue ):


			self.info: dict = info
			self.worker_id: int = worker_id
			self.instructions: Queue = instructions

			#current active task
			self.current_active: Instruction = None



		def poll(self) -> bool:
			"""
			polls a instruction and looks for work
			"""
			if not self.instructions.empty():
				self.current_active = self.instructions.get()
				return True
			else:
				return False

		def proc(self):
			"""
			proccess things 
			"""
			if self.poll():
				self.instruction_process()
			else:
				pass

		def instruction_process(self):
			if self.current_active == None:
				return
			else:

				match(self.current_active.itype):
					case InstructionType.LOG:
						print("log")
					case InstructionType.SHUTDOWN:
						print("die")
						exit(0)
					case InstructionType.COMMAND:
						print("doing something")
					case _:
						print("could not read")


	proc: "ChildProc" = ChildProc(info, worker_id, instructions)
	print("startup child")
	try:

		running: bool = True
		while running:
			proc.proc()
			pass

	except:
		return 0

	return

