#pragma once
#include "afxwin.h"
#include <string>
using namespace std;
// Mainpage �Ի���

class Mainpage : public CDialogEx
{
	DECLARE_DYNAMIC(Mainpage)

public:
	Mainpage(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Mainpage();
	//���ز˵�
	CMenu m_menu;
	//�û�����
	string name;
// �Ի�������
	enum { IDD = IDD_MAINPAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit search;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void On32780();
	virtual BOOL OnInitDialog();
	CListBox showlist;
	afx_msg void On32771();
	afx_msg void On32772();
};
