#include "StdAfx.h"
#include "Officermanagement.h"
#include <algorithm>
#include <string>
#include<stdlib.h>
using namespace std;
bool Officermanagement::comp(string a,string b)
{
	return a < b;
}
bool Officermanagement::comp(int a,int b)
{
	return a<b;
}
//排序函数
void Officermanagement::mysort(bool flag)
{
    Officer c[1000];
    int i=0;
    fstream fileOfficer;
    fileOfficer.open("Officer.dat",ios::in);
    while(!fileOfficer.eof())
    {
        string ID1,password1,name1,sex1,book1;
        string age1;
        fileOfficer>>ID1;
		if(ID1=="")break;
		fileOfficer>>password1>>name1>>sex1>>age1>>book1;
        c[i].getID(ID1);
        c[i].getpassword(password1);
        c[i].getname(name1);
        c[i].getsex(sex1);
        c[i].getage(age1);
        c[i].getbook(book1);
        i++;
    }
    fileOfficer.close();
    if(flag==true)
    {
        for(int j=0;j<i;j++)
        {
            Officer min1=c[j];
            int l=j;
            for(int k=j;k<i;k++)
            {
                if(comp(min1.sentname(),c[k].sentname()))
                {
                    min1=c[k];
                    l=k;
                }
            }
            Officer tmp;
            tmp=c[j];
            c[j]=c[l];
            c[l]=tmp;
        }
        fileOfficer.open("officer.dat",ios::out);
        for(int j=0;j<i;j++)
        {
            fileOfficer<<c[j].sentID()<<' '<<c[j].sentpassword()<<' '<<c[j].sentname()<<' '<<c[j].sentsex()<<' '<<c[j].sentage()<<' '<<c[j].sentbook()<<endl;
        }
        fileOfficer.close();
    }
    else
    {
        for(int j=0;j<i;j++)
        {
            Officer min1=c[j];
            int l=j;
            for(int k=j;k<i;k++)
            {
                if(comp(atoi(min1.sentage().c_str()),atoi(c[k].sentage().c_str())))
                {
                    min1=c[k];
                    l=k;
                }
            }
            Officer tmp;
            tmp=c[j];
            c[j]=c[l];
            c[l]=tmp;
        }
        fileOfficer.open("Officer.dat",ios::out);
        for(int j=0;j<i;j++)
        {
            fileOfficer<<c[j].sentID()<<' '<<c[j].sentpassword()<<' '<<c[j].sentname()<<' '<<c[j].sentsex()<<' '<<c[j].sentage()<<' '<<c[j].sentbook()<<endl;
        }
        fileOfficer.close();
    }

}
//检查是否纯在
bool Officermanagement::check1(string ID2)
{
    fstream fileOfficer;

    fileOfficer.open("Officer.dat",ios::in);
	if(!fileOfficer)return true;
    {
        string ID1,password1,name1,sex1,book1;
        string age1;
        while(!fileOfficer.eof())
        {
            fileOfficer>>ID1>>password1>>name1>>sex1>>age1>>book1;
            if(ID2==ID1)
                return false;
        }

    }
    fileOfficer.close();
    return true;
}

