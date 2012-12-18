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
    void _inOrderWalk(Node *r, void DoIt(Node*));
public:
    void Add(T *d);
    void InOrderWalk(void DoIt(Node*));
    void print();
    friend ostream &operator<<(ostream &stream, BTree r);
};

#endif /* defined(__TrafficPolicePenalties__BTree__) */
