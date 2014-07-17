#pragma once
#include "afxwin.h"
#include <string>
#include "Studentmanagement.h"
#include "afxcmn.h"
#include "CBookMangement.h"
#include "Officermanagement.h"
using namespace std;
// Mainpage �Ի���

class Mainpage : public CDialogEx
{
	DECLARE_DYNAMIC(Mainpage)

public:
	Mainpage(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Mainpage();
	Studentmanagement Stumgt;
	CBookMangement bkmgt;
	//���ز˵�
	CMenu m_menu;
	//�û�����
	string name;
// �Ի�������
	Officermanagement offmgt;
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
	int byname;
	int byid;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedMod();
	afx_msg void On32773();
	afx_msg void On32789();
	afx_msg void On32779();
	afx_msg void On32790();
	afx_msg void On32791();
	afx_msg void On_newbook();
	afx_msg void On32786();
	afx_msg void offshow();
	bool showingstu;
	bool showingbook;
	afx_msg void On32797();
	afx_msg void On32798();
	afx_msg void outofficer();
	afx_msg void instudent();
	afx_msg void inofficer();
	bool isadminlogin;
	string getstring(int n);
	Officer curper;
	afx_msg void outbook();
	afx_msg void inbook();
//	afx_msg void OnLvnColumnclickList1(NMHDR *pNMHDR, LRESULT *pResult);
	CButton modbtn;
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void helpdoc();
};
