//
//  main.cpp
//  TrafficPolicePenalties

#include <iostream>
#include "BTree.h"
using namespace std;

int main(int argc, const char * argv[])
{
    BTree bt;
    T *data = new T;
    
    data->userInput();
    bt.Add(data);
    
    data->userInput();
    bt.Add(data);
    
    data->userInput();
    bt.Add(data);
    
    bt.print();
    
    
    delete data;
    return 0;
}

