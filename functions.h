//
//  functions.h
//  TrafficPolicePenalties

#ifndef TrafficPolicePenalties_functions_h
#define TrafficPolicePenalties_functions_h

#include "BTree.h"

#define DATA_FILE "/Users/dmitry/projects/Univer/TrafficPolicePenalties/TrafficPolicePenalties/TrafficPolicePenalties.dat"

int main_menu(void);
void read_from_file(BTree*);
void save_to_file(BTree*);

#endif
