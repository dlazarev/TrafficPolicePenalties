//
//  main.cpp
//  TrafficPolicePenalties

#include <iostream>
#include <fstream>
#include "BTree.h"
#include "functions.h"
using namespace std;

int main(int argc, const char * argv[])
{
    BTree bt;
    
    read_from_file(&bt);
    main_menu(&bt);
    save_to_file(&bt);
    
/*
    data->userInput();
    bt.Add(data);
    
    data->userInput();
    bt.Add(data);
    
    data->userInput();
    bt.Add(data);
*/

    return 0;
}

