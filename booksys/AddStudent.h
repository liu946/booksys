#pragma once
#include "afxwin.h"
#include "Studentmanagement.h"

// AddStudent �Ի���

class AddStudent : public CDialogEx
{
	DECLARE_DYNAMIC(AddStudent)

public:
	AddStudent(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AddStudent();
	Studentmanagement stumgt;

// �Ի�������
	enum { IDD = IDD_ADDSTUDENT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnKillfocusAddsid();
	CButton addconfirmbtn;
	afx_msg void On32789();
};
