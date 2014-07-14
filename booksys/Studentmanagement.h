#pragma once
#include <string>
#include "Student.h"
using namespace std;
class Studentmanagement
{
public:
	 fstream file;
	 string findname;
     bool check1(string ID2);
    // void add(int n);
     void add1(string ID1,string password1,string name1);
     void finds(string name2);
	Student show(bool &x);
	Student nextname(bool &y);
	Student nextid(bool &z);
     void modify(string ID2,string password2,string name2,string sex2,string age2);
     void delet(string ID2);
     bool comp(string a,string b);
     bool sortage(Student a,Student b);
     bool sortname(Student a,Student b);
     void mysort(bool flag=true);
	 void backup(string filename);
	 bool rollback(string ID2,string filename);
	 Student IDfind(string);
};
