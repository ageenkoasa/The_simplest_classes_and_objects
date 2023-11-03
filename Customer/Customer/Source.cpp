#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Customer.h"
#include <fstream>
#include <clocale>  
#include <Windows.h>
#include <cstring>
#include <cstdio>
#include <ctime>

using namespace std;

void systemFun();
void header();
void footer();
void catalog(Customer* cust, int n);
void bubbleSort(Customer arr[], int n);
void getInterval(Customer arr[], int length, long from, long to);

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int n = 30;
    Customer* customers = new Customer[n];

    const char* path = "customers.txt";
    ifstream streamIn(path);
    if (!streamIn.is_open())
    {
        cout << "Файл не открыт для чтения!" << endl;
        system("pause");
        exit(1);
    }

    char* ch = new char[30];
    int x;
    while (!streamIn.eof()) {
        for (int i = 0; i < n; i++) {
            streamIn >> ch;
            customers[i].setSurname(ch);
            streamIn >> ch;
            customers[i].setFirstname(ch);
            streamIn >> ch;
            customers[i].setPatronymic(ch);
            streamIn >> ch;
            customers[i].setAddress(ch);
            streamIn >> x;
            customers[i].setPhone(x);
            streamIn >> x;
            customers[i].setCard(x);
            streamIn >> x;
            customers[i].setCheck(x);
        }
    }
    streamIn.close();

    cout << endl << "                         Список всех покупателей:" << endl;
    header();
    for (int i = 0; i < 30; i++) {
        customers[i].show(i);
    }
    footer();
    systemFun();

    catalog(customers, 30);
    
    delete[] customers;

    return 0;
}

void catalog(Customer* cust, int n) {
    cout << endl;
    cout << "                         Вывести:" << endl;
    cout << "           1. Cписок покупателей в алфавитном порядке\n";
    cout << "           2. Список покупателей, номер кредитной карточки которых находится в заданном интервале\n";
    cout << "           3. Закончить\n" << endl;
    cout << "           Введите выбранный пункт: ";

    int num;
    cin >> num;
    cout << endl;
    switch (num) {
    case 1:
        bubbleSort(cust, 30);
        header();
        for (int i = 0; i < 30; i++) {
            cust[i].show(i);
        }
        footer();
        systemFun();
        catalog(cust, n);
        break;
    case 2:
        cout << "Введите интервал:" << endl;
        long from;
        long to;
        cout << "от: ";
        cin >> from;
        cout << "до: ";
        cin >> to;
        header();
        getInterval(cust, 30, from, to);
        footer();
        systemFun();
        catalog(cust, n);
        break;
    case 3:
        systemFun();
        break;
    default:
        cout << "Ошибка, такого пункта нет\n";
        systemFun();
        catalog(cust, n);
        break;
    }
}

void systemFun() {
    cout << endl;
    system("pause");
    system("cls");
}

void header() {
    cout << "    _________________________________________________________________________________________________________________________________________________" << endl;
    cout << "   |  N  |   Фамилия    |    Имя       |      Отчество       |     Адрес       |     Номер     |    N кредитной карточки   |   N банковского счета   |" << endl;
    cout << "   |_____|______________|______________|_____________________|_________________|_______________|___________________________|_________________________|" << endl;
}

void footer() {
    cout << "   |__________________________________________________________________________________________________________________________________________________" << endl;
}

void bubbleSort(Customer arr[], int n) {
    bool flag;
    for (int i = 0; i < n; i++) {
        flag = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].getSurname(), arr[j + 1].getSurname()) > 0) {
                Customer temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = true;
            }
        }
        if (!flag) break;
    }
}

void getInterval(Customer arr[], int length, long from, long to) {
    for (int i = 0; i < length; i++) {
        long currentNumber = arr[i].getCard();
        if (currentNumber >= from && currentNumber <= to)
            arr[i].show(i);
    }
}