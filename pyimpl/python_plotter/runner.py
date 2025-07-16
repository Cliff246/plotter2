import logging as log
from multiprocessing import Process, Queue
from p2datter import Datter, DatterCall
from childproc import childproc_startup, Instruction, InstructionType
from time import sleep

class Child:
	def __init__(self, worker_number):
		self.worker_number = worker_number
		self.task_queue = Queue()
		self.proc = Process(target=childproc_startup, args=({}, worker_number, self.task_queue))

	def start_up(self):
		self.proc.start()

	def give_task(self, task):
		self.task_queue.put(Instruction(InstructionType.COMMAND,task))

	def shut_down(self):
		self.task_queue.put(Instruction(InstructionType.SHUTDOWN, ""))

class Runner:

	def __init__(self):

		self.datter = Datter()

		self.children = [Child(x) for x in range(4)]

	def start(self):
		for ch in self.children:
			ch.start_up()

	def shut_down(self):
		for ch in self.children:
			ch.shut_down()








def start():
	"""
	start up function for plotter2 python
	"""
	print("is python version do not use as final product")
	run = Runner()
	run.start()
	sleep(1)
	run.shut_down()
	sleep(1)
	print("done")


