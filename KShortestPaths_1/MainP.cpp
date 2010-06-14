/************************************************************************/
/* $Id$                                                                 */
/************************************************************************/

#include <limits>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "GraphElements.h"
#include "BasePath.h"
#include "BaseGraph.h"
//#include "TGraph.h"
#include "Graph.h"
#include "TPath.h"
#include "DijkstraShortestPathAlg.h"

using namespace std;

map<int, set<int> > tmp_map;

void test()
{
	set<int> tmp_set; 
	tmp_set.insert(1);
	tmp_set.insert(2);
	tmp_set.insert(3);

	tmp_map.insert(make_pair(1,tmp_set));	
}


set<int> getSet()
{
	set<int> tmp2;
	tmp2.insert(4);
	tmp2.insert(5);
	tmp_map.insert(make_pair(2, tmp2));
	return tmp2;
}

void testGraph()
{
	Graph my_graph("data/test_2");
	DijkstraShortestPathAlg shortest_path_alg(my_graph);
	BasePath* result = 
		shortest_path_alg.get_shortest_path(my_graph.get_vertex_by_ID(0), my_graph.get_vertex_by_ID(2));
	result->PrintOut(cout);
}

int main(...)
{
	cout << "Welcome to the real world!" << endl;
// 	test();
// 	for (map<int, set<int> >::iterator iter = tmp_map.begin(); iter !=
// 		tmp_map.end(); iter++)
// 	{
// 		cout << (*iter).second.size() << endl;
// 	}
// 	cout << getSet().size() << endl;

	testGraph();
}