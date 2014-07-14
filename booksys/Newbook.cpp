// Newbook.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "booksys.h"
#include "Newbook.h"
#include "afxdialogex.h"
#include <string>
#include <stdlib.h>
using namespace std;

// Newbook �Ի���

IMPLEMENT_DYNAMIC(Newbook, CDialogEx)

Newbook::Newbook(CWnd* pParent /*=NULL*/)
	: CDialogEx(Newbook::IDD, pParent)
{

}

Newbook::~Newbook()
{
}

void Newbook::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NEWBOOKMSG, msg);
	DDX_Control(pDX, IDC_NEWBOOKID, ce_id);
	DDX_Control(pDX, IDC_NEWBOOKNAME, ec_name);
	DDX_Control(pDX, IDC_NEWBOOKNUM, ec_num);
	DDX_Control(pDX, IDC_NEWBOOKYEAR, ec_year);
	DDX_Control(pDX, IDC_NEWBOOKMONTH, ec_month);
	DDX_Control(pDX, IDC_NEWBOOKDAY, ec_day);
}


BEGIN_MESSAGE_MAP(Newbook, CDialogEx)
	ON_BN_CLICKED(IDOK, &Newbook::OnBnClickedOk)
END_MESSAGE_MAP()


// Newbook ��Ϣ�������


void Newbook::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char id[30];
	char name[30];
	char num[30];
	char year[30];
	char day[30];
	char month[30];
	this->ce_id.GetWindowTextA(id,29);
	this->ec_name.GetWindowTextA(name,29);
	this->ec_num.GetWindowTextA(num,29);
	this->ec_year.GetWindowTextA(year,29);
	this->ec_month.GetWindowTextA(month,29);
	this->ec_day.GetWindowTextA(day,29);
	//���Ψһ��
	//to do
	this->bkmgt.AddBookInformation(name,atoi(id),atoi(num),atoi(num),atoi(year),atoi(month),atoi(day));
	string str_msg("�鼮��");
	str_msg+=name;
	str_msg+="������ӣ�";
	this->msg.SetWindowTextA(LPCTSTR(str_msg.c_str()));
}
