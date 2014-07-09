#include "stdafx.h"
#include "CBook.h"
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;
class CBookMangement
{
	/*public:
	CBook book;*/
private:
	void AddBookInformation(string a, long b, int c, int d, int x, int y, int z);
	CBook BookDateSearch(int year, int month, int day);
	CBook BookNameSearch(string name);
	CBook BookIDSearch(long a);
};