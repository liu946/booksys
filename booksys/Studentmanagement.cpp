#include "StdAfx.h"
#include "Studentmanagement.h"
#include <string>
bool Studentmanagement::comp(string a,string b)
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
}
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
void Studentmanagement::add(int n)
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
}
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
    fileStudent<<a.sentID()<<' '<<a.sentpassword()<<' '<<a.sentname()<<' '<<a.sentsex()<<' '<<a.sentage()<<' '<<a.sentbook()<<' '<<a.sentxx()<<endl;
    fileStudent.close();
}
//显示函数
void Studentmanagement::show()
{
    fstream fileStudent;
    fileStudent.open("Student.dat",ios::in);
    while(!fileStudent.eof())
    {
        string ID1,password1,name1,sex1,book1;
        long long id1;
        int age1;
        bool xx1;
        fileStudent>>ID1>>password1>>id1>>name1>>sex1>>age1>>book1>>xx1;
        if(xx1==1)
        cout<<id1<<" "<<name1<<" "<<sex1<<" "<<age1<<" "<<book1<<endl;
    }
    fileStudent.close();
}
//查找函数
void Studentmanagement::finds(string name2)
{
    int flag=0;
    fstream fileStudent;
    fileStudent.open("Student.dat",ios::in);
    while(!fileStudent.eof())
    {
        string ID1,password1,name1,sex1,book1;
        long long id1;
        int age1;
        bool xx1;
        fileStudent>>ID1>>password1>>id1>>name1>>sex1>>age1>>book1>>xx1;
        if(name2==name1&&xx1==1)
        {
            flag=1;
            cout<<id1<<" "<<name1<<" "<<sex1<<" "<<age1<<" "<<book1<<endl;
            break;
        }
    }
    if(flag==0) cout<<"没有找到这个人"<<endl;
}
void Studentmanagement::finds(long long id2)
{
    int flag=0;
    fstream fileStudent;
    fileStudent.open("Student.dat",ios::in);
    while(!fileStudent.eof())
    {
        string ID1,password1,name1,sex1,book1;
        long long id1;
        int age1;
        bool xx1;
        fileStudent>>ID1>>password1>>id1>>name1>>sex1>>age1>>book1>>xx1;
        if(id2==id1&&xx1==1)
        {
            flag=1;
            cout<<id1<<" "<<name1<<" "<<sex1<<" "<<age1<<" "<<book1<<endl;
            break;
        }
    }
    if(flag==0) cout<<"没有找到这个人"<<endl;

}

