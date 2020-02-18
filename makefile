all: dijkstra bellmanford kruskal prim

dijkstra : ./Dijkstra/dijkstra.cpp
	g++ ./Dijkstra/dijkstra.cpp -o dijkstra 
	
bellmanford : ./BellmanFord/bellmanford.cpp
	g++ ./BellmanFord/bellmanford.cpp -o bellmanford 

kruskal : ./Kruskal/kruskal.cpp 
	g++ ./Kruskal/kruskal.cpp -o kruskal 
	
prim : ./Prim/prim.cpp
	g++ ./Prim/prim.cpp -o prim