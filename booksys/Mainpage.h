#pragma once
#include "afxwin.h"
#include <string>
#include "Studentmanagement.h"
#include "afxcmn.h"
using namespace std;
// Mainpage �Ի���

class Mainpage : public CDialogEx
{
	DECLARE_DYNAMIC(Mainpage)

public:
	Mainpage(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Mainpage();
	Studentmanagement Stumgt;
	//���ز˵�
	CMenu m_menu;
	//�û�����
	string name;
// �Ի�������
	enum { IDD = IDD_MAINPAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	void clearlist();
	DECLARE_MESSAGE_MAP()
public:
	CEdit search;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void On32780();
	virtual BOOL OnInitDialog();
	//CListBox showlist;
	afx_msg void On32771();
	afx_msg void On32772();
	afx_msg void On32775();
	afx_msg void On32781();
	CListCtrl showlist;
	afx_msg void OnBnClickedDel();
};
