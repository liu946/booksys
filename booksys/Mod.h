#pragma once


// Mod �Ի���

class Mod : public CDialogEx
{
	DECLARE_DYNAMIC(Mod)

public:
	Mod(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Mod();

// �Ի�������
	enum { IDD = IDD_MOD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
