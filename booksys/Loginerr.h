#pragma once


// Loginerr �Ի���

class Loginerr : public CDialogEx
{
	DECLARE_DYNAMIC(Loginerr)

public:
	Loginerr(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Loginerr();

// �Ի�������
	enum { IDD = IDD_LOGINERR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
