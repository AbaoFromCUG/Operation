// PaymentDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "Sixth.h"
#include "PaymentDialog.h"
#include "afxdialogex.h"
#include"HomeDialog.h"
#include"URecord.h"
#include<string>
using namespace std;

// CPaymentDialog 对话框

IMPLEMENT_DYNAMIC(CPaymentDialog, CDialog)

CPaymentDialog::CPaymentDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG5, pParent)
	, much(0)
	, shuo(_T(""))
{

}

CPaymentDialog::~CPaymentDialog()
{
}

void CPaymentDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, much);
	DDX_Text(pDX, IDC_EDIT2, shuo);
}


BEGIN_MESSAGE_MAP(CPaymentDialog, CDialog)
	ON_BN_CLICKED(IDOK, &CPaymentDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CPaymentDialog 消息处理程序


void CPaymentDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	string str = LPCSTR(shuo);
	if (much<=0)
	{
		MessageBox("缴费金额非法", __T("别搞事情"));
		shuo = "";
		much = 0;
		UpdateData(false);
		return;
	}
	try
	{
		CHomeDialog::readCache().doSomesthing(URecord::Do_Deduct, str, much);
		MessageBox("缴费成功", __T("恭喜啊"));
		cH->refresh();
		cH->UpdateData(false);
		CDialog::OnOK();
	}
	catch (const std::exception&)
	{

	}
	catch (string str)
	{
		AfxMessageBox(_T(&str[0]));
	}
}
