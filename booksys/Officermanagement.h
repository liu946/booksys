#pragma once
#include <string>
#include "Officer.h"
using namespace std;
class Officermanagement
{
public:
	 fstream file;
	 string findname;
     bool check1(string ID2);
     void add1(string ID1,string password1,string name1);
     void finds(string name2);
	 Officer show(bool &x);
	 Officer nextname(bool &y);
	 Officer nextid(bool &z);
     void modify(string ID2,string password2,string name2,string sex2,string age2);
     void delet(string ID2);
     bool comp(string a,string b);
	 bool comp(int a,int b);
     void mysort(bool flag=true);
	 void backup(string filename);
	 bool rollback(string ID2,string filename);
	 Officer IDfind(string);
	 void rollback1(string filename);

};
