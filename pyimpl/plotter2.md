

let's work towards an understanding of the system design

in general plotter2 should sit in between data and experiments acting as a bridge and coordnater all in one

				plotting and analysis
					^
					|
datasources ->	[plotter2]  -> long term storage
					/\
				   /  \
				  /	   \
				 /		\
				<		 >
			[commands]	[reruns and experimental versioning]


data should be understood as a collection of arbitrary data


it's a filesystem in simplest terms


something like

source_1245132 ---> output_data/[contains data base csv's, json's, anything really. could be gb's to terabytes of data in a tree]
			   \--> manifest.json
				\-> source_data/[contains the source code and generation system, not the actual data necessarily, it's to ensure how data is gotten is not lost, more simple then git]
				 \> tbd/[idk more space]


plotter2 is a server. it's always on, always watching. the way plotter works is it's the gate way in. while data may be stored on a filesystem like drive.
 you don't insert shit your self, you ask plotter2 to do that.

how plotter2 may look at a dirve is like this:


we will have 7 directories that plotter2 manages.

1st: source directory(where data is stored)
2nd: temp directory(staging ground and buffer(could be in /tmp))
3rd: config directory(configurations and extentions)
4th: service directory(external app's and experiments reloaded(could also be in /tmp))
5th: registry directory(registry of everything)
6th: output directory(where shit is retreived from)
7th: log/daemon moniter directory(the watchdog of plotter2 run by cron or systemd)


plotter2 will run on a multiple input type system.


	firstly:
		it will recieve bundles, data information. this can be from it's self, or from a user.
		(by it's self means plotter2 starts an experiment in the service directory, the service outputs a bundle, plotter2 pushes the bundle into staging)

		this will be done using a watched file directory, as in, plotter2 watches some directory for a package and then loads it into this

	secondly:
		command and api system(plotter2 will not be something you demand from. you ask it and it will do it for you.
		you don't just say:

			>kill proccess 4

		there will likely be a cli interface but as a service baked ontop of plotter2 for maintaince.

		rather plotter2 will recieve requests from an api, these will be well formated and targeted. these will not be 'lost' but persistant and logged. you ask it to do something, plotter2 rememebers

		for example let's say i ask plotter2 in layman's terms(cause I currently lack a design doc for the api):

			plotter2 please redo experiment2 with a lr=0.1, 0.2, 0.15, 0.05 and 0.01.

		plotter2 has been given a tight scope assuming experiment2 is well defined and consistent. that's to say it's a leaf in the source tree.


	thirdly:
		automatic input generation will be saught out. that's to say AI enabled work flow's will be built into plotter2 if it comes to that. ai will help schedule out and create precise instructions for plotter2 from user requests or from a chain of successes.

		as in the ai may be asked.
			"generate a plot of the output's where data that's clustered is circled and labled and non clusted data is removed"

		in the context of an experiment, the ai will determine the scope, what to draw, how to draw and if it can be accomplished.

		it's not supposed to 'find the meaning of life' but give it a scope that's strong it can help manufacture this easier.

		of course plotter2 owns the ai. that's to say, plotter2 has final juristiction and it can just say no. think of the ai as an 'auto user'

	finaly:
		plotter2 will work with all three systems from the same vantage point. there are two things you can do. give plotter information. or ask for something to be done. both can be bundled together but in general, thing's are non mutable. as in do something, You don't delete it, you move on past it or archive it.




Workflow kinda:

plotter2 logs, stores and begins to cycle up a experiment, that's to say, plotter2 already knows what it's expecting.
if plotter2 has been told for experiment2 batches to log the mean reward over time or generate a report for the entire experiment2.
then plotter2 will begin this proccess automatically. if plotter2 has been told to generate a meta meta report of experiment2 it also will.
what that means is let's say I ran experiment2 before, it's stored, charted and effectively 'done'. but I told plotter2 to compare experiment2 with it's future results before.
plotter2 when given a new instruction will reread the old data and generate a new report.

	plotter2 source management may looks something like this

		experiment2----> code_sources/[the actual experiment code]
				   \---> bundles-> bundle_1/ [old data experiment]
				   	            \> bundle_2/ [new data experiment]
					\--> meta-> history/ [history of experiment2]
							 \> reports -> report1/ [idk the exact 	name but it should look like a stored state
							 		    \> report2/ [same thing step 2]
					 \-> shared--> bundles/ [shared bundle compute steps, like a pca's or computed data]
							   \-> tasks/ [any individual step analysis]
							   	\> tbd/ [any thing else?]
					  \> package.(IDK maybe json) [package for the system]

	plotter2 manages lot's of stages:

		it could store like

		sources--> tali_experiments-> experiment1/
								   \> experiment2/
			   \-> llm_tests/test1 [just a fun test on a llm's]
			   	\> test1/ [actual just straight up registry]

	in fact plotter2 should be designed with many different child nodes that implement parent behaviour like:

	'experiment2a' may implement from 'experiment2'
	'experiment2a_revision2' implements from 'experiment2a'

	the tasks from experiment2 may be linked down to experiment2a then to experiment2a_revision2 and the first revision.

	that's not to say experiment2a_revision2 DEPENDS on experiment2, rather it inherits the user's configurations if they are linked.


what are bundles?

	bundles are just data... they are essentually linked with a source.
	what that source is? idk exactly yet

	but they are 'owned' by something and any action/task ontop of them produces a similar source tree to this:

		experiment2----> code_sources/[the actual experiment code]
				   \---> bundles-> bundle_1/ [old data experiment]
				   	            \> bundle_2/ [new data experiment]
					\--> meta-> history/ [history of experiment2]
							 \> reports -> report1/ [idk the exact 	name but it should look like a stored state
							 		    \> report2/ [same thing step 2]
					 \-> shared--> bundles/ [shared bundle compute steps, like a pca's or computed data]
							   \-> tasks/ [any individual step analysis]
							   	\> tbd/ [any thing else?]
					  \> package.(IDK maybe json) [package for the system]

	what's unique is bundles are self encapsulating.
	as in a bundle can define a bundle. this sub bundle shares the parent's trait's and so does anything else beneath it.



	experiment2/
		experiment2a/
			experiment2a_revision1/
			experiment2a_revision2/
				experiment2a_revision3/
		experiment2b/
			experiment2b_v2.

	you may say "ugh... okay? that's confusing experiments source and data as the same thing"

	YES and no. to simply put it, experiments aren't a 'thing' they are a set of subthings like this:

		x = {A, B, C, D}

		but A = {r1, {r2, r3}}
		and B = {2b, v2}

		but it's not just a set. it's a tuple

		so x = { { A, {r1, {r2, r3}}}, {B, {2b, v2}, C, D}

		as in they are self included.
		anything beneth you includes your self so that means...

	So if I ask at x to render a pca of lr=0.1 for all of them. they are each expected to implement a way to get that or be superset'd by x it's self.

	if I never ask X to do anything... that mean's X is blank, it simply exists as a encapsulating bundle. only there to sort information.

	We do this through linking. essentually we say A, B, C, D must link to x. if they can link they are defined. if not, they are not really a member of x. they are a memeber of the set's of 'imposter' children. now, that's not a universal feature. A may link some features of X, B may link some other features.
	the intersection between A's and B's links are a valid task defintion.
	if you want. you can 'unlink' manually, or force link(bad idea) but the idea is that they are there.

	the union of A's and B's link's are essentually the valid operations of A and B.

	ANOTHER HUGE NOTE!
		X is linked to it's self. that's to say. the parent is expected to link it's self fully. X must incorperate X. cause ugh... that makes no sense if it doesnt.

		we can think of bundle as containing it's self and it's children. or both.

		it's not like we say:

		[bundle1]
		   /\
		  /  \
		 /	  \
		/	   \
[bundle1 data] [children]
				/		\
			   /		 \
			[bundle2]	[bundle3]
			/					\
			[bundle2 data] 		[bundle3 data]

		we say:
			bundles include their data as an element. that's expected

		[bundle1]
		[data]
		[children]
		|	   \
		|		\
		\ 		 [bundle3]
		 \		 [data]
		  \		 [no children]
		   \
	  	    \
		[bundle2]
		[data]
		[no children]



Now what is a manifest?

	Like in the past ocean faring day's manifests's represent information on cargo. they are transit information for data! you don't really wan't to be using the API for long data stream's. It can be used but it's really for small snipet's and extentions.

	Manifests serve as a transport's book keeping. they define what something is, what it's doing.

	but plotter2 get's to decide what something is actually.
	not in the 'well actually🤓' but in the 'ehhh, experiment15_revision4 barely links with experiment15_revision3 so they probablly aren't children. it will listen to you,

	manifests are complicated but will include version codes, users, date & time, dependencies and what the transport contains. links, tasks, everything else is optional and included in submanifests.
	manifests can contain just new configurations, updates, and new data Or could be a whole new work flow



	back to manifests. they are temporary and just define updates, they presupose something new to plotter2

	but plotter2's state is king, and a manifest can represcribe conditions.

	let's be clear. manifests only describe. setting and everything else is a task, which manifests can describe. Why are they important... cause they describe projects in such a way that is clear.

	that's also to say... manifests exist within their scope only. a manifest does not update old information just installs new information. a manifest also does not gurantee anything. if a manifest says experiment1 links to experiment2. if you update experiment1 with new information. the manifest is no longer valid for experiment1. it's actually not even used. it only describes what it contains.


	let's also seperate this. manifests describe packages and tasks. they can do any combination of this. to say it can describe both, none, tasks or packages only. packages define links.


	manifests will look like this minimally

	{
		date: str
		time: int
		user: str
		manifest_version: int
		meta: obj
		contains: obj

	}


LINKS:


	links are one way connections to another bundle. they define a strict scope and are supposed to be reusable.

	for example:
		let's say a experimentA defines:

			def get_weight_data(self, step):
				return weight[step]

		experimentB is expected to work identically as in it does the same thing.

		so:
			def get_weight_data(self, step):
				return weight2[step]

		would be valid.

	Links can be translated:

		A -> B is a simple link
		A -> ε -> B is a translated link.
		where ε converts A's information to B.

	links must contain a in and out head.

	A link is not a call. the input caller is not static and can be plotter2 it's self, a user config, anything. you are writing a function to do something. but not... you don't have to define it. plotter2 can find it.

	let's say a function is:

		def forward(input):
			return fn((w @ input) + b)

	this may be an internal function in a program, what that means is it's not actually given to plotter2. plotter2 finds it or is told to find it.

	also let's be super clear, in the function def forward(input). the paramater input is not A. the function "forward(input)" is also not A.
	A is given by a configuration of plotter2. B is given by a configuration of plotter2.

	A->B may look like.

	link A->B:
		A:
			forward1(input)
			parms:
				vector
			returns:
				vector
		B:
			forward2(input)
			params:
				vector
			returns:
				vector

	where forward1 and forward2 are defined by packages

	a link does not need to proccess anything. a link can just alias data.

	in the sense A -> B = weights.csv

		if A expect

	additonally neither given room to overwrite anything if it executes.

	links may be mutable or constant. that's to say, a link can expect mutable data as in data that varies in size, shape or paramaters. still the same type of data. just bigger or smaller. constant means if it's expecting a R^3 float. it's getting a R^3 float. not a R^3 int, not a R^4 float. it's exactly the same. that's done through ε it converts to what defined.

	a tranlation looks like:


	A->B:

		A:
			forward(in)
			params:
				vector
			returns:
				vector
		Epsilon:
			f(x)
			params:
				matrix
			returns:
				vector
		B:
			load(path)
			parmas:
				matrix.csv
			returns
				matrix

	the way it works is like this, data at it's end must fit a certain shape. but how it get's to that shape can be translated.


	now back to our higher up understanding
	if two bundles link. what does that mean?

	it means a bundle link's up some condition or subset of what the bundle does, that can be the whole bundle or some part of it. all we know, is that it's consistent

	bundle 1 implements X
	bundle 2 implements Y

	if 1[X] links to 2[Y]. then anything X does, Y does

	B is what the bundle expects A


DATA SYSTEM...



plotter 2 runs under this execution model

Watchdog's are unmanaged by plotter2. they are expected to work with systemd, cron, task scheduler and launchd. but systemd initally.

Execution model:


		watchdog main 		   		 stager					watchdog 3
		[saftey]	  			[save state slave] <--->[saftey for this guy]
	   	     \	  		 	        /
			  \	 	  		   	   /
			   \	   		  	  /
				\	   		 	 /
				 \  		network
			      \   	   	   /
				   \ 	 	  /
			 	 	\ 		 /
	   				 \   	/
outside link <--> 	main exe <----> children * N
					[parent] 	[each run a python interpreter]
	  				  /;\   \
					   |	 \
					   |  	  \
					   |	   \
	   				   |		\
					   |		 \
					   |		  \
					  \;/		   \
					servicer	    \
				[service handler]<-> Watchdog2
					  /;\			[saftey again for outer proccesses]
					   |			/
					  \;/		   /
					service's	  /
				[service executables]


main exe:
	managed by: watchdog 1
	machine: main
	description: primary plotter2 interface, it run's the code, sanatizes and schedules children. it's the primary decider on what data does.

children:
	managed by: watchdog 1, main exe(kinda)
	machine: main/shared
	description: essentually a python interperter due to GIL, acts as the primary data pusher and cruncher.
	Also performs ploting, rendering and all parallel data, can be instantiated and copied many times.
	Does not do IO normally(initally).
	these guys potentially are going to be alway's held in form of stasis when unused but that's tbd.

Servicer:
	managed by: watchdog 1(kinda), main exe(kinda), watchdog 2
	machine: main
	description: acts as a inbetween of plotter2 and it's services(ie experiments)
	this program ensures services are running and managing io between them and main exe.
	can do async writing and also get's access to the sourcess. It's coupled tightly with watchdog 2.
	it's not exactly needed as a unique system but prevent's services from dying due to plotter2 reboots or any error.


(DIFFERENT then servicer)
Service:
	managed by: watchdog 2, servicer(kinda), os
	machine: shared
	description: a service, a program designed to run under it's own load. essentually an experiment or data source. this program just run's does it's thing. It has no need to do anything special, think of it like job.

Stager:
	managed by: watchdog 3
	machine: buffer machine
	description: a buffer, this thing essentually ensures data thats coming in is not killed by a power outage.
	this guy operates alone, potentailly coupled with watchdog 3 it's self. to say it simply.
	when sending to plotter, you send to this guy, which sends to plotter2's main machine. Intrestingly enough also handles services.
	as in it just ensures they are relocated when the main machine reboots.


watchdog 1
	managed by: os
	machine: main
	description: ensures plotter2 is cooperating and functional, every so often cleans and restarts plotter2 to ensure no memory leaks.
	also manages children and servicer.
	act's as god themselves, full authority to kill and restart everthing including watchdog 2, and everything except watchdog 3.

watchdog 2:
	managed by: os, watchdog1
	machine: main
	description: ensures all connections between services are cooperating, communicates with external or internal os to drop and kill services.

watchdog 3:
	managed by: os
	machine: buffer machine
	description: a buffer stager designed to hold data before plotter2 sees it. additonally act's as a offsite relay. watchdog 3 is unique, it's designed to act as a offsite back up.
	it ensures data is NEVER lost. watchdog 3, listens to watchdog 1


DATAFLOW

	plotter2 runs using a mix between python and cpp and a form of mix, with watchdog's likely bash or python.

	most core logic and code is done in cpp such as managing procceses, file streams, data parsing and networking. almost all logic that's base code is cpp

	with python being a scripting language for running experiment workflow's

	WITH one huge caveat, python in plotter2 is more extended then the original, with built in's.

	things with math are
		mean()
		median()
		mode()
		stddev()

		product()
		l2norm()
		l1norm()



		cosine_simularity()
		sine()
		cos()
		tan()
		all the trig functions

		pca()
		kmean()



		derivative() ; derivate of
		integral() ; integrates


	but also things like

		me; current context

		datter ;datter class (how bundles and data are handled as well as the analyist system of plotter)

		loggy() ;logging system(essentually print just more exposed)

		pipe  ;pipeline functions and class

		giveup() ;give up means quit safely,

		order() ; order, like sort but essentually the back bone of all the automatic meta generation data

		frame() ; frame produces a frame. can frame a frame

		plotme() ;just fucking sends the plot(does everything based on context)
		animateme() ;just fucking sends the animation

		visualtype() ; defines what it is

		label() ;label data

		colour()/color() ; color data

		axis() ; define axis's(how many there are how big)

		legend() ; define legend
		graident() ; a graident
		point() ; a point
		shape() ;draw shape
		line() ; draw line
		circle() ; draw's circle
		;;;blah blah blah lot's of shapes



		text() ; text
		font() ; font
		;text info
		table() ; table shit
		expr() ; math expression
		fit() ; fit something


		boxer() ; box data


		scale() ; scales
		plot() ;queues a plot using a frame
		simulate() ; queues a simulated object up(for visualizer)
		animate() ; queues a animation

		report(); queues a report queue a report with a frame(lot's of plots)



		register() ; registers data as your own
		deregister() ; deregister's your data
		handoff(); give away data(takes away your ownership)
		handin() ;give data to someone else(also takes your ownership but rather than releasing, you transfer with a key)

		access() ; how you get your data(with or without key)
		share() ; shares data away(ugh... scary as well, essentually gives someone else your data while still asserting it's yours)(basis of handin, handout)


		task() ; start's a task
		release() ; give back execution too who owned it for a bit

		collect() ; wait for all sub tasks to be done
		gather_tasks() ; gather from a type of task


		islinked() ; returns if a key is linked and the key's
		link() ; link a to b

		copy() ; is like access but rather than taking a link and owning it. it copies the data from it. you still have to handoff the scoped access. but you do own the copied data


		automatic() ; just default everything

		page() ; page a response
		repeat() ; repeats something (special i will explain)

		load() ; imports data from a bundle(very expcit should use access)(basis of access)
		export() ; pushes data to a bundle(very expcit should use handoff)(basis of share)

		impose() ; force something(assert essentually but plotter2 prelistens like a preproccesed instruction)
		expose() ; share to plotter2( how you share what you do. also like a preproccesed instruction)


		exposed() ; get's everything exposed to you
		imposed() ; get's everything imposed to you


plotter2 work flow involves 8 major systems


	Main proccess threads

	|1	[Runtime(the main loop)		   		]
	|2	[Orchestratior (manages children)	]
	|3	[Datter	(analysist system)	   		]
	|4	[IO system(async io for children)	]
	|5 	[Organizer(manages memory map)		]


	Children

	|1	[Runtime(messenger, optimizer)		]
	|2,1[Python interperter
	|2,2[Pipeliner and actor (datter)		]


the main proccess runs under a individual component system. each component is designed to carry out it's task indivdually without growth or thread creep

Children are designed to follow a more event based system. while there are two threads for each child.
the threading model is designed to 'switch' the use case of thread's for the task.

plotter is not just a bunch of IO race conditions in a box, the system runs as a memory mapped system, where data is shared between each of the children.
children don't interface with files, they interface with the main executable loading the data as it need's.
the children may in the future be given task scopes for IO. but initally they are to be essentually shared memory.

that's not to say children edit shared memory each over writing themselves. rather they share read head's but each communicate to plotter2 write wise themselves.


plotter 2 is designed for two forms of data manipulation.

	scripts and pipelines.

	Scripts:
		scripts are defined as python files that are run in the child. scripts are parallel in nature.
		a script should not solve 1000 plots of the same type at once. rather they should solve a small subset of the problem.
		they are instanced 1000 times by the children to complete tasks. optimized of course but they complete a small task.

		in this way scripts are different then pipelines by one key factor. they can contain runtime dependencies and conditonal's.

		scripts can gate input's for example wheras pipelines struggle with this.

		scripts are designed to be light weight and simple but since they are python they can be very complex

	Pipelines:

		pipelines are plotter2 native features, they implement datter(the backbone of plotter2). d
		atter essentually is the main data format and tranformation engine.

		Pipelines are just sequences of instructions built up and run a bunch

		something like:
			[access, label, pca, scale, frame, colour, axis, legend, plot, handoff]

		what this does is load data, label it implicitly, pca the data, scale the data.
		then it creates a frame. colours the data, places the axis, then the legend. finally it 'plots' it which queues the data up, and hands it off. letting datter reaccess it.




plotter2 and datter

	datter is the data analysis engine of plotter and data managment engine.
	when doing something in plotter, you are interfacing with datter.

	datter deal's with packages. these are loaded bundles of information scoped to exactly what you want by the linking system.

	datter acts as a shared pool of information.

	for example datter can deal with all stages of information, from the starting data like raw numbers.
	to meta information like clusters for every experiment. datter is the exposed core of the system

	datter works under two assumptions. you have data you want computed and you have alot of that data.

	datter essentually paralellizes all the common data flows into tasks based on dependency


	for a pipeline dependence is trivial.

		a to b to c to d

	for a script. datter needs to do more work computing what is required at what time

	a script for example can do this:

		let's say we have 10000 sets of matrix's. I want to find what each of them when combined combined have shared regions as well as plot each matrix. but I want each matrix plot to be side and side with the combined total over time.

		with a pipeline this is not possible exactly, you cannot just interface with every thing at the same time then restart. you depend on the combined shared regions existing already but you have not found that yet.


		with a script however I can do it.

		i would define it like this.

		matrix_plot.py

		#exposes that this gives a matrix
		expose(matrix)

		impose(matrix_step_key as datter.keytype(matrix))

		def task():

			data = access(matrix_step_key) #gathers the data from the matrix plot

			#exposes data on the parent's datter
			expose(matrix as data)

			#section for parent
			parents = islinked(me)
			if(parents != None)
				#for each parent
				for parent in parents:
					handin(data, parent)
					#gives back parent the data
					release()
					#parent must handin back to me
			if(data not in exposed()):
				giveup()

			extra_data = access(exposed())

			window = frame()

			main = frame(window)
			extra = frame(window)

			plotme(extra_data, extra)
			plotme(main, data)
			plotme(window)



		meta_sum_matrix.py

		def task()

			#gather the tasks of matrix_plot.py
			#why this works is because this script is assumed to run only when matrix_plot is defined.
			tasks = gather_tasks(matrix_plot.py)
			#links me to tasks
			link(me, tasks)

			#wait for tasks to release
			collect(tasks)
			#results
			result = []
			if("matrix" in exposed()):
				#get's every matrix as a copy
				result.appned(copy("matrix"))

			#give back every matrix(it's still in our scope)
			handin(access("matrix"), tasks)

			#gives back execution to child
			release()

			summed_matrix = sum(result)

			window = frame()
			plotme(window, summed_matrix)


	so to run this
	you would define a task

		task1:
			name: plot_matrix's
			task_src: matrix_plot.py

	this defines a task in the scope of the bundle

		task_meta:
			name: plot_meta_matrix
			task_src: meta_sum_matrix.py
			linked: task1

	this defines task_meta. so when task meta is run, task1 is run as well.

	but when task1 is run, it just outputs a boring plot


	so the way it works is if you start task_meta:

		task_meta runs. it links task1()
		a->b
		but A collects 'task1' this mean's it wait's until task1 is released.
		so task1 executes in scope.
		task1 conditonally works with links.
		so since we linked it, task1 exposes it's data and releases to each of it's links
		this mean's we are back at task_meta.
		we then check if 'matrix' is exposed to us.
		we recieve EVERY(YES EVERY SINGLE EXPOSED MATRIX) of task1.
		we then store a copy of it and hand off.
		then we release again. well... how does that work? well since task1 and task_meta are functionally independent past this we are allowed to continue each.
		so each task1 is finished and at the same time since the dependency is met.
		every task_meta is also finished