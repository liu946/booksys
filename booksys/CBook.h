#include "stdafx.h"
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
#ifndef CBOOK
#define CBOOK 1
typedef struct Date1
{
	int year;
	int month;
	int day;
}Date;

class CBook
{
private:
	string bookName;
	long bookID;
	int bookAllNumber;
	int bookNowNumber;
	Date bookDate;
public:
	CBook(string a, long b, int c, int d, int x, int y, int z);
	CBook();
	void SetbookName(string x);
	void SetbookID(int x);
	void SetbookAllNumber(int x);
	void SetbookNowNumber(int x);
	void SetbookDate(int x, int y, int z);
	string GetbookName();
	long GetbookID();
	int GetbookAllNumber();
	int GetbookNowNumber();
	int GetbookDateyear();
	int GetbookDatemonth();
	int GetbookDateday();
	void AddbookNumber();
	void DebookNumber();
};
#endif