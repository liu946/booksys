#pragma once
#include "afxwin.h"
#include "Studentmanagement.h"

// Rollback �Ի���

class Rollback : public CDialogEx
{
	DECLARE_DYNAMIC(Rollback)

public:
	Rollback(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Rollback();
	Studentmanagement stumgt;
// �Ի�������
	enum { IDD = IDD_ROLLBACK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CEdit ec_rollbackid;
	CEdit ec_rollbackmsg;
};
