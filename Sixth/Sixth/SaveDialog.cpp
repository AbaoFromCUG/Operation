// SaveDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "Sixth.h"
#include "SaveDialog.h"
#include "afxdialogex.h"
#include"URecord.h"
#include"HomeDialog.h"
#include<string>
using namespace std;

// CSaveDialog 对话框

IMPLEMENT_DYNAMIC(CSaveDialog, CDialog)

CSaveDialog::CSaveDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG4, pParent)
	, much(_T(""))
	, str(_T(" "))
{

}

CSaveDialog::~CSaveDialog()
{
}

void CSaveDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, much);
	DDX_Text(pDX, IDC_EDIT2, str);
}


BEGIN_MESSAGE_MAP(CSaveDialog, CDialog)
	
	ON_BN_CLICKED(IDOK, &CSaveDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CSaveDialog 消息处理程序



void CSaveDialog::OnBnClickedOk()
{


	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	string shuo = LPCSTR(str);
	double amuch = User::fun(LPCSTR(much));
	if (amuch <= 0)
	{
		AfxMessageBox(__T("输入金额不合法，我要打妖妖灵"));
		str = "";
		shuo = "";
		much = "";
		UpdateData(false);
		return;
	}

	CHomeDialog::readCache().doSomesthing(URecord::Do_Save, shuo, amuch);
	cH->refresh();
	cH->UpdateData(false);
	AfxMessageBox(__T("存钱成功"));
	CDialog::OnCancel();
}
