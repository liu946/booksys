#include "stdafx.h"
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "CBook.h"
using namespace std;
#ifndef CBOOKMANGEMENT
#define CBOOKMANGEMENT 1
class CBookMangement
{
public:
	void AddBookInformation(string name, long ID, int allnum, int nownum, int year, int month, int day);
	void BookNameSearch(string name,CBook *bookName,int anum);
	void BookIDSearch(long a,CBook *bookID,int anum);
	void BookDateSearch(int year, int month, int day, CBook *bookDate,int anum);
	int IDNumber(long ID,int num);
	int NameNumber(string ,int num);
	int DateNumber(int year, int month, int day,int num);
	void BackUp(int num,string fname);
	void RollUp(int num,string fname);
	int AllNumber();
	int ALLNumberNEW(string fname);
	void ShowAllNumber(CBook *Book,int num);
	void BookReturn(long ID,int num);
	void BookDelete(long ID,int t, int num);
	void BookSent(long ID,int num);

};
#endif