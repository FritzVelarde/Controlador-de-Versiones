#include <iostream>
#include <vector>
#include "cNode.h"
#include "cEdge.h"
#include "cGraph.h"

using namespace std;

int main()
{
    cGraph<string,int> grafo;
    cGraph<int,string> grafo2;
	
    grafo.insertNode("primer commit");
    grafo.insertNode("segundo commit");
    grafo.insertNode("tercer commit");
    grafo.insertNode("cuarto commit");
    grafo.insertNode("quinto commit");
    grafo.insertNode("sexto commit");
    grafo.insertEdge(1,"primer commit","segundo commit",0);
    grafo.insertEdge(2,"tercer commit","cuarto commit",1);
    grafo.insertEdge(3,"sexto commit","segundo commit",1);
    grafo.insertEdge(4,"quinto commit","tercer commit",1);
    grafo.insertEdge(5,"segundo commit","quinto commit",1);
	
	grafo2.insertNode(1);
	grafo2.insertNode(2);
	grafo2.insertEdge("a",1,2,0);
	grafo2.insertEdge("b",1,2,0);
	// grafo2.mEdges[].m_node[0]=grafo.mEdges
	
	
	cout<<"------nodos:"<<endl;
    for(int i=0; i<grafo.mNodes.size();i++){
        cout<<grafo.mNodes[i]->mData<<endl;
    }
	
	cout<<"------aristas:"<<endl;
    for(int i=0; i<grafo.mEdges.size(); i++){
    	cout<<"Arista "<<grafo.mEdges[i]->mData<<" Nodos: "<<grafo.mEdges[i]->m_node[0]->mData<<" - "<<grafo.mEdges[i]->m_node[1]->mData<<endl;
		if(!grafo.mEdges[i]->m_dir)
		cout<<"Arista "<<grafo.mEdges[i]->mData<<" Nodos: "<<grafo.mEdges[i]->m_node[1]->mData<<" - "<<grafo.mEdges[i]->m_node[0]->mData<<endl;
	}
    
	grafo.removeEdge(1,"primer commit","segundo commit");
    grafo.removeNode("primer commit");
    
	cout<<"------nodos:"<<endl;
    for(int i=0; i<grafo.mNodes.size();i++){
        cout<<grafo.mNodes[i]->mData<<endl;
    }

    cout<<"------aristas:"<<endl;
    for(int i=0; i<grafo.mEdges.size(); i++){
    	cout<<"Arista "<<grafo.mEdges[i]->mData<<" Nodos: "<<grafo.mEdges[i]->m_node[0]->mData<<" - "<<grafo.mEdges[i]->m_node[1]->mData<<endl;
		if(!grafo.mEdges[i]->m_dir)
		cout<<"Arista "<<grafo.mEdges[i]->mData<<" Nodos: "<<grafo.mEdges[i]->m_node[1]->mData<<" - "<<grafo.mEdges[i]->m_node[0]->mData<<endl;
	}
	
	cout<<grafo.mNodes.size()<<endl;	
	
    return 0;
}