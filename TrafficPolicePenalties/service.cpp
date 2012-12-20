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
    stream << n.number << endl;
    stream << *n.begin;
    stream << endl;
    
    return stream;
}

istream &operator>>(istream &stream, Node &n)
{
    string str="@";
    Fine *tmp;
    
    getline(stream, n.number);
    
    getline(stream, str);
    while (!stream.eof() && !str.empty()){
        if (!n.begin) {
            n.begin = readFine(str);
            tmp = n.begin;
        } else {
            tmp->next = readFine(str);
            tmp = tmp->next;
        }
        getline(stream, str);
    }
    
    return stream;
}

void printNode(Node *r)
{
    cout << *r << endl;
}

void outNode(ostream &stream, Node *r)
{
    stream << *r;
}

//******************************************************************

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

//******************************************************************

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

/*
istream &operator>>(istream &stream, Data d)
{
    return stream;
}
*/

//******************************************************************

Fine *readFine(string &str)
{
    string s;
    size_t index;
    T *d = new T;
    
    index = str.find(";");
    if (index > 0) {
        d->time = str.substr(0, index);
        str = str.substr(++index);
    } else {
        cerr << "Error input file reading." << endl;
        exit(1);
    }

    index = str.find(";");
    if (index > 0) {
        d->type = str.substr(0, index);
        str = str.substr(++index);
    } else {
        cerr << "Error input file reading." << endl;
        exit(1);
    }

    if (!str.empty())
        d->price = atof(str.c_str());
    else {
        cerr << "Error input file reading." << endl;
        exit(1);
    }
    
    return new Fine(d);
}