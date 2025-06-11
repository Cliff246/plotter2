import plotter2

import datetime
test = {
	"name": {
		"first" :"john", 
		"last" : "adams",
	},
	"dob" : {
		datetime.datetime.now()
	},

}

def main():
	sm = plotter2.SceneMap(test) 
	sm.print_map()

if __name__ == "__main__":
	main()
