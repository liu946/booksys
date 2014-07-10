#include "stdafx.h"
#include "CBookMangement.h"
#include "CBook.h"
#include <string>
using namespace std;
void CBookMangement::AddBookInformation(string a, long b, int c, int d, int x, int y, int z)
{
	fstream bookinformation;
	bookinformation.open("BookInformation.txt", ios::out | ios::app);
	bookinformation << a << '	';
	bookinformation << b << '	';
	bookinformation << c << '	';
	bookinformation << d << '	';
	bookinformation << x << '	';
	bookinformation << y << '	';
	bookinformation << z << endl;
	bookinformation.close();
}
CBook CBookMangement::BookDateSearch(bool &end,int year, int month, int day)
{
	fstream bookinformation;
	bookinformation.open("BookInformation.txt", ios::in);
	while (!bookinformation.eof())
	{
		string a;
		long b;
		int c, d, x, y, z;
		bookinformation >> a >> b >> c >> d >> x >> y >> z;
		if (x == year && y == month && z == day)
		{
			CBook book(a, b, c, d, x, y, z);
			return book;
		}
	}
	end = false;
	CBook booknull("abc", 11111, 1, 1, 1, 1, 1);
	return booknull;
}
CBook CBookMangement::BookNameSearch(bool &end,string name)
{
	fstream bookinformation;
	bookinformation.open("BookInformation.txt", ios::in);
	while (!bookinformation.eof())
	{
		string a;
		long b;
		int c, d, x, y, z;
		bookinformation >> a >> b >> c >> d >> x >> y >> z;
		if (a == name)
		{
			CBook book(a, b, c, d, x, y, z);
			return book;
		}
	}
	end = false;
	CBook booknull("abc", 11111, 1, 1, 1, 1, 1);
	return booknull;
}
CBook CBookMangement::BookIDSearch(bool &end,long ID)
{
	fstream bookinformation;
	bookinformation.open("BookInformation.txt", ios::in);
	while (!bookinformation.eof())
	{
		string a;
		long b;
		int c, d, x, y, z;
		bookinformation >> a >> b >> c >> d >> x >> y >> z;
		if (b == ID)
		{
			CBook book(a, b, c, d, x, y, z);
			return book;
		}
	}
	end = false;
	CBook booknull("abc", 11111, 1, 1, 1, 1, 1);
	return booknull;
}
void BookReturn(bool &end,long ID)
{
	int p = 0;
	fstream book,book1;
	book.open("BookInformation.txt", ios::in);
	book1.open("booknew.txt", ios::out);
	while (!book.eof())
	{
		string a;
		long b;
		int c, d, x, y, z;
		book >> a >> b >> c >> d >> x >> y >> z;
		book1 << a << " " << b << " " << c << " " << d << " " << x << " " << y << " " << z << endl;
		if (b == ID)
		{
			d++;
			p++;
		}
	}
	book.close();
	book1.close();
	fstream book2, book3;
	book2.open("BookInformation.txt", ios::out);
	book3.open("booknew.txt", ios::in);
	while (!book3.eof())
	{
		string a;
		long b;
		int c, d, x, y, z;
		book3 >> a >> b >> c >> d >> x >> y >> z;
		book2 << a << " " << b << " " << c << " " << d << " " << x << " " << y << " " << z << endl;
	}
	book2.close();
	book3.close();
	if (p == 0){ end = false; }
}

void BookDelete(bool &end, long ID)
{
	int p = 0;
	fstream book, book1;
	book.open("BookInformation.txt", ios::in);
	book1.open("booknew.txt", ios::out);
	while (!book.eof())
	{
		string a;
		long b;
		int c, d, x, y, z;
		book >> a >> b >> c >> d >> x >> y >> z;
		if (b != ID)
		{
			book1 << a << " " << b << " " << c << " " << d << " " << x << " " << y << " " << z << endl;
		}
		else { p++; }
	}
	book.close();
	book1.close();
	fstream book2, book3;
	book2.open("BookInformation.txt", ios::out);
	book3.open("booknew.txt", ios::in);
	while (!book3.eof())
	{
		string a;
		long b;
		int c, d, x, y, z;
		book3 >> a >> b >> c >> d >> x >> y >> z;
		book2 << a << " " << b << " " << c << " " << d << " " << x << " " << y << " " << z << endl;
	}
	book2.close();
	book3.close();
	if (p == 0){ end = false; }
}
void BookSent(bool &end, long ID)
{
	int p = 0;
	fstream book, book1;
	book.open("BookInformation.txt", ios::in);
	book1.open("booknew.txt", ios::out);
	while (!book.eof())
	{
		string a;
		long b;
		int c, d, x, y, z;
		book >> a >> b >> c >> d >> x >> y >> z;
		book1 << a << " " << b << " " << c << " " << d << " " << x << " " << y << " " << z << endl;
		if (b == ID)
		{
			d++;
			p++;
		}
	}
	book.close();
	book1.close();
	fstream book2, book3;
	book2.open("BookInformation.txt", ios::out);
	book3.open("booknew.txt", ios::in);
	while (!book3.eof())
	{
		string a;
		long b;
		int c, d, x, y, z;
		book3 >> a >> b >> c >> d >> x >> y >> z;
		book2 << a << " " << b << " " << c << " " << d << " " << x << " " << y << " " << z << endl;
	}
	book2.close();
	book3.close();
	if (p == 0){ end = false; }
}