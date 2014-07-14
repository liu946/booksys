#include "StdAfx.h"
#include "Studentmanagement.h"
#include <algorithm>
#include <string>
using namespace std;
bool Studentmanagement::comp(string a,string b)
{
	return a < b;
}
bool Studentmanagement::sortage(Student a,Student b)
{
	return comp(a.sentage(),b.sentage());
}
bool Studentmanagement::sortname(Student a,Student b)
{
	return comp(a.sentname(),b.sentname());
}
//排序函数
void Studentmanagement::mysort(bool flag)
{
    Student c[1000];
    int i=0;
    fstream fileStudent;
    fileStudent.open("Student.dat",ios::in);
    while(!fileStudent.eof())
    {
        string ID1,password1,name1,sex1,book1;
        string age1;
        fileStudent>>ID1;
		if(ID1=="")break;
		fileStudent>>password1>>name1>>sex1>>age1>>book1;
        c[i].getID(ID1);
        c[i].getpassword(password1);
        c[i].getname(name1);
        c[i].getsex(sex1);
        c[i].getage(age1);
        c[i].getbook(book1);
        i++;
    }
    fileStudent.close();
    if(flag==true)
    {
        //std::sort(c,c+i,sortname);
        fileStudent.open("student.dat",ios::out);
        for(int j=0;j<i;j++)
        {
            fileStudent<<c[j].sentID()<<' '<<c[j].sentpassword()<<' '<<c[j].sentname()<<' '<<c[j].sentsex()<<' '<<c[j].sentage()<<' '<<c[j].sentbook()<<endl;
        }
        fileStudent.close();
    }
    else
    {
       // sort(c,c+i,sortage);
        fileStudent.open("student.dat",ios::out);
        for(int j=0;j<i;j++)
        {
            fileStudent<<c[j].sentID()<<' '<<c[j].sentpassword()<<' '<<c[j].sentname()<<' '<<c[j].sentsex()<<' '<<c[j].sentage()<<' '<<c[j].sentbook()<<endl;
        }
        fileStudent.close();
    }

}
//添加多人函数
/*void Studentmanagement::add(int n)
{
    Student *p=NULL;
    p = new Student[n];
    for(int i=0;i<n;i++)
    {
        string ID1,password1,name1,sex1,book1;
        int age1;
        cin>>ID1>>password1>>name1>>sex1>>age1>>book1;
        p[i].getID(ID1);
        p[i].getpassword(password1);
        p[i].getname(name1);
        p[i].getsex(sex1);
        p[i].getage(age1);
        p[i].getbook(book1);
    }
    fstream fileStudent;
    fileStudent.open("Student.dat",ios::out|ios::app);
    for(int i=0;i<n;i++)
    fileStudent<<p[i].sentID()<<' '<<p[i].sentpassword()<<' '<<p[i].sentname()<<' '<<p[i].sentsex()<<' '<<p[i].sentage()<<' '<<p[i].sentbook()<<' '<<p[i].sentxx()<<endl;
    fileStudent.close();
}*/
//检查是否纯在
bool Studentmanagement::check1(string ID2)
{
    fstream filestudent;
	
    filestudent.open("student.dat",ios::in);
	if(!filestudent)return true;
    {
        string ID1,password1,name1,sex1,book1;
        int age1;
        while(!filestudent.eof())
        {
            filestudent>>ID1>>password1>>name1>>sex1>>age1>>book1;
            if(ID2==ID1)
                return false;
        }

    }
    filestudent.close();
    return true;
}

