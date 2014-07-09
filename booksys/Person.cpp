#include "StdAfx.h"
#include "Person.h"

void Person::getID(string ID1)
{
    ID=ID1;
}
void Person::getpassword(string s)
{
    password=s;
}
void Person::getname(string a)
{
    name = a;
}
void Person::getsex(string b)
{
    sex = b;
}
void Person::getage(int c)
{
    age = c;
}
void Person::getbook(string d)
{
    book = d;
}
void Person::getxx(bool x)
{
    xx = x;
}
string Person::sentID()
{
    return ID;
}
string Person::sentpassword()
{
    return password;
}
string Person::sentname()
{
    return name;
}
string Person::sentsex()
{
    return sex;
}
int Person::sentage()
{
    return age;
}
string Person::sentbook()
{
    return book;
}
bool Person::sentxx()
{
    return xx;
}
