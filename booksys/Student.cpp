#include "StdAfx.h"
#include "Student.h"
#include<fstream>
void Student::checkUser(string name2,string pwd2)
{
    fstream file;
    file.open("student.dat",ios::in);
    string ID1,password1,name1,sex1,book1;
    string age1;
	this->name="";
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
void Student::borrow(string IDbook)
{
    fstream file;
    file.open("connect.dat",ios::out|ios::app);
    file<<this->sentID()<<' '<<IDbook<<endl;
    file.close();
}
void Student::lent(string IDbook)
{
    fstream file1,file2;
    file1.open("connect.dat",ios::in);
    file2.open("connect1.dat",ios::out);
    while(!file1.eof())
    {
        string IDP1,IDB1;
        file1>>IDP1>>IDB1;
        if(!(IDP1==this->sentID()&&IDB1==IDbook))
            file2<<IDP1<<' '<<IDB1<<endl;
    }
    file1.close();
    file2.close();
    file1.open("connect.dat",ios::out);
    file2.open("connect1.dat",ios::in);
    while(!file2.eof())
    {
        string IDP1,IDB1;
        file2>>IDP1>>IDB1;
        file1<<IDP1<<' '<<IDB1<<endl;
    }
    file1.close();
    file2.close();    
}
string Student::checkbook()
{
    fstream file;
    int num=0;
    file.open("connect.dat",ios::in);
    while(!file.eof())
    {
        string IDp2,IDb2;
        file>>IDp2>>IDb2;
        if(IDp2==this->sentID()) num++;
    }
	file.close();
	char i[5];
    itoa(num,i,4);
	string s(i);
	return s; 
}


int Student::numbook(string ID2)
{
    fstream file;
    int num=0;
    file.open("connect.dat",ios::in);
    while(!file.eof())
    {
        string ID1,book1;
        file>>ID1>>book1;
        if(ID1==ID2) num++;
    }
    file.close();
    return num++;
}
void Student::returnbook(string a[])
{
    fstream file;
    int i=0;
    file.open("connect.dat",ios::in);
    while(!file.eof())
    {
        string ID1,book1;
        file>>ID1>>book1;
		if(ID1==this->ID) a[i++]=book1;
    }
    file.close();
}
