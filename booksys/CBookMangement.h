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
	CBook BookDateSearch(bool &end,int year, int month, int day);
	CBook BookNameSearch(bool &end,string name);
	CBook BookIDSearch(bool &end,long a);
	void BookReturn(bool &end, long ID);
	void BookDelete(bool &end, long ID);
	void BookSent(bool &end, long ID);
};