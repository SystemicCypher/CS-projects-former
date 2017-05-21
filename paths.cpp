//Paths.cpp 
//shortest path implementation
#include <climits> // provides ULONG_MAX, maximum size_t
#include <list>
#include <vector>
#include <set>
#include "wtdgraph.h"
#include "paths.h"
using main_savitch_15::wtdgraph;
using std::size_t;
using std::vector;
using std::list;
using std::string;
using std::set;



void shortest(wtdgraph<string> &g, size_t start, vector<size_t> &distances, vector<list<size_t> > &paths){
	distances[start] = 0;
	//size_t v, allowed_size, sum;
	//vector<size_t> allowed_vertices;
	set<size_t> neighbor;
	for(size_t i = 0; i < g.size(); i++){
		if (start == i) continue;
		distances[i] = INF;
	}
	neighbor = g.neighbors(start);
	for(set<size_t>::iterator it = neighbor.begin(); it!=neighbor.end(); ++it){
		distances[(*it)] = g.edge_weight(start,(*it));
		paths[0].push_back(*it);
	}



	for(size_t i = 0; i < g.size(); i++){
		if (start == i) continue;
		neighbor = g.neighbors(i);
		for(set<size_t>::iterator it = neighbor.begin(); it!=neighbor.end(); ++it){
			paths[i].push_back(*it);

		}
	}


}