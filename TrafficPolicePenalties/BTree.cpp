//
//  BTree.cpp
//  TrafficPolicePenalties
//
//  Created by Dmitry Lazarev on 15.12.12.
//  Copyright (c) 2012 Ilya Lazarev. All rights reserved.
//

#include "BTree.h"
#include "service.h"

Node* BTree::_add(Node *r, T *d)
{
    if (r == NULL)
        r = new Node(d);
    else if (d->number < r->number)
        r->left = _add(r->left, d); // Вставка в левое поддерево
    else
        r->right = _add(r->right, d); // Вставка в правое поддерево
    return r;
}

void BTree::Add(T *d)
{
    root = _add(root, d);
}

void BTree::_inOrderWalk(Node *r, void DoIt(Node*))
{
    if(r == NULL) return;
    DoIt(r);
    _inOrderWalk(r->left, DoIt);
    _inOrderWalk(r->right, DoIt);
}

void BTree::InOrderWalk(void DoIt(Node*))
{
    _inOrderWalk(root, DoIt);
}

void BTree::print()
{
    _inOrderWalk(root, printNode);
}

ostream &operator<<(ostream &stream, BTree r)
{
    stream << "I'm BTree!" << endl;
    return stream;
}
