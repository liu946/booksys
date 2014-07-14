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
public:
	void AddBookInformation(string name, long id, int total, int curnum, int year, int month, int day);
	CBook BookDateSearch(bool &end,int year, int month, int day);
	CBook BookNameSearch(bool &end,string name);
	CBook BookIDSearch(bool &end,long a);
	void BookReturn(bool &end, long ID);
	void BookDelete(bool &end, long ID);
	void BookSent(bool &end, long ID);
};