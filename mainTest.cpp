#include <iostream>
#include <vector>
#include <string>
#include "cNode.h"
#include "cEdge.h"
#include "cGraph.h"
#include "cTree.h"

using namespace std;

int main()
{
    cGraph<string,int> grafo;
    cGraph<string,int> grafo2;
	cTree<string,int> arbol;
	
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
	
	cout<<grafo.mNodes.size()<<endl<<endl;

	for(int i=0; i<grafo.mNodes.size();i++){
		// cNode<cGraph<string,int>>* ptr;
		grafo.mNodes[i]->dia=i;
		arbol.insert2(grafo.mNodes[i]);
	}
	cout<<"impresion inorden "<<endl;
	arbol.printInOrden(arbol.mRoot);
	cout<<endl;
	cout<<"impresion preorden "<<endl;
	arbol.printPreOrden(arbol.mRoot);
	cout<<endl;
	cout<<"impresion postorden "<<endl;
	arbol.printPostOrden(arbol.mRoot);
	cout<<endl;
	
	// string b = to_String(4+5);
	// cout<<b<<endl;
    return 0;
}