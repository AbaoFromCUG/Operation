#pragma once
#include"SixthDlg.h"	
#include"User.h"
// CHomeDialog �Ի���

class CHomeDialog : public CDialog
{
	DECLARE_DYNAMIC(CHomeDialog)

public:
	CHomeDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CHomeDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString TextLineOne;
	CString TextLineTwo;
	CString TextLineThree;
	CSixthDlg* six;
	static User readCache();
	
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	void refresh();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
