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

/*
Меню:
Для ввода нарушения - 1
Введите номер автомобиля
Ввежите дату и время нарушения
Введите тип нарушения
Введите сумму штрафа

Для оплаты штрафа - 2
Введите номер автомобиля
Введите дату и время нарушения

Получение сведений об автомобиле - 3
Введите номер автомобиля

Для печати суммарной информации - 4

Выход из программы - 6
*/

static float sum_fine = 0;
static int car_count = 0;

int main_menu(BTree *bt)
{
    T *data = new T;
    char c;
    string s;
    
    while(true) {
        cout << "Главное меню" << endl;
        cout << "------------------------------------" << endl;
        cout << "1. Ввод записи о нарушении." << endl;
        cout << "2. Оплата штрафа." << endl;
        cout << "3. Получение сведений об автомобиле." << endl;
        cout << "4. Печать сводной информации." << endl;
        cout << "5. Выход." << endl;
        cout << "------------------------------------" << endl;
        cout << "=>";
        
        getline(cin, s);
        c = s[0];
    
        switch (c) {
            case '1':
                data->userInput();
                bt->Add(data);
                break;

            case '2':
                fine_payment(bt);
                break;
            
            case '3':
                car_info(bt);
                break;
            
            case '4':
                report(bt);
                break;
            
            case '5':
                delete data;
                return 0;
                break;

            default:
                break;
        }
    }
    
    delete data;
    return 0;
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

void report(BTree* bt)
{
    sum_fine = 0;
    car_count = 0;
    bt->InOrderWalk(stat);
    
    cout << "Сводная информация о нарушениях и штрафах." << endl;
    cout << "******************************************" << endl;
    cout << "Количество автомобилей: " << car_count << endl;
    cout << "Общая сумма штрафов: " << sum_fine << endl;
    cout << "******************************************" << endl;
    cout << endl << "Штрафы по автомобилям: " << endl;
    bt->InOrderWalk(stat_by_car);
    cout << "******************************************" << endl;
    
}

void stat(Node* n)
{
    Fine *f = n->begin;
    while(f) {
        sum_fine += f->price;
        f = f->next;
    }
    car_count++;
    
}

void stat_by_car(Node* n)
{
    cout << n->number << ": " << n->sumFines() << " руб." << endl;
}

void car_info(BTree* bt)
{
    string num;
    cout << "Введите номер автомобиля: ";
    getline(cin, num);
    Node *car = bt->Search(num);
    Fine *tmp;
    
    if (car) {
        cout << "******************************************" << endl;
        cout << "Для автомобиля с гос. номером " << num << " зафиксированы следующие нарушения:" << endl;
        tmp = car->begin;
        while (tmp) {
            cout << tmp->type << ", от " << tmp->time.human_out() << " на сумму " << tmp->price << " руб." << endl;
            tmp = tmp->next;
        }
        cout << "******************************************" << endl;
    } else cout << " Для указанного автомобиля не найдено сведений" << endl;
    
}

void fine_payment(BTree *bt)
{
    string num;
    string time;
    float amount, payment;
    
    cout << "Введите номер автомобиля: ";
    getline(cin, num);
    Node *car = bt->Search(num);
    Fine *tmp;
    
    if (!car) {
        cout << " Для указанного автомобиля не найдено сведений" << endl;
        return;
    }
    
    tmp = car->begin;
    while (tmp) {
        cout << tmp->type << ", от " << tmp->time.human_out() << " на сумму " << tmp->price << " руб." << endl;
        tmp = tmp->next;
    }
    
    cout << "Введите дату штрафа, который вы хотите оплатить: ";
    getline(cin, time);
    tmp = car->searchFineByTime(time);
    if (!tmp) {
        cout << "Не найден штраф от указанной даты." << endl;
        return;
    }
    
    cout << "Укажите сумму оплаты, руб.: ";
    cin >> amount;
    
    payment = min(tmp->price, amount);
    tmp->price -= payment;
    amount -= payment;
    
    tmp = car->begin;
    while (tmp && amount > 0.0) {
        payment = min(tmp->price, amount);
        tmp->price -= payment;
        amount -= payment;
    }
    
    if (amount > 0.0)
        cout << "Остаток денежных средств в размере " << amount << " руб. будет учтен в будущих платежах :)" << endl;
    
    // Удалим штрафы с нулевыми суммами
    car->deleteZeroFine();
    
    
}
