// booknew.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*! @file
/****************************************************************************** **
ģ����       : CBook �ඨ���ļ�
�ļ���       : CBook.cpp
����ļ�     : CBook.h
�ļ�ʵ�ֹ��� : CBook ���к��������ݵĶ���
����         : ������
�汾         : 1.0
--------------------------------------------------------------------------------
��ע         : <����˵��>
--------------------------------------------------------------------------------
�޸ļ�¼ :
�� ��        �汾     �޸���              �޸�����
2014/07/9    1.0      ������              ����
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
