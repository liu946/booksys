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
CBook CBookMangement::BookDateSearch(int year, int month, int day)
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
	cout << "没有找到！" << endl;
	exit(0);
}
CBook CBookMangement::BookNameSearch(string name)
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
	cout << "没有找到！" << endl;
	exit(0);
}
CBook CBookMangement::BookIDSearch(long ID)
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
	cout << "没有找到！" << endl;
	exit(0);
}