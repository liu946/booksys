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
    //void add(int n);
    static void add1(string ID1,string password1,string name1);
    static void finds(string name2);
	static Student *show(bool &x);
	static Student nextname(bool &y);
	static Student nextid(bool &z);
    /**void modify(string name2,string sex2,int age2);
    void delet(string name2,string sex2,int age2);
    bool comp(string a,string b);
    bool comp(int a,int b);
    bool sortage(Student a,Student b);
    bool sortname(Student a,Student b);
    void mysort(int flag=1);*/
};
