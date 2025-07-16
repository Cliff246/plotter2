

class Task:

	def __init__(self):
		pass


	def run(self):
		raise NotImplementedError()



class TaskConfig:
	"""
	default basic task that just 'does' something from a basic call
	"""

	def __init__(self):
		pass

	def run(self):
		pass






class TaskPipeline:
	"""
	A pipe line of linked calls 
	"""
	def __init__(self):
		pass

class TaskScript:
	"""
	A python script for doing calls and the most complicated type of task
	"""
	def __init__(self):

		pass