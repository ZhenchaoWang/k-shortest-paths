/************************************************************************/
/* $Id$                                                                 */
/************************************************************************/
#include <set>
#include <map>
#include <queue>
#include <vector>

#include "GraphElements.h"
#include "TGraph.h"
#include "Graph.h"
#include "DijkstraShortestPathAlg.h"

using namespace std;

DijkstraShortestPathAlg::~DijkstraShortestPathAlg(void)
{
}

void DijkstraShortestPathAlg::clear()
{
	m_stDeterminedVertices.clear();
	m_mpPredecessorVertex.clear();
	m_mpStartDistanceIndex.clear();
	while (!m_quCandidateVertices.empty())
	{
		m_quCandidateVertices.pop();
	}
}

void DijkstraShortestPathAlg::determine_shortest_paths(GIntVertex& source, GIntVertex& sink, bool is_source2sink )
{
	//1. clear the intermediate variables
	clear();

	//2. initiate the local variables
	GIntVertex* start_vertex = is_source2sink ? &sink : &source;
	GIntVertex* end_vertex = is_source2sink ? &source : &sink;
	m_mpStartDistanceIndex.insert(make_pair(start_vertex, 0));
	start_vertex->Weight(0);
	m_quCandidateVertices.push(start_vertex);

	//3. start searching for the shortest path
	while (!m_quCandidateVertices.empty())
	{
		GIntVertex* cur_vertex_pt = m_quCandidateVertices.top();
		m_quCandidateVertices.pop();

		if (cur_vertex_pt->getID() == end_vertex->getID()) break;

		m_stDeterminedVertices.insert(cur_vertex_pt);

		improve2vertex(*cur_vertex_pt, is_source2sink);
	}
}

void DijkstraShortestPathAlg::improve2vertex( GIntVertex& cur_vertex, bool is_source2sink )
{
	// 1. get the neighboring vertices 
	
// 	Set<BaseVertex> neighbor_vertex_list = is_source2sink ? 
// 		_graph.get_adjacent_vertices(vertex) : _graph.get_precedent_vertices(vertex);
}