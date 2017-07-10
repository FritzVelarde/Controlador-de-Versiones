#ifndef CNODE_H
#define CNODE_H

#include "cEdge.h"
#include <vector>
#include <string>

using namespace std;

template <class G>
class cNode{
public:
	typedef typename G::N N;
	typedef typename G::Edge Edge;
	
	N mData;
	vector<Edge*> mEdges;
	vector<Edge*> mPadres;
	vector<Edge*> mHijos;
	
	int altura;
	int balance;
	cNode<G>* pNodo[2];
	int seg;
	int min;
	int hor;
	int dia;
	int mes;
	int anh;
	string rama;
	
	cNode(N x){
		this->mData=x;
		altura=0;
		balance=0;
		seg=min=hor=dia=mes=anh=0;
		pNodo[0]=pNodo[1]=0;
	}
};

#endif