#include "Officermanagement.h"
#pragma once


// AddOfficer �Ի���

class AddOfficer : public CDialogEx
{
	DECLARE_DYNAMIC(AddOfficer)

public:
	AddOfficer(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AddOfficer();
	CButton addconfirmbtn;
// �Ի�������
	enum { IDD = IDD_ADDOFFICER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk2();
	Officermanagement offmgt;
	afx_msg void OnEnKillfocusAddsid();

	afx_msg void OnBnClickedCancel2();
};
