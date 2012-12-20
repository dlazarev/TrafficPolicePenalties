//
//  functions.h
//  TrafficPolicePenalties

#ifndef TrafficPolicePenalties_functions_h
#define TrafficPolicePenalties_functions_h

#include "BTree.h"

#define DATA_FILE "/Users/ramporez/Documents/XcodeProjects/TrafficPolicePenalties/TrafficPolicePenalties/TrafficPolicePenalties.dat"

int main_menu(BTree*);
void read_from_file(BTree*);
void save_to_file(BTree*);
void report(BTree*);
void stat(Node* n);
#endif
