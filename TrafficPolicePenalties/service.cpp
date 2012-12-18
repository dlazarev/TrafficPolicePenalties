//
//  service.cpp
//  TrafficPolicePenalties
//
//  Created by Dmitry Lazarev on 18.12.12.
//  Copyright (c) 2012 Ilya Lazarev. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <limits>

#include "service.h"
using namespace std;

Node::Node(T *d)
{
    number = d->number;
    begin = new Fine(d);
    left = NULL;
    right = NULL;
}

ostream &operator<<(ostream &stream, Node n)
{
    stream << n.number;
    stream << *n.begin;
    
    return stream;
}

Fine::Fine(T *d)
{
    time = d->time;
    type = d->type;
    price = d->price;
    next = NULL;
}

ostream &operator<<(ostream &stream, Fine f)
{
    stream << f.time << ';' << f.type << ';' << f.price << endl;
    if (f.next)
        stream << *f.next;
    
    return stream;
}

void Data::userInput(void)
{
    // Чистим входной поток
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    
    cout << "Input car number: ";
    getline(cin, number);

    cout << "Input date and time of the offense [yyyymmddhhmm]: ";
    getline(cin, time);

    cout << "Input the offense description: ";
    getline(std::cin, type);
    
    cout << "Input the penalty rate: ";
    cin >> price;
}

void printNode(Node *r)
{
    cout << *r << endl;
}

void outNode(ostream &stream, Node *r)
{
    stream << *r;
}