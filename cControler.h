#ifndef cControler_H
#define cContoler_H
#include "cNode.h"
#include "cEdge.h"
#include "cGraph.h"
#include "cTree.h"
#include <vector>
#include <stack>
using namespace std;

template <class n, class e>
class cContoler{
public:
    typedef cContoler<n,e> self;
    typedef cNode<self> Node;
    typedef cEdge<self> Edge;
    typedef n N;
    typedef e E;

    vector<Node*> mNodes;
    vector<Edge*> mEdges;
	
    bool insertNode(N);
    bool insertEdge(E,N,N,bool);
    bool removeEdge(E,N,N);
    bool removeNode(N);
};

template <class n, class e>
bool cContoler<n,e>::insertNode(N x){
    return true;
}

template <class n, class e>
bool cContoler<n,e>::insertEdge(E x,N a,N b,bool dir){
    return true;
}

template <class n, class e>
bool cContoler<n,e>::removeEdge(E x,N a,N b){
    
    return true;
}

template <class n, class e>
bool cContoler<n,e>::removeNode(N x){

    return true;
}
#endif