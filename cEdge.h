#ifndef CEDGE_H
#define CEDGE_H

#include "cNode.h"

template <class G>
class cEdge{
public:
    typedef typename G::Node Node;
    typedef typename G::E E;

	bool m_dir; //0 BIDIRECCIONAL---1 UNIDIRECCIONAL
    E mData;
    Node* m_node[2];
	
    cEdge(E x,Node *a, Node *b, bool dir){

        m_node[0]=a;
        m_node[1]=b;
        mData=x;
        m_dir=dir;
    }
};

#endif