//
//  service.cpp
//  TrafficPolicePenalties
//
//  Created by Dmitry Lazarev on 18.12.12.
//  Copyright (c) 2012 Ilya Lazarev. All rights reserved.
//

#include <stdio.h>
#include "service.h"

Node::Node(T *d)
{
    number = d->number;
    begin = new Fine(d);
    left = NULL;
    right = NULL;
}

Fine::Fine(T *d)
{
    time = d->time;
    type = d->type;
    price = d->price;
    next = NULL;
}