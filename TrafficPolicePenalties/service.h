//
//  service.h
//  TrafficPolicePenalties
//

#ifndef TrafficPolicePenalties_service_h
#define TrafficPolicePenalties_service_h

// Штраф
struct Fine {
    char *time;
    char *type;
    float price;
    Fine *next;
}

// Автомобиль
struct Node {
    char *number;
    Fine *begin;
    Node *left;
    Node *right;
}

// Данные о нарушении
struct Data {
    char *number;
    char *time;
    char *type;
    float price;
}

#endif
