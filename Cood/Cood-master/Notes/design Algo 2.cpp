*/Graphs
->Movie network => nodes=actor, edge is between co-star
	bacon number = min no of hops/edges req to reach kevin bacon.
'AI'
	-> graphs connecting 'states' through 'functions' !
'Sudoku graph ! Directed graph.'
		-> Node is the state pf a partially completed puzzle
		-> Edge = Connects two states differing by one move.

'Connectivity in a network',' Pieces of a graph- clusters'

*/ Generic Graph Search ->find everything findable & dont explore any node twice for O(m+n) time
v explored <=> has a path from s to v
brute= set a bool 'visited' to the nodes
BFS - can compute SHORTEST PATH
	=uses  a LIFE = Queue
	- explores in layers
	- like the 'mindly' map
	- Runs in linear time = Ns (nodes reachable from s) +Ms(edges reachable from s) 
	- can store the layer number of the points 'SINCE' every unexplored node from w must be in the next layer, at dist dist(w)+1
		 shortest path => move one layer at each step.
		 clusters = explored from a s (put this in a loop that runs BFS on unexplored ones to find all clusters)

	- 

DFS - can't be useful for shortest paths
	- but very useful in directed Graphs => topological ordering (ancestors & descendants)


	- explores aggressively like in a maze , backtrack only when necc.
	- like an active, curious kid which moves to whatever is unexplored
	- uses a FIFO = stack
	- explores in wells
	
	directed Graphs => topological ordering (ancestors & descendants)
	if it has a cycle, the graph will not have topological order.
			-> KIM that every ACYCLIC directed graph his a 'Sink' vertex( the one with no outgoing edges).
			-> this Sink vertex must be the end of the topological order
			->but cyclic one can also have a sink vertex
	M-I) = set number of Sink vertex = n, recurse on G - {v} (remove all edges related to it.)
	M-II) = use DFS: => set f(u) = current_label--; when backtracking (write it below the recursion call to DFS_Visit)

*/ Strongly connected in Directed graphs-
able to go from any pt to any other pt
=> Kosaraju's Two-pass algo-
	First pass= Run DFS_loop on G with reveresed edges (the Transpose).
	Second pass= Run DFS_loop on G, but in decreasing order of finishing times in First pass.

	book keeping is 	
		1st pass : t= # of nodes processed so far, & LEADER(I) = parent(i)
		2nd pass : s= current source vertex 


