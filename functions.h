//
//  functions.h
//  TrafficPolicePenalties

#ifndef TrafficPolicePenalties_functions_h
#define TrafficPolicePenalties_functions_h

#include "BTree.h"

/*
#define DATA_FILE "/Users/ramporez/Documents/XcodeProjects/TrafficPolicePenalties/TrafficPolicePenalties/TrafficPolicePenalties.dat"
*/
#define DATA_FILE "/Users/dmitry/projects/Univer/TrafficPolicePenalties/TrafficPolicePenalties/TrafficPolicePenalties.dat"

int main_menu(BTree*);
void read_from_file(BTree*);
void save_to_file(BTree*);
void report(BTree*);
void stat(Node* n);
void stat_by_car(Node* n);
void car_info(BTree*);
void fine_payment(BTree*);
#endif
