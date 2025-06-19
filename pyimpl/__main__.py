import plotter2

import datetime
test1 = {
	"axis": {
		"axis1": {

			"type" : "linear",
			"name" : "x",
			"function" : {
				"independent" : "x",
				"dependent" : "y",
				"equation" : "y=x"
			},
			"style" : "basic",
			"range" : {
				"start" : -10,
				"stop" : 10,
				"terms" : 100
			}
		},
		"axis2" : {
			"type": "linear",
			"name" : "y",
			"function" : {
				"independent" : "x",
				"dependent" : "y",
				"equation" : "y=2x",
			},
			"style" : "basic",
			"range" : {
				"start" : -10,
				"stop" : 10,
				"terms" : 100
			}
		}
	},
	"shapes": [
			{
				"name" : "square",
				"text" : "legend\nred=linear,blue=exponential",
				"pos" : {
					"type" : "relative",
					"base" : {
						"vertical" : "upper",
						"horizontal" : "right,"	
					}
				}
			}
	],
	
	"data" : {
		"lines" : [
			{
				"name" : "linear",
				"path" : "linear1.csv",
	
			}
		]
	}
}

test2 = {
	"meta" : {
		"paths" : [
			"linear1.csv",
			"graph1.meta.json",
		]
	}
}


def main():
	#sm = plotter2.SceneMap(test1) 
	#sm.print_map()
	ms = plotter2.SceneMap(test2)
	ms.print_map()
if __name__ == "__main__":
	main()
