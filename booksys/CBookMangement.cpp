/*! @file
/****************************************************************************** **
模块名       : CBookMangement 类定义文件
文件名       : CBookMangement.cpp
相关文件     : CBookMangement.h
文件实现功能 : CBookMangement 类中函数及数据的定义
作者         : 蒋金文
版本         : 2.0
--------------------------------------------------------------------------------
备注         : <其它说明>
--------------------------------------------------------------------------------
修改记录 :
日 期        版本     修改人              修改内容
2014/07/9    1.0      蒋金文              创建
2014/07/15   2.0      蒋金文              添加函数
*******************************************************************************
*/
#include "stdafx.h"
#include "CBook.h"
#include "CBookMangement.h"
#include <string>
using namespace std;
void CBookMangement::AddBookInformation(string name, long ID, int allnum, int nownum, int year, int month, int day)
{
	fstream bookinformation;
	bookinformation.open("BookInformation.txt", ios::out | ios::app);
	bookinformation << name << '	';
	bookinformation << ID << '	';
	bookinformation << allnum << '	';
	bookinformation << nownum << '	';
	bookinformation << year << '	';
	bookinformation << month << '	';
	bookinformation << day << endl;
	bookinformation.close();
}
void CBookMangement::BookDateSearch(int year, int month, int day, CBook *bookDate,int anum)
{
	int num = 0;
	fstream bookinformation;
	bookinformation.open("BookInformation.txt", ios::in);
	for (int k = 0; k < anum; k++)
	{
		string a;
		long b;
		int c, d, x, y, z;
		bookinformation >> a >> b >> c >> d >> x >> y >> z;
		if (x == year && y==month && z==day)
		{
			bookDate[num].SetbookName(a);
			bookDate[num].SetbookID(b);
			bookDate[num].SetbookAllNumber(c);
			bookDate[num].SetbookNowNumber(d);
			bookDate[num].SetbookDate(x, y, z);
			num++;
		}
	}
	bookinformation.close();
}
void CBookMangement::BookNameSearch(string name, CBook *bookName,int anum)
{
	int num = 0;
	fstream bookinformation;
	bookinformation.open("BookInformation.txt", ios::in);
	for (int i = 0; i < anum;i++)
	{
		string a;
		long b;
		int c, d, x, y, z;
		bookinformation >> a >> b >> c >> d >> x >> y >> z;
		if (a == name)
		{
			bookName[num].SetbookName(a);
			bookName[num].SetbookID(b);
			bookName[num].SetbookAllNumber(c);
			bookName[num].SetbookNowNumber(d);
			bookName[num].SetbookDate(x, y, z);
			num++;
		}
	}
	bookinformation.close();
}
void CBookMangement::BookIDSearch(long ID, CBook *bookID,int anum)
{
	int i = 0;
	fstream bookinformation;
	bookinformation.open("BookInformation.txt", ios::in);
	for (int t = 0; t < anum;t++)
	{
		string a;
		long b;
		int c, d, x, y, z;
		bookinformation >> a >> b >> c >> d >> x >> y >> z;
		if (b == ID)
		{
			bookID[i].SetbookName(a);
			bookID[i].SetbookID(b);
			bookID[i].SetbookAllNumber(c);
			bookID[i].SetbookNowNumber(d);
			bookID[i].SetbookDate(x, y, z);
			i++;
		}
	}
	bookinformation.close();
}
void CBookMangement::BookReturn(long ID,int num)
{
	fstream book,book1;
	book.open("BookInformation.txt", ios::in);
	book1.open("booknew.txt", ios::out);
	for (int i = 0; i < num; i++)
	{
		string a;
		long b;
		int c, d, x, y, z;
		book >> a >> b >> c >> d >> x >> y >> z;
		if (b == ID)
		{
			d++;
		}
		book1 << a << " " << b << " " << c << " " << d << " " << x << " " << y << " " << z << endl;
	}
	book.close();
	book1.close();
	fstream book2, book3;
	book2.open("BookInformation.txt", ios::out);
	book3.open("booknew.txt", ios::in);
	for (int i = 0; i < num; i++)
	{
		string a;
		long b;
		int c, d, x, y, z;
		book3 >> a >> b >> c >> d >> x >> y >> z;
		book2 << a << " " << b << " " << c << " " << d << " " << x << " " << y << " " << z << endl;
	}
	book2.close();
	book3.close();
}