//添加一人函数
void Studentmanagement::add1(string ID1,string password1,string name1)
{
    Student a;
    a.getID(ID1);
    a.getpassword(password1);
    a.getname(name1);
    fstream fileStudent;
    fileStudent.open("Student.dat",ios::out|ios::app);
    fileStudent<<a.sentID()<<' '<<a.sentpassword()<<' '<<a.sentname()<<' '<<a.sentsex()<<' '<<a.sentage()<<' '<<a.sentbook()<<endl;
    fileStudent.close();
}
//显示函数
Student Studentmanagement::show(bool &x)
{
    if(file.eof())
    {
        x=false;
    }
    else
    {
        string ID1,password1,name1,sex1,book1;
        string age1;
        file>>ID1>>password1>>name1>>sex1>>age1>>book1;
        Student a;
        a.getID(ID1);
        a.getpassword(password1);
        a.getname(name1);
        a.getsex(sex1);
        a.getage(age1);
        a.getbook(book1);
        return a;
    }
	file.close();
	Student b;
	return b;
}
//查找函数
void Studentmanagement::finds(string name2)
{
    file.open("student.dat",ios::in);
    findname=name2;
}
Student Studentmanagement::nextname(bool &y)
{
	if(!file){file.close();	Student b;return b;}
    if(file.eof())
    {
        y=false;
    }
    else
    {
        string ID1,password1,name1,sex1,book1;
        string age1;
        file>>ID1>>password1>>name1>>sex1>>age1>>book1;
        if(findname==name1)
        {
            y=true;
            Student a;
            a.getID(ID1);
            a.getpassword(password1);
            a.getname(name1);
            a.getsex(sex1);
            a.getage(age1);
            a.getbook(book1);
            return a;
        }
        else return nextname(y);
    }
	file.close();
	Student b;
    return b;
}
Student Studentmanagement::nextid(bool &z)
{
	if(!file){file.close();	Student b;return b;}
    if(file.eof())
    {
        z=false;
    }
    else
    {
        string ID1,password1,name1,sex1,book1;
        string age1;
        file>>ID1>>password1>>name1>>sex1>>age1>>book1;
        if(ID1==findname)
        {
            z=true;
            Student a;
            a.getID(ID1);
            a.getpassword(password1);
            a.getname(name1);
            a.getsex(sex1);
            a.getage(age1);
            a.getbook(book1);
            return a;
        }
        else return nextid(z);
    }
	file.close();
	Student b;
    return b;
}
//修改函数
void Studentmanagement::modify(string ID2,string password2,string name2,string sex2,string age2)
{
    fstream filestudent1,filestudent2;
    filestudent1.open("student.dat",ios::in);
    filestudent2.open("student1.dat",ios::out);
    while(!filestudent1.eof())
    {
        string ID1,password1,name1,sex1,book1;
        string age1;
        filestudent1>>ID1>>password1>>name1>>sex1>>age1>>book1;
        if(ID1==ID2)
        filestudent2<<ID2<<' '<<password2<<' '<<name2<<' '<<sex2<<' '<<age2<<' '<<book1<<endl;
        else
        filestudent2<<ID1<<' '<<password1<<' '<<name1<<' '<<sex1<<' '<<age1<<' '<<book1<<endl;
    }
    filestudent1.close();
    filestudent2.close();
    filestudent1.open("student.dat",ios::out);
    filestudent2.open("student1.dat",ios::in);
    while(!filestudent2.eof())
    {
        string ID1,password1,name1,sex1,book1,age1;
        filestudent2>>ID1>>password1>>name1>>sex1>>age1>>book1;
        filestudent1<<ID1<<' '<<password1<<' '<<name1<<' '<<sex1<<' '<<age1<<' '<<book1<<endl;
    }
    filestudent1.close();
    filestudent2.close();
}
//删除函数
void Studentmanagement::delet(string ID2)
{
    fstream filestudent1,filestudent2;
    filestudent1.open("student.dat",ios::in);
    filestudent2.open("student1.dat",ios::out);
    while(!filestudent1.eof())
    {
        string ID1,password1,name1,sex1,book1;
        string age1;
        filestudent1>>ID1>>password1>>name1>>sex1>>age1>>book1;
        if(ID1!=ID2)
        filestudent2<<ID1<<' '<<password1<<' '<<name1<<' '<<sex1<<' '<<age1<<' '<<book1<<endl;
    }
    filestudent1.close();
    filestudent2.close();
    filestudent1.open("student.dat",ios::out);
    filestudent2.open("student1.dat",ios::in);
    while(!filestudent2.eof())
    {
		string ID1,password1,name1,sex1,book1;
        string age1;
        filestudent2>>ID1>>password1>>name1>>sex1>>age1>>book1;
        filestudent1<<ID1<<' '<<password1<<' '<<name1<<' '<<sex1<<' '<<age1<<' '<<book1<<endl;
        //filestudent1<<filestudent2<<' '<<filestudent2<<' '<<filestudent2<<' '<<filestudent2<<' '<<filestudent2<<' '<<filestudent2<<endl;
    }
    filestudent1.close();
    filestudent2.close();
}
//备份函数
void Studentmanagement::backup(string filename)
{
    fstream filestudent1,filestudent2;
    filestudent1.open("student.dat",ios::in);
    filestudent2.open(filename,ios::out);
    while(!filestudent1.eof())
    {
       string ID1,password1,name1,sex1,age1,book1;
       filestudent1>>ID1>>password1>>name1>>sex1>>age1>>book1;
       filestudent2<<ID1<<' '<<password1<<' '<<name1<<' '<<sex1<<' '<<age1<<' '<<book1<<endl;
    }
    filestudent1.close();
    filestudent2.close();
}

//还原函数
bool Studentmanagement::rollback(string ID2,string filename)
{
    fstream filestudent1,filestudent2;
    bool x1=false;
    filestudent1.open(filename,ios::in);
    filestudent2.open("student.dat",ios::out&ios::app);
    while(!filestudent1.eof())
    {
        string ID1,password1,name1,sex1,age1,book1;
        filestudent1>>ID1>>password1>>name1>>sex1>>age1>>book1;
        if(ID1==ID2)
        {
            filestudent2<<ID1<<' '<<password1<<' '<<name1<<' '<<sex1<<' '<<age1<<' '<<book1<<endl;
            x1=true;
        }
    }
    filestudent1.close();
    filestudent2.close();
    return x1;
}

Student Studentmanagement::IDfind(string ID2)
{
    fstream filestudent;
    filestudent.open("student.dat",ios::in);
    while(!filestudent.eof())
    {
        string ID1,password1,name1,sex1,book1;
        string age1;
        filestudent>>ID1>>password1>>name1>>sex1>>age1>>book1;
        if(ID2==ID1)
        {
            Student a;
            a.getID(ID1);
            a.getpassword(password1);
            a.getname(name1);
            a.getsex(sex1);
            a.getage(age1);
            a.getbook(book1);
            return a;
        }
    }
	Student b;
    return b;
}
