//
//  main.cpp
//  TrafficPolicePenalties

#include <iostream>
#include <fstream>
#include "BTree.h"
using namespace std;

int main(int argc, const char * argv[])
{
    BTree bt;
    T *data = new T;
    Node *n;
    
    ifstream infile("TrafficPolicePenalties.dat");
    if (!infile) {
        cout << "Input file error." << endl;
        return 1;
    }
    
    while (!infile.eof()) {
        n = new Node;
        infile >> *n;
        if (!n->number.empty())
            bt.Add(n);
    }
    infile.close();
    
/*
    data->userInput();
    bt.Add(data);
    
    data->userInput();
    bt.Add(data);
    
    data->userInput();
    bt.Add(data);
*/
    ofstream outfile("TrafficPolicePenalties.dat");
    if (!outfile) {
        cout << "Output file error." << endl;
        return 1;
    }

    outfile << bt;
    outfile.close();

    delete data;
    return 0;
}

