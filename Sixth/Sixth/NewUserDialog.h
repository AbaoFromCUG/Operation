#pragma once
#include"SixthDlg.h"
#include<string>
using namespace std;
// CNewUserDialog �Ի���

class CNewUserDialog : public CDialog
{
	DECLARE_DYNAMIC(CNewUserDialog)

public:
	CNewUserDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNewUserDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	
	DECLARE_MESSAGE_MAP()
public:
	CString new_name;
	CString new_id;
	CString new_key;
	CString new_key_com;
	CSixthDlg* cD;
	afx_msg void OnBnClickedButton1();
	static void writeCache(string);
};
