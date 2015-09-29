#include "_algo_common.h"
#include "../Data Structures/Library/Graph/_graph_common.h"
#include "../Data Structures/Library/Graph/Graph.h"
#include "../Data Structures/Library/Graph/Tree.h"


#ifndef _CPPREF_PRIM_H_
#define _CPPREF_PRIM_H_

class Prim : public Solver {
public:
    const static string path;
    const static string file;

    Prim(Graph graph = Graph(), Tree tree = Tree());

    Graph& graph;
    Tree& tree;
    double treeCost;

    string solve();
    Edge& findMinEdgesFrom(GraphNode* node);
    Prim& read();
};


#endif //_CPPREF_PRIM_H_
