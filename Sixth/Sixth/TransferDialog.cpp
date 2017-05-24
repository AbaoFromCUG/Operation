// TransferDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "Sixth.h"
#include "TransferDialog.h"
#include "afxdialogex.h"
#include"HomeDialog.h"
#include"URecord.h"
// CTransferDialog 对话框

IMPLEMENT_DYNAMIC(CTransferDialog, CDialog)

CTransferDialog::CTransferDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG3, pParent)
	, aim_id(_T(""))
	, much(0)
	, description(_T(""))
{

}

CTransferDialog::~CTransferDialog()
{
}

void CTransferDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, aim_id);
	DDX_Text(pDX, IDC_EDIT2, much);
	DDX_Text(pDX, IDC_EDIT6, description);
}


BEGIN_MESSAGE_MAP(CTransferDialog, CDialog)
	ON_BN_CLICKED(IDOK, &CTransferDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CTransferDialog::OnBnClickedCancel)
END_MESSAGE_MAP()


// CTransferDialog 消息处理程序


void CTransferDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	try
	{
		UpdateData(true);
		string id = LPCSTR(aim_id);
		string str = LPCSTR(description);
		if (id=="")
		{
			MessageBox("请不要调皮，收款人ID为空", __T("收款人ID为空"));
			return;
		}
		if (much<=0)
		{
			MessageBox("输入金额不合法，我要打妖妖灵",__T("输入金额不合法"));
			aim_id = "";
			description = "";
			much = 0;
			UpdateData(false);
			return;
		}
		if (!User(id).isId())
		{
			MessageBox("请不要调皮，收款人ID不存在", __T("收款人不存在"));
			return;
		}

		CHomeDialog::readCache().doSomesthing(URecord::Do_Transfer,str, id, much);
		MessageBox("嗯，正常的成功了",__T("转账成功"));
		cH->refresh();
		cH->UpdateData(false);
		CDialog::OnCancel();
	}
	catch (const std::exception&)
	{

	}
	catch (string str)
	{
		AfxMessageBox(__T(&str[0]));
	}
	catch (...)
	{
		AfxMessageBox(__T(""));
	}
}


void CTransferDialog::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CDialog::OnCancel();
}
