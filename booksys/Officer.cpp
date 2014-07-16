#include "StdAfx.h"
#include "Officer.h"
#include<fstream>
void Officer::checkUser(string name2,string pwd2)
{
    fstream file;
    file.open("Officer.dat",ios::in);
    string ID1,password1,name1,sex1,book1;
    string age1;
    while(!file.eof())
    {
        file>>ID1>>password1>>name1>>sex1>>age1>>book1;
        if(name2==name1&&pwd2==password1)
        {
            this->ID = ID1;
            this->password = password1;
            this->name = name1;
            this->sex = sex1;
            this->age = age1;
            this->book = book1;
        }
    }
    file.close();
}


