#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 20;

class Customer
{
public:
	Customer();
	~Customer();

	void setSurname(char*);
	char* getSurname();

	void setFirstname(char*);
	char* getFirstname();

	void setPatronymic(char*);
	char* getPatronymic();

	void setAddress(char*);
	char* getAddress();

    void setPhone(int);
	int getPhone();

	void setCard(int);
	int getCard();

	void setCheck(int);
	int getCheck();

	void show(int);

private:
	char* surname;
	char* firstname;
	char* patronymic;
	char* address;
	int phone;
	int numberOfCard;
	int bankAccountNumber;
};
