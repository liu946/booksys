#pragma once
#include "Person.h"
class Manager :public Person
{
public:
	void showMenu(){}
    void checkUser(string name,string pwd);
};

