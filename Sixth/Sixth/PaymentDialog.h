#pragma once
#include"HomeDialog.h"

// CPaymentDialog �Ի���

class CPaymentDialog : public CDialog
{
	DECLARE_DYNAMIC(CPaymentDialog)

public:
	CPaymentDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPaymentDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	double much;
	CString shuo;
	afx_msg void OnBnClickedOk();
	CHomeDialog* cH;
};
