#pragma once
#include"HomeDialog.h"

// CSaveDialog �Ի���

class CSaveDialog : public CDialog
{
	DECLARE_DYNAMIC(CSaveDialog)

public:
	CSaveDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSaveDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP();
public:
	CHomeDialog* cH;
	CString much;
	CString str;
	afx_msg void OnBnClickedOk();
};
