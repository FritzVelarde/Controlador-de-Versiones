#include <iostream>
#include "cTree.h"
#include "cNode.h"

using namespace std;

int main(){
	cTree<int,string> arbol;
	
	arbol.insert(1);
	arbol.insert(2);
	arbol.insert(3);
	arbol.insert(4);
	arbol.insert(5);
	arbol.insert(6);
	arbol.insert(7);
	arbol.insert(8);
	arbol.insert(9);
	arbol.insert(10);
	// cout<<arbol.mRoot->mDato<<endl;
	cout<<"impresion inorden "<<endl;
	arbol.printInOrden(arbol.mRoot);
	cout<<endl;
	cout<<"impresion preorden "<<endl;
	arbol.printPreOrden(arbol.mRoot);
	cout<<endl;
	cout<<"impresion postorden "<<endl;
	arbol.printPostOrden(arbol.mRoot);
	cout<<endl;

	return 0;
}