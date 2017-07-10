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
    cGraph<string,int> grafo6;
    cGraph<string,int> grafo1;
    cGraph<string,int> grafo2;
    cGraph<string,int> grafo3;
    cGraph<string,int> grafo4;
    cGraph<string,int> grafo5;
    cTree<string,int> arbol;

grafo1.insertNode("primer commit");
grafo2.insertNode("primer commit");
    grafo2.insertNode("segundo commit");
grafo3.insertNode("primer commit");
    grafo3.insertNode("segundo commit");
    grafo3.insertNode("tercer commit");
grafo4.insertNode("primer commit");
    grafo4.insertNode("segundo commit");
    grafo4.insertNode("tercer commit");
    grafo4.insertNode("cuarto commit");  
grafo5.insertNode("primer commit");
    grafo5.insertNode("segundo commit");
    grafo5.insertNode("tercer commit");
    grafo5.insertNode("cuarto commit");
    grafo5.insertNode("quinto commit");    
grafo6.insertNode("primer commit");
    grafo6.insertNode("segundo commit");
    grafo6.insertNode("tercer commit");
    grafo6.insertNode("cuarto commit");
    grafo6.insertNode("quinto commit");
    grafo6.insertNode("sexto commit");
grafo2.insertEdge(1,"primer commit","segundo commit",0);
grafo3.insertEdge(1,"primer commit","segundo commit",0);
    grafo3.insertEdge(2,"segundo commit","tercer commit",0);
grafo4.insertEdge(1,"primer commit","segundo commit",0);
    grafo4.insertEdge(2,"segundo commit","tercer commit",0);
    grafo4.insertEdge(3,"tercer commit","cuarto commit",0);
grafo5.insertEdge(1,"primer commit","segundo commit",0);
    grafo5.insertEdge(2,"segundo commit","tercer commit",0);
    grafo5.insertEdge(3,"tercer commit","cuarto commit",0);
    grafo5.insertEdge(4,"cuarto commit","quinto commit",0);
grafo6.insertEdge(1,"primer commit","segundo commit",0);
    grafo6.insertEdge(2,"segundo commit","tercer commit",0);
    grafo6.insertEdge(3,"tercer commit","cuarto commit",0);
    grafo6.insertEdge(4,"cuarto commit","quinto commit",0);
    grafo6.insertEdge(5,"quinto commit","sexto commit",0);
		
	cout<<"------Tiempo1_nodos:"<<endl;
    for(int i=0; i<grafo1.mNodes.size();i++){
        cout<<grafo1.mNodes[i]->mData<<endl;
    }
    
    
	cout<<"------Tiempo2_nodos:"<<endl;
    for(int i=0; i<grafo2.mNodes.size();i++){
        cout<<grafo2.mNodes[i]->mData<<endl;
    }
    
	
	cout<<"------Tiempo3_nodos:"<<endl;
    for(int i=0; i<grafo3.mNodes.size();i++){
        cout<<grafo3.mNodes[i]->mData<<endl;
    }


	cout<<"------Tiempo4_nodos:"<<endl;
    for(int i=0; i<grafo4.mNodes.size();i++){
        cout<<grafo4.mNodes[i]->mData<<endl;
    }


	cout<<"------Tiempo5_nodos:"<<endl;
    for(int i=0; i<grafo5.mNodes.size();i++){
        cout<<grafo5.mNodes[i]->mData<<endl;
    }
    	cout<<"------Tiempo6_nodos:"<<endl;
    for(int i=0; i<grafo6.mNodes.size();i++){
        cout<<grafo6.mNodes[i]->mData<<endl;
    }

	for(int i=30010; i<grafo1.mNodes.size()+30010;i++){
		grafo1.mNodes[i-30010]->dia=i;
		arbol.insert2(grafo1.mNodes[i-30010]);
	}	
	for(int i=30110; i<grafo2.mNodes.size()+30110;i++){
		grafo2.mNodes[i-30110]->dia=i;
		arbol.insert2(grafo2.mNodes[i-30110]);
	}
	for(int i=30210; i<grafo3.mNodes.size()+30210;i++){
		grafo3.mNodes[i-30210]->dia=i;
		arbol.insert2(grafo3.mNodes[i-30210]);
	}
	for(int i=30310; i<grafo4.mNodes.size()+30310;i++){
		
		grafo4.mNodes[i-30310]->dia=i;
		arbol.insert2(grafo4.mNodes[i-30310]);
	}
	for(int i=30410; i<grafo5.mNodes.size()+30410;i++){
		grafo5.mNodes[i-30410]->dia=i;
		arbol.insert2(grafo5.mNodes[i-30410]);
	}	
	for(int i=30510; i<grafo6.mNodes.size()+30510;i++){
		// cNode<cGraph<string,int>>* ptr;
		grafo6.mNodes[i-30510]->dia=i;
		arbol.insert2(grafo6.mNodes[i-30510]);
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
