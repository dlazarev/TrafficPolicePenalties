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
public:
    void userInput(void); // Ввод данных о нарушении
//   friend istream &operator>>(istream &stream, Data d); // Чтение записи из файла
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
    friend ostream &operator<<(ostream &stream, Fine n);
};

// Автомобиль
struct Node {
    string number;
    Fine *begin;
    Node *left;
    Node *right;
public:
    Node() {number = ""; begin = NULL; left = NULL; right = NULL; }
    Node(T *d);
    void addFine(T*);
    friend ostream &operator<<(ostream &stream, Node n);
    friend istream &operator>>(istream &stream, Node &n);
};

void printNode(Node*);
void outNode(ostream &stream, Node *r);
Fine *readFine(string&);

#endif
