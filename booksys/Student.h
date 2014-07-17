#pragma once
#include "Person.h"

class Student:public Person
{
public:
    void showMenu(){}
    void checkUser(string name,string pwd);
	void borrow(string IDbook);
	void lent(string IDbook);
	string checkbook();
	int numbook(string );
	void returnbook(string *);
};