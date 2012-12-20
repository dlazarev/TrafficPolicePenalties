//
//  BTree.h
//  TrafficPolicePenalties
//
//  Created by Dmitry Lazarev on 15.12.12.
//  Copyright (c) 2012 Ilya Lazarev. All rights reserved.
//

#ifndef __TrafficPolicePenalties__BTree__
#define __TrafficPolicePenalties__BTree__

#include <iostream>
#include "service.h"

class BTree {
private:
    Node* root;
    Node* _add(Node *r, T *d);
    Node* _add(Node *r, Node *);
    void _inOrderWalk(Node *r, void DoIt(Node*));
    void _inOrderWalk(ostream&, Node *r, void DoIt(ostream&, Node*));
    Node* _search(Node *r, const string&);
public:
    BTree() { root = NULL; }
    void Add(T *d);
    void Add(Node *n);
    void InOrderWalk(void DoIt(Node*));
    void InOrderWalk(ostream&, void DoIt(ostream&, Node*));
    Node* Search(const string&);
    void print();
    friend ostream &operator<<(ostream &stream, BTree r);
};

#endif /* defined(__TrafficPolicePenalties__BTree__) */
