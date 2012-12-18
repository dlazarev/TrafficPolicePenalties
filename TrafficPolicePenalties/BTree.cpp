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
    if (root == NULL)
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