void CBookMangement::BookDelete(long ID,int t,int num)
{
	fstream book, book1;
	book.open("BookInformation.txt", ios::in);
	book1.open("booknew.txt", ios::out);
	for (int i = 0; i < num;i++)
	{
		string a;
		long b;
		int c, d, x, y, z;
		book >> a >> b >> c >> d >> x >> y >> z;
		if (b != ID)
		{
			book1 << a << " " << b << " " << c << " " << d << " " << x << " " << y << " " << z << endl;
		}
	}
	book.close();
	book1.close();
	fstream book2, book3;
	book2.open("BookInformation.txt", ios::out);
	book3.open("booknew.txt", ios::in);
	for (int i = 0; i < (num-t); i++)
	{
		string a;
		long b;
		int c, d, x, y, z;
		book3 >> a >> b >> c >> d >> x >> y >> z;
		book2 << a << " " << b << " " << c << " " << d << " " << x << " " << y << " " << z << endl;
	}
	book2.close();
	book3.close();
}
void CBookMangement::BookSent(long ID,int num)
{
	fstream book, book1;
	book.open("BookInformation.txt", ios::in);
	book1.open("booknew.txt", ios::out);
	string a,a1;
	long b,b1;
	int c, c1, d, d1, x, x1, y, y1, z, z1;
	for (int i = 0; i < num; i++)
	{
		book >> a >> b >> c >> d >> x >> y >> z;
		if (b == ID)
		{
			d--;
		}
		book1 << a << " " << b << " " << c << " " << d << " " << x << " " << y << " " << z << endl;
	}
	book.close();
	book1.close();
	fstream book2, book3;
	book2.open("BookInformation.txt", ios::out);
	book3.open("booknew.txt", ios::in);
	for (int i = 0; i < num; i++)
	{
		book3 >> a1 >> b1 >> c1 >> d1 >> x1 >> y1 >> z1;
		book2 << a1 << " " << b1 << " " << c1 << " " << d1 << " " << x1 << " " << y1 << " " << z1 << endl;
	}
	book2.close();
	book3.close();
}
int CBookMangement::IDNumber(long ID,int num)
{
	int t=0;
	fstream book;
	book.open("BookInformation.txt", ios::in);
	string a;
	long b;
	int c, d, x, y, z;
	for (int i = 0; i < num; i++)
	{
		book >> a >> b >> c >> d >> x >> y >> z;
		if (b == ID) {t++; }
	}
	book.close();
	return t;
}
int CBookMangement::NameNumber(string name,int num)
{
	int t = 0;
	fstream book;
	book.open("BookInformation.txt", ios::in);
	string a;
	long b;
	int c, d, x, y, z;
	for (int i = 0; i < num; i++)
	{
		book >> a >> b >> c >> d >> x >> y >> z;
		if (a == name) { t++; }
	}
	book.close();
	return t;
}
int CBookMangement::DateNumber(int year, int month, int day,int num)
{
	int t = 0;
	fstream book;
	book.open("BookInformation.txt", ios::in);
	string a;
	long b;
	int c, d, x, y, z;
	for (int i = 0; i < num;i++)
	{
		book >> a >> b >> c >> d >> x >> y >> z;
		if (x == year && y==month && z==day) { t++; }
	}
	book.close();
	return t;
}
void CBookMangement::ShowAllNumber(CBook *Book,int num)
{
	fstream bookinformation;
	bookinformation.open("BookInformation.txt", ios::in);
	for (int i = 0; i < num;i++)
	{
		string a;
		long b;
		int c, d, x, y, z;
		bookinformation >> a >> b >> c >> d >> x >> y >> z;
		Book[i].SetbookName(a);
		Book[i].SetbookID(b);
		Book[i].SetbookAllNumber(c);
		Book[i].SetbookNowNumber(d);
		Book[i].SetbookDate(x, y, z);
	}
	bookinformation.close();
}
int CBookMangement::AllNumber()
{
	int num = 0;
	fstream book;
	book.open("BookInformation.txt", ios::in);
	while (!book.eof())
	{
		string a;
		long b;
		int c, d, x, y, z;
		book >> a >> b >> c >> d >> x >> y >> z;
		num++;
	}
	book.close();
	return (num-1);
}
//还原
void CBookMangement::BackUp(int num,string fname)
{
	fstream book2, book3;
	book2.open("BookInformation.txt", ios::out);
	book3.open(fname, ios::in);
	for (int i=0;i<num;i++)
	{
		string a;
		long b;
		int c, d, x, y, z;
		book3 >> a >> b >> c >> d >> x >> y >> z;
		book2 << a << " " << b << " " << c << " " << d << " " << x << " " << y << " " << z << endl;
	}
	book2.close();
	book3.close();
}
//备份
void CBookMangement::RollUp(int num,string fname)
{
	fstream book, book1;
	book.open("BookInformation.txt", ios::in);
	book1.open(fname, ios::out);
	for (int i = 0; i < num;i++)
	{
		string a;
		long b;
		int c, d, x, y, z;
		book >> a >> b >> c >> d >> x >> y >> z;
		book1 << a << " " << b << " " << c << " " << d << " " << x << " " << y << " " << z << endl;
	}
	book.close();
	book1.close();
}
int CBookMangement::ALLNumberNEW(string fname)
{
	int num = 0;
	fstream book;
	book.open(fname, ios::in);
	while (!book.eof())
	{
		string a;
		long b;
		int c, d, x, y, z;
		book >> a >> b >> c >> d >> x >> y >> z;
		num++;
	}
	book.close();
	return (num-1);
}