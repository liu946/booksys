#pragma once
#include <iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
class Person
{
protected:
    string ID;
    string password;
	string name;
	string sex;
	string age;
	string book;
public:
    Person()
    {
		name="";
        sex = "man";
        age = "18";
		book="null";
    }
    virtual void showMenu()
    {

    }
    virtual void checkUser(string ,string)
    {
    }
    void getID(string ID1);
    void getpassword(string s);
	void getname(string a);
	void getsex(string b);
	void getage(string c);
	void getbook(string d);
	string sentID();
	string sentpassword();
	string sentname();
	string sentsex();
	string sentage();
	string sentbook();
};