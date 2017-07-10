#ifndef CGRAPH_H
#define CGRAPH_H
#include "cNode.h"
#include "cEdge.h"
#include <vector>

using namespace std;

template <class n, class e>
class cGraph{
public:
    typedef cGraph<n,e> self;
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
bool cGraph<n,e>::insertNode(N x){

    Node* new_node=new Node(x);
    mNodes.push_back(new_node);
    return true;
}

template <class n, class e>
bool cGraph<n,e>::insertEdge(E x,N a,N b,bool dir){
	//a padre
	//b hijo
    Node *Na,*Nb;
    for(int i=0; i<mNodes.size(); i++){
        if(mNodes[i]->mData==a) Na=mNodes[i];
        if(mNodes[i]->mData==b) Nb=mNodes[i];
    }
    Edge* new_edge=new Edge(x,Na,Nb,dir);
    Na->mEdges.push_back(new_edge);
    Na->mHijos.push_back(new_edge);
    Nb->mEdges.push_back(new_edge);
    Nb->mPadres.push_back(new_edge);
    mEdges.push_back(new_edge);
    return true;
}

template <class n, class e>
bool cGraph<n,e>::removeEdge(E x,N a,N b){
    Node *Na,*Nb;
    for(int i=0; i<mNodes.size(); i++){

        if(mNodes[i]->mData==a) Na=mNodes[i];
        if(mNodes[i]->mData==b) Nb=mNodes[i];
    }
    Edge* borrar;
    for(int i=0; i<mNodes.size(); i++){
        for(int j=0; j<mNodes[i]->mEdges.size(); j++){

            if((mNodes[i]->mEdges[j])->mData==x && (mNodes[i]->mEdges[j])->m_node[0]==Na && (mNodes[i]->mEdges[j])->m_node[1]==Nb){

                mNodes[i]->mEdges.erase(mNodes[i]->mEdges.begin()+j);
            }
        }
    }
    for(int i=0; i<mEdges.size(); i++){

        if((mEdges[i])->mData==x && (mEdges[i])->m_node[0]==Na && (mEdges[i])->m_node[1]==Nb){
            borrar= mEdges[i];
            mEdges.erase(mEdges.begin()+i);
            delete borrar;
        }
    }
    return true;
}

template <class n, class e>
bool cGraph<n,e>::removeNode(N x){

    Node* borrar;
    for(int i=0; i<mNodes.size(); i++){

        if((mNodes[i])->mData==x){
            borrar= mNodes[i];
            for(int j=0; j<(mNodes[i])->mEdges.size(); j++){

                removeEdge(((mNodes[i])->mEdges[j])->mData,((mNodes[i])->mEdges[j])->m_node[0]->mData,((mNodes[i])->mEdges[j])->m_node[1]->mData);
            }
            mNodes.erase(mNodes.begin()+i);
            delete borrar;
        }
    }
    return true;
}

#endif