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
    cGraph<string,int> grafoMain;
    cGraph<string,int> grafo;
    cTree<string,int> arbol;
	

    grafoMain.insertNode("primer commit");
    grafoMain.insertNode("segundo commit");
    grafoMain.insertNode("tercer commit");
    grafoMain.insertNode("cuarto commit");
    grafoMain.insertNode("quinto commit");
    grafoMain.insertNode("sexto commit");
    grafoMain.insertNode("primer commit");
    
    grafo.insertNode("primer commit");
	cout<<"------Tiempo1_nodos:"<<endl;
    for(int i=0; i<grafo.mNodes.size();i++){
        cout<<grafo.mNodes[i]->mData<<endl;
    }
    grafo.insertNode("segundo commit");
    
	cout<<"------Tiempo2_nodos:"<<endl;
    for(int i=0; i<grafo.mNodes.size();i++){
        cout<<grafo.mNodes[i]->mData<<endl;
    }
    grafo.insertNode("tercer commit");
	
	cout<<"------Tiempo3_nodos:"<<endl;
    for(int i=0; i<grafo.mNodes.size();i++){
        cout<<grafo.mNodes[i]->mData<<endl;
    }

    grafo.insertNode("cuarto commit");
	cout<<"------Tiempo4_nodos:"<<endl;
    for(int i=0; i<grafo.mNodes.size();i++){
        cout<<grafo.mNodes[i]->mData<<endl;
    }

    grafo.insertNode("quinto commit");
	cout<<"------Tiempo5_nodos:"<<endl;
    for(int i=0; i<grafo.mNodes.size();i++){
        cout<<grafo.mNodes[i]->mData<<endl;
    }
    grafo.insertNode("sexto commit");
	cout<<"------Tiempo6_nodos:"<<endl;
    for(int i=0; i<grafo.mNodes.size();i++){
        cout<<grafo.mNodes[i]->mData<<endl;
    }
    grafo.insertEdge(1,"primer commit","segundo commit",0);
    grafo.insertEdge(2,"segundo commit","tercer commit",0);
    grafo.insertEdge(3,"tercer commit","cuarto commit",0);
    grafo.insertEdge(4,"cuarto commit","quinto commit",0);
    grafo.insertEdge(5,"quinto commit","sexto commit",0);
	
/*	cout<<"------nodos:"<<endl;
    for(int i=0; i<grafo.mNodes.size();i++){
        cout<<grafo.mNodes[i]->mData<<endl;
    }
	
	cout<<"------aristas:"<<endl;
    for(int i=0; i<grafo.mEdges.size(); i++){
    	cout<<"Arista "<<grafo.mEdges[i]->mData<<" Nodos: "<<grafo.mEdges[i]->m_node[0]->mData<<" - "<<grafo.mEdges[i]->m_node[1]->mData<<endl;
		if(!grafo.mEdges[i]->m_dir)
		cout<<"Arista "<<grafo.mEdges[i]->mData<<" Nodos: "<<grafo.mEdges[i]->m_node[1]->mData<<" - "<<grafo.mEdges[i]->m_node[0]->mData<<endl;
	}*/
    
	grafo.removeEdge(1,"primer commit","segundo commit");
    grafo.removeNode("primer commit");
    
/*	cout<<"------nodos:"<<endl;
    for(int i=0; i<grafo.mNodes.size();i++){
        cout<<grafo.mNodes[i]->mData<<endl;
    }

    cout<<"------aristas:"<<endl;
    for(int i=0; i<grafo.mEdges.size(); i++){
    	cout<<"Arista "<<grafo.mEdges[i]->mData<<" Nodos: "<<grafo.mEdges[i]->m_node[0]->mData<<" - "<<grafo.mEdges[i]->m_node[1]->mData<<endl;
		if(!grafo.mEdges[i]->m_dir)
		cout<<"Arista "<<grafo.mEdges[i]->mData<<" Nodos: "<<grafo.mEdges[i]->m_node[1]->mData<<" - "<<grafo.mEdges[i]->m_node[0]->mData<<endl;
	}*/
	
	cout<<grafo.mNodes.size()<<endl<<endl;

	for(int i=300; i<grafo.mNodes.size()+300;i++){
		// cNode<cGraph<string,int>>* ptr;
		grafo.mNodes[i-300]->dia=i;
		arbol.insert2(grafo.mNodes[i-300]);
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
