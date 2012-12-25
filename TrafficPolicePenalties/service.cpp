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

ostream &operator<<(ostream &stream, DateTime d)
{
    stream << d.datetime;
    return stream;
}

string DateTime::human_out()
{
    string result = datetime.substr(6,2) + "." + datetime.substr(4,2) + "." + datetime.substr(0,4) +
    " " + datetime.substr(8,2) + ":" + datetime.substr(10,2);
    return result;
}

Node::Node(T *d)
{
    number = d->number;
    begin = new Fine(d);
    left = NULL;
    right = NULL;
}

void Node::addFine(T *d)
{
    Fine *tmp = begin;
    
    while (tmp) {
        if (!tmp->next) {
            tmp->next = new Fine(d);
            break;
        }
        tmp = tmp->next;
    }
}

float Node::sumFines()
{
    float sum_fines = 0.0;
    Fine *tmp = begin;
    
    while (tmp) {
        sum_fines += tmp->price;
        tmp = tmp->next;
    }
    return sum_fines;
}

void Node::deleteZeroFine()
{
    Fine *tmp = begin;
    Fine *prev = NULL;
    
    while (tmp) {
        if (tmp->price == 0.0) {
            if (tmp == begin) { // Это первый элемент
                begin = tmp->next;
                delete tmp;
            } else {
                prev->next = tmp->next;
                tmp = tmp->next;
                delete tmp;
            
            }
        } else {
            prev = tmp;
            tmp = tmp->next;
        }
    }
}

ostream &operator<<(ostream &stream, Node n)
{
    stream << n.number << endl;
    if (n.begin)
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

Fine* Node::searchFineByTime(const string& str)
{
    Fine *tmp = begin;
    while (tmp) {
        if (tmp->time.datetime == str)
            return tmp;
        tmp = tmp->next;
    }
    
    return NULL;
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