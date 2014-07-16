#pragma once
#include "Person.h"
class Officer:public Person
{
public:
	void showMenu(){}
    void checkUser(string name,string pwd);
};
