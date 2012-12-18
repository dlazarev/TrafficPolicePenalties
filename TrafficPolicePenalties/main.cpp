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
    
    data->userInput();
    bt.Add(data);
    
    data->userInput();
    bt.Add(data);
    
    data->userInput();
    bt.Add(data);
    
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

