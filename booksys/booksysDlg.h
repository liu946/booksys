
// booksysDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CbooksysDlg �Ի���
class CbooksysDlg : public CDialogEx
{
// ����
public:
	CbooksysDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_BOOKSYS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CEdit login_name;
	CEdit login_pwd;
	afx_msg void On32780();
	afx_msg void OnBnClickedExit();
};
