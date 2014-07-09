//#include "StdAfx.h"
#include "Studentmanagement.h"
#include "Person.h"
#include <string>
/*bool Studentmanagement::comp(string a,string b)
{
	return a < b;
}
bool Studentmanagement::comp(int a,int b)
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
}*/
//排序函数
/*void Studentmanagement::mysort(int flag)
{
    Student c[10000];
    int i=0;
    fstream fileStudent;
    fileStudent.open("Student,dat",ios::in)
    {
        fileStudent>>
    }
    while()
    if(flag)

}*/
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
    {
        string ID1,password1,name1,sex1,book1;
        long long id1;
        int age1;
        bool xx1;
        while(!filestudent.eof())
        {
            filestudent>>ID1>>password1>>name1>>sex1>>age1>>book1>>xx1;
            if(ID2==ID1&&xx1==true)
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
    fileStudent<<a.sentID()<<' '<<a.sentpassword()<<' '<<a.sentname()<<' '<<a.sentsex()<<' '<<a.sentage()<<' '<<a.sentbook()<<' '<<a.sentxx()<<endl;
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
        int age1;
        bool xx1;
        file>>ID1>>password1>>name1>>sex1>>age1>>book1>>xx1;
        Student a;
        a.getID(ID1);
        a.getpassword(password1);
        a.getname(name1);
        a.getsex(sex1);
        a.getage(age1);
        a.getbook(book1);
        a.getxx(xx1);
        return a;
    }
}
//查找函数
void Studentmanagement::finds(string name2)
{
    file.open("student.dat",ios::in);
    findname=name2;
}
Student Studentmanagement::nextname(bool &y)
{
    if(file.eof())
    {
        y=false;
    }
    else
    {
        string ID1,password1,name1,sex1,book1;
        int age1;
        bool xx1;
        file>>ID1>>password1>>name1>>sex1>>age1>>book1>>xx1;
        if(findname==name1&&xx1==1)
        {
            y=true;
            Student a;
            a.getID(ID1);
            a.getpassword(password1);
            a.getname(name1);
            a.getsex(sex1);
            a.getage(age1);
            a.getbook(book1);
            a.getxx(xx1);
            return a;
        }
        else return nextname(y);
    }
}
Student Studentmanagement::nextid(bool &z)
{
    fstream filestudent;
    filestudent.open("student.dat",ios::in);
    while(!filestudent.eof())
    {
        string ID1,password1,name1,sex1,book1;
        int age1;
        bool xx1;
        filestudent>>ID1>>password1>>name1>>sex1>>age1>>book1>>xx1;
        if(findname==ID1&&xx1==1)
        {
            z=true;
            Student a;
            a.getID(ID1);
            a.getpassword(password1);
            a.getname(name1);
            a.getsex(sex1);
            a.getage(age1);
            a.getbook(book1);
            a.getxx(xx1);
            return a;
        }
    }
    z=false;
}

