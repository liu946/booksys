#pragma once
#include <iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
class Person
{
private:
    string ID;
    string password;
	string name;
	string sex;
	int age;
	string book;
public:
    Person()
    {
        sex = "man";
        age = 18;
		book="null";
    }
    virtual void showMenu()
    {

    }
    virtual int checkUser()
    {
        return 0;
    }
    void getID(string ID1);
    void getpassword(string s);
	void getname(string a);
	void getsex(string b);
	void getage(int c);
	void getbook(string d);
	string sentID();
	string sentpassword();
	string sentname();
	string sentsex();
	int sentage();
	string sentbook();
};