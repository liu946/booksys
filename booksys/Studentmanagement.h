#pragma once
#include <string>
#include "Student.h"
using namespace std;
class Studentmanagement
{
public:
	static fstream file;
	static string findname;
    static bool check1(string ID2);
    //static void add(int n);
    static void add1(string ID1,string password1,string name1);
    static void finds(string name2);
	static Student *show(bool &x);
	static Student *nextname(bool &y);
	static Student *nextid(bool &z);
    static void modify(string ID2,string password2,string name2,string sex2,int age2,string book2);
    static void delet(string ID2);
    static bool comp(string a,string b);
    static bool comp(int a,int b);
    static bool sortage(Student a,Student b);
    static bool sortname(Student a,Student b);
    static void mysort(int flag=1);
	static void backup();
	static void rollback(string ID2);
};