//添加一人函数
void Officermanagement::add1(string ID1,string password1,string name1)
{
    Officer a;
    a.getID(ID1);
    a.getpassword(password1);
    a.getname(name1);
    fstream fileOfficer;
    fileOfficer.open("Officer.dat",ios::out|ios::app);
    fileOfficer<<a.sentID()<<' '<<a.sentpassword()<<' '<<a.sentname()<<' '<<a.sentsex()<<' '<<a.sentage()<<' '<<a.sentbook()<<endl;
    fileOfficer.close();
}
//显示函数
Officer Officermanagement::show(bool &x)
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
        Officer a;
        a.getID(ID1);
        a.getpassword(password1);
        a.getname(name1);
        a.getsex(sex1);
        a.getage(age1);
        a.getbook(book1);
        return a;
    }
	file.close();
	Officer b;
	return b;
}
//查找函数
void Officermanagement::finds(string name2)
{
    file.open("Officer.dat",ios::in);
    findname=name2;
}
Officer Officermanagement::nextname(bool &y)
{
	if(!file){file.close();	Officer b;return b;}
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
            Officer a;
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
	Officer b;
    return b;
}
Officer Officermanagement::nextid(bool &z)
{
	if(!file){file.close();	Officer b;return b;}
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
            Officer a;
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
	Officer b;
    return b;
}
//修改函数
void Officermanagement::modify(string ID2,string password2,string name2,string sex2,string age2)
{
    fstream fileOfficer1,fileOfficer2;
    fileOfficer1.open("Officer.dat",ios::in);
    fileOfficer2.open("Officer1.dat",ios::out);
    while(!fileOfficer1.eof())
    {
        string ID1,password1,name1,sex1,book1;
        string age1;
        fileOfficer1>>ID1>>password1>>name1>>sex1>>age1>>book1;
        if(ID1==ID2)
        fileOfficer2<<ID2<<' '<<password2<<' '<<name2<<' '<<sex2<<' '<<age2<<' '<<book1<<endl;
        else
        fileOfficer2<<ID1<<' '<<password1<<' '<<name1<<' '<<sex1<<' '<<age1<<' '<<book1<<endl;
    }
    fileOfficer1.close();
    fileOfficer2.close();
    fileOfficer1.open("Officer.dat",ios::out);
    fileOfficer2.open("Officer1.dat",ios::in);
    while(!fileOfficer2.eof())
    {
        string ID1,password1,name1,sex1,book1,age1;
        fileOfficer2>>ID1>>password1>>name1>>sex1>>age1>>book1;
        fileOfficer1<<ID1<<' '<<password1<<' '<<name1<<' '<<sex1<<' '<<age1<<' '<<book1<<endl;
    }
    fileOfficer1.close();
    fileOfficer2.close();
}
//删除函数
void Officermanagement::delet(string ID2)
{
    fstream fileOfficer1,fileOfficer2;
    fileOfficer1.open("Officer.dat",ios::in);
    fileOfficer2.open("Officer1.dat",ios::out);
    while(!fileOfficer1.eof())
    {
        string ID1,password1,name1,sex1,book1;
        string age1;
        fileOfficer1>>ID1>>password1>>name1>>sex1>>age1>>book1;
        if(ID1!=ID2)
        fileOfficer2<<ID1<<' '<<password1<<' '<<name1<<' '<<sex1<<' '<<age1<<' '<<book1<<endl;
    }
    fileOfficer1.close();
    fileOfficer2.close();
    fileOfficer1.open("Officer.dat",ios::out);
    fileOfficer2.open("Officer1.dat",ios::in);
    while(!fileOfficer2.eof())
    {
		string ID1,password1,name1,sex1,book1;
        string age1;
        fileOfficer2>>ID1>>password1>>name1>>sex1>>age1>>book1;
        fileOfficer1<<ID1<<' '<<password1<<' '<<name1<<' '<<sex1<<' '<<age1<<' '<<book1<<endl;
        //filestudent1<<filestudent2<<' '<<filestudent2<<' '<<filestudent2<<' '<<filestudent2<<' '<<filestudent2<<' '<<filestudent2<<endl;
    }
    fileOfficer1.close();
    fileOfficer2.close();
}
//备份函数
void Officermanagement::backup(string filename)
{
    fstream fileOfficer1,fileOfficer2;
    fileOfficer1.open("Officer.dat",ios::in);
    fileOfficer2.open(filename,ios::out);
    while(!fileOfficer1.eof())
    {
       string ID1,password1,name1,sex1,age1,book1;
       fileOfficer1>>ID1>>password1>>name1>>sex1>>age1>>book1;
       fileOfficer2<<ID1<<' '<<password1<<' '<<name1<<' '<<sex1<<' '<<age1<<' '<<book1<<endl;
    }
    fileOfficer1.close();
    fileOfficer2.close();
}

//还原函数
bool Officermanagement::rollback(string ID2,string filename)
{
    fstream fileOfficer1,fileOfficer2;
    bool x1=false;
    fileOfficer1.open(filename,ios::in);
    fileOfficer2.open("Officer.dat",ios::out&ios::app);
    while(!fileOfficer1.eof())
    {
        string ID1,password1,name1,sex1,age1,book1;
        fileOfficer1>>ID1>>password1>>name1>>sex1>>age1>>book1;
        if(ID1==ID2)
        {
            fileOfficer2<<ID1<<' '<<password1<<' '<<name1<<' '<<sex1<<' '<<age1<<' '<<book1<<endl;
            x1=true;
        }
    }
    fileOfficer1.close();
    fileOfficer2.close();
    return x1;
}

Officer Officermanagement::IDfind(string ID2)
{
    fstream fileOfficer;
    fileOfficer.open("Officer.dat",ios::in);
    while(!fileOfficer.eof())
    {
        string ID1,password1,name1,sex1,book1;
        string age1;
        fileOfficer>>ID1>>password1>>name1>>sex1>>age1>>book1;
        if(ID2==ID1)
        {
            Officer a;
            a.getID(ID1);
            a.getpassword(password1);
            a.getname(name1);
            a.getsex(sex1);
            a.getage(age1);
            a.getbook(book1);
            return a;
        }
    }
	Officer b;
    return b;
}
void Officermanagement::rollback1(string filename)
{
    fstream filestudent1,filestudent2;
    filestudent1.open(filename,ios::in);
    filestudent2.open("Officer.dat",ios::out);
    while(!filestudent1.eof())
    {
        string ID1,password1,name1,sex1,age1,book1;
        filestudent1>>ID1>>password1>>name1>>sex1>>age1>>book1;
        filestudent2<<ID1<<' '<<password1<<' '<<name1<<' '<<sex1<<' '<<age1<<' '<<book1<<endl;
    }
    filestudent1.close();
    filestudent2.close();
}
