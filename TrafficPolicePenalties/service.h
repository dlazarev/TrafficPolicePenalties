//
//  service.h
//  TrafficPolicePenalties
//

#ifndef TrafficPolicePenalties_service_h
#define TrafficPolicePenalties_service_h

#include <string>
using namespace std;

// Данные о нарушении
struct Data {
    string number;
    string time;
    string type;
    float price;
};

typedef Data T;

// Штраф
struct Fine {
    string time;
    string type;
    float price;
    Fine *next;
public:
    Fine(T *d);
};

// Автомобиль
struct Node {
    string number;
    Fine *begin;
    Node *left;
    Node *right;
public:
    Node(T *d);
};


#endif
