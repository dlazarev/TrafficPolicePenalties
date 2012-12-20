//
//  functions.cpp
//  TrafficPolicePenalties
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "functions.h"
#include "BTree.h"

using namespace std;

int main_menu(void)
{
    
}

void read_from_file(BTree *bt)
{
    Node *n;
    ifstream infile(DATA_FILE);
    if (!infile) {
        cout << "Input file error." << endl;
        exit(1);
    }
    
    while (!infile.eof()) {
        n = new Node;
        infile >> *n;
        if (!n->number.empty())
            bt->Add(n);
    }
    infile.close();
    
}

void save_to_file(BTree *bt)
{
    ofstream outfile(DATA_FILE);
    if (!outfile) {
        cout << "Output file error." << endl;
        exit(1);
    }
    
    outfile << *bt;
    outfile.close();
}
