#ifndef CcTree_H
#define CcTree_H
#include "cNode.h"
#include "cEdge.h"
#include "cGraph.h"
#include <stack>
using namespace std;

template <class n, class e>
class cTree{
public:
	typedef cGraph<n,e> T;
	typedef cNode<T> Node;
	typedef cEdge<T> Edge;
	typedef n N;
    typedef e E;
	cNode<T>* mRoot;
	stack<cNode<T>**> recorrido;
	cTree();
	bool find(int, cNode<T>**&);
	bool insert(int);
	bool insert2(cNode<T>*&);
	bool remove(int);
	void printInOrden(cNode<T>*);
	void printPostOrden(cNode<T>*);
	void printPreOrden(cNode<T>*);
	int check_altura(cNode<T>*);
	void RR(cNode<T>**&);
	void LL(cNode<T>**&);
	void RL(cNode<T>**&);
	void LR(cNode<T>**&);
	void check_balance();
};
	
	template <class n, class e>
	cTree<n,e>::cTree(){
		mRoot=0;
	}
	
	template <class n, class e>
	bool cTree<n,e>::find(int x, cNode<T>**& p){
		for(p = &mRoot; *p && x != (*p)->dia; p = &((*p)->pNodo[x>(*p)->dia]));
		return *p!=0;
	}
	
	template <class n, class e>
	bool cTree<n,e>::insert(int x){
		// std::cout<<"insertare "<<x<<std::endl;
		// cNode<T>** p = &mRoot;
		cNode<T>** p;
		if(find(x, p)){
			// std::cout<<"	no inserte "<<x<<std::endl;
			return 0;
		}
		*p = new cNode<T> (x);
		(*p)->dia=x;
		check_balance();
		// std::cout<<"	inserte "<<x<<std::endl;
		return 1;
	}
	
	template <class n, class e>
	bool cTree<n,e>::insert2(cNode<T>*& q){
		int x = q->dia; 
		cNode<T>** p;
		find(x, p);
		*p = q;
		check_balance();
		return 1;
	}
	
	template <class n, class e>
	bool cTree<n,e>::remove(int x){
		cNode<T>** p = &mRoot;
		if(!find(x, p)){
			return 0;
		}
		if((*p)->pNodo[0] && (*p)->pNodo[1]){
			cNode<T>** q = p;
			q = &((*q)->pNodo[0]);
			while((*q)->pNodo[1])
				q = &((*q)->pNodo[1]);
			
			(*p)->dia = (*q)->dia;
			p=q;
		}
		cNode<T>* temporal = *p;
		*p = (*p)->pNodo[(*p)->pNodo[1]!=0];
		delete temporal;
		return 1;
	}
	
	template <class n, class e>
	int cTree<n,e>::check_altura(cNode<T> *p){
	  if (!p)
		{
		  return 0;
		}
	  return max(check_altura(p->pNodo[0]),check_altura(p->pNodo[1]))+1;
	}
	
	template <class n, class e>
	void cTree<n,e>::check_balance(){
		while (!recorrido.empty()) {

		  cNode<T>**temp;
		  temp=recorrido.top();
		  recorrido.pop();

		  (*temp)->altura=check_altura(*temp);
		  // cout<<(*temp)->dia<<" "<<(*temp)->altura<<endl;
		  (*temp)->balance=check_altura((*temp)->pNodo[1])-check_altura((*temp)->pNodo[0]);
		  // cout<<(*temp)->dia<<" "<<(*temp)->balance<<endl;

		  if((*temp)->balance==2 && (*temp)->pNodo[1]->balance==-1)LR(temp);
		  if((*temp)->balance==-2 && (*temp)->pNodo[0]->balance==1)RL(temp);
		  if((*temp)->balance==2)RR(temp);
		  if((*temp)->balance==-2)LL(temp);

		  // cout<<endl;

		 // preorden(m_root);
		  // cout<<"Amplitud"<<endl;
		  // Amplitud();
		  // cout<<endl;

		}
	}
	
	template <class n, class e>
	void cTree<n,e>::RR(cNode<T> **&a){
		// cout<<"RR"<<endl;

		cNode<T> *temp;
		temp=(*a);
		(*a)=(*a)->pNodo[1];
		(temp)->pNodo[1]=(*a)->pNodo[0];
		(*a)->pNodo[0]=temp;
		//recorrido.push(a);
		// preorden(*a);

		//derecha
		// cout<<endl;
	}

	template <class n, class e>
	void cTree<n,e>::LL(cNode<T> **&a){
		// cout<<"LL"<<endl;
		cNode<T> *temp;
		(temp)=(*a);
		(*a)=(*a)->pNodo[0];
		(temp)->pNodo[0]=(*a)->pNodo[1];
		(*a)->pNodo[1]=(temp);

		// recorrido.push(a);
		// preorden(*a);
		// cout<<endl;
	}

	template <class n, class e>
	void cTree<n,e>::RL(cNode<T> **&a){
		// cout<<"RL"<<endl;

		cNode<T>**t=&(*a)->pNodo[0];
		RR(t);
		LL(a);
		 //derecha
		// cout<<endl;

	}

	template <class n, class e>
	void cTree<n,e>::LR(cNode<T> **&a){
		// cout<<"LR"<<endl;

		cNode<T>**t=&(*a)->pNodo[1];
		LL(t);
		RR(a);
		// cout<<endl;
	}
	
	template <class n, class e>
	void cTree<n,e>::printInOrden(cNode<T>* p){
		if((p)->pNodo[0]){
			printInOrden((p)->pNodo[0]);
		}
		std::cout<<(p)->dia<<", ";
		if((p)->pNodo[1]){
			printInOrden((p)->pNodo[1]);
		}
	}
	
	template <class n, class e>
	void cTree<n,e>::printPreOrden(cNode<T>* p){
		std::cout<<(p)->dia<<", ";
		if((p)->pNodo[0]){
			printPreOrden((p)->pNodo[0]);
		}
		if((p)->pNodo[1]){
			printPreOrden((p)->pNodo[1]);
		}
	}
	
	template <class n, class e>
	void cTree<n,e>::printPostOrden(cNode<T>* p){
		if((p)->pNodo[0]){
			printPostOrden((p)->pNodo[0]);
		}
		if((p)->pNodo[1]){
			printPostOrden((p)->pNodo[1]);
		}
		std::cout<<(p)->dia<<", ";
	}
#endif
