#pragma once
#include "afxwin.h"
#include "CBookMangement.h"

// Newbook �Ի���

class Newbook : public CDialogEx
{
	DECLARE_DYNAMIC(Newbook)

public:
	Newbook(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Newbook();
	CBookMangement bkmgt;

// �Ի�������
	enum { IDD = IDD_NEWBOOK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit msg;
	CEdit ce_id;
	CEdit ec_name;
	CEdit ec_num;
	CEdit ec_year;
	CEdit ec_month;
	CEdit ec_day;
	afx_msg void OnBnClickedOk();
};
