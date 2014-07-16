#pragma once
#include <string>
#include "afxwin.h"
#include "Studentmanagement.h"
#include "Officermanagement.h"
using namespace std;

// Mod �Ի���

class Mod : public CDialogEx
{
	DECLARE_DYNAMIC(Mod)

public:
	Mod(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Mod();

// �Ի�������
	enum { IDD = IDD_MOD };
	string id;
	string name;
	string pwd;
	string sex;
	string age;
	Studentmanagement stumgt;
	Officermanagement offmgt;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CEdit tx_id;
	CEdit tx_pwd;
	CEdit tx_name;
	CEdit tx_sex;
	CEdit tx_age;
};
