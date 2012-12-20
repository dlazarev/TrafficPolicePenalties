//
//  main.cpp
//  TrafficPolicePenalties

#include <iostream>
#include <fstream>
#include "BTree.h"
#include "functions.h"

int main(int argc, const char * argv[])
{
    BTree bt;
    
    read_from_file(&bt);
    main_menu(&bt);
    

    
//    Node *n = bt.Search(string("A318KK52"));
    save_to_file(&bt);
//    cout << bt;
    return 0;
}

