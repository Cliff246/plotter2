
def recursive_print_map(layer: dict, depth: int = 0):	
	offset = "" if depth == 0 else "   " * depth	
	if isinstance(layer, dict):	
		for key, value in layer.items():
			print(offset + key + ":")
			recursive_print_map(value, depth + 1)
	elif isinstance(layer, list):
		print(offset + "[")
		for value in layer:
			recursive_print_map(value, depth + 1)
		print(offset + "]")
	else:
		print(offset + str(layer)) 


class SceneMap:

	def __init__(self, startup: dict):

		self.scene_map: dict = dict(startup)
	

		
	def print_map(self):
		recursive_print_map(self.scene_map)
