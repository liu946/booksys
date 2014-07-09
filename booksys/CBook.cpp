// booknew.cpp : 定义控制台应用程序的入口点。
//
/*! @file
/****************************************************************************** **
模块名       : CBook 类定义文件
文件名       : CBook.cpp
相关文件     : CBook.h
文件实现功能 : CBook 类中函数及数据的定义
作者         : 蒋金文
版本         : 1.0
--------------------------------------------------------------------------------
备注         : <其它说明>
--------------------------------------------------------------------------------
修改记录 :
日 期        版本     修改人              修改内容
2014/07/9    1.0      蒋金文              创建
*******************************************************************************
*/
#include "stdafx.h"
#include "CBook.h"
CBook::CBook(string a, long b, int c, int d, int x, int y, int z)
{
	bookName = a;
	bookID = b;
	bookAllNumber = c;
	bookNowNumber = d;
	bookDate.year = x;
	bookDate.month = y;
	bookDate.day = z;
}
CBook::CBook(){}
void CBook::SetbookName(string x){ bookName = x; }
void CBook::SetbookID(int x){ bookID = x; }
void CBook::SetbookAllNumber(int x){ bookAllNumber = x; }
void CBook::SetbookNowNumber(int x){ bookNowNumber = x; }
void CBook::SetbookDate(int x, int y, int z)
{
	bookDate.year = x;
	bookDate.month = y;
	bookDate.day = z;
}
string CBook::GetbookName(){ return bookName; }
long CBook::GetbookID(){ return bookID; }
int CBook::GetbookAllNumber(){ return bookAllNumber; }
int CBook::GetbookNowNumber(){ return bookNowNumber; }
int CBook::GetbookDateyear(){ return bookDate.year; }
int CBook::GetbookDatemonth(){ return bookDate.month; }
int CBook::GetbookDateday(){ return bookDate.day; }
void CBook::AddbookNumber(){ bookNowNumber++; }
void CBook::DebookNumber(){ bookNowNumber--; }
