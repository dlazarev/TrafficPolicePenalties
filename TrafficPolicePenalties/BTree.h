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

public:
    void Add(T *d);
};

#endif /* defined(__TrafficPolicePenalties__BTree__) */
