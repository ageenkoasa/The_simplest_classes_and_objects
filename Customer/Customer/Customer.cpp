#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Customer.h"
#include <clocale>  
#include <Windows.h>
#include <iomanip>

using namespace std;

Customer::Customer() {
	this->surname = new char[30];
	this->firstname = new char[30];
	this->patronymic = new char[30];
	this->address = new char[30];
	this->phone = 0;
	this->numberOfCard = this->bankAccountNumber = 0;
}

Customer::~Customer() {}

void Customer::setSurname(char* s) {
	strcpy(surname, s);
}

void Customer::setFirstname(char* f) {
	strcpy(firstname, f);
}

void Customer::setPatronymic(char* p) {
	strcpy(patronymic, p);
}

void Customer::setAddress(char* a) {
	strcpy(address, a);
}

void Customer::setPhone(int p) {
	this->phone = p;
}

void Customer::setCard(int c) {
	this->numberOfCard = c;
}

void Customer::setCheck(int c) {
	this->bankAccountNumber = c;
}

char* Customer::getSurname() {
	return this->surname;
}

char* Customer::getFirstname() {
	return this->firstname;
}

char* Customer::getPatronymic() {
	return this->patronymic;
}

char* Customer::getAddress() {
	return this->address;
}

int Customer::getPhone() {
	return this->phone;
}

int Customer::getCard() {
	return this->numberOfCard;
}

int Customer::getCheck() {
	return this->bankAccountNumber;
}

void Customer::show(int n) {
	if (n + 1 < 10) {
		cout << "   |  " << n + 1 << "   " << getSurname() << setw(17) << getFirstname() << setw(19) << getPatronymic() << setw(18) << getAddress() << setw(20) << getPhone() << setw(20) << getCard() << setw(22) << getCheck() << endl;
	}
	else 	cout << "   |  " << n + 1 << "  " << getSurname() << setw(17) << getFirstname() << setw(19) << getPatronymic() << setw(18) << getAddress() << setw(20) << getPhone() << setw(20) << getCard() << setw(22) << getCheck() << endl;
}