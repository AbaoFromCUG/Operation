// HomeDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "Sixth.h"
#include "HomeDialog.h"
#include "afxdialogex.h"
#include"TransferDialog.h"
#include"SaveDialog.h"
#include"DetailsDialog.h"
#include"PaymentDialog.h"
#include<fstream>
#include<string>
using namespace std;

// CHomeDialog 对话框

IMPLEMENT_DYNAMIC(CHomeDialog, CDialog)

CHomeDialog::CHomeDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG2, pParent)
	, TextLineOne(_T(""))
	, TextLineTwo(_T(""))
	, TextLineThree(_T(""))
{
	refresh();
}

CHomeDialog::~CHomeDialog()
{
}

void CHomeDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, TextLineOne);
	DDX_Text(pDX, IDC_EDIT2, TextLineTwo);
	DDX_Text(pDX, IDC_EDIT5, TextLineThree);
}

User CHomeDialog::readCache()
{
	string str;
	fstream f("File\\cache.mfc", ios::in);
	getline(f, str);
	f.close();
	return User::getObject(str);
}


BEGIN_MESSAGE_MAP(CHomeDialog, CDialog)
	
	
	
	ON_BN_CLICKED(IDC_BUTTON5, &CHomeDialog::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CHomeDialog::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CHomeDialog::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON4, &CHomeDialog::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON1, &CHomeDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CHomeDialog::OnBnClickedButton2)
END_MESSAGE_MAP()


// CHomeDialog 消息处理程序





void CHomeDialog::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	CTransferDialog cD;
	cD.cH = this;
	cD.DoModal();
}


void CHomeDialog::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	CSaveDialog cD;
	cD.cH = this;
	cD.DoModal();
}

void CHomeDialog::refresh()
{

	User u = readCache();
	string str_name = ("你好呀:  " + u.getName());
	TextLineOne = &str_name[0];
	string str_id = "ID:  " + u.getId();
	TextLineTwo = &str_id[0];
	string str_money = "当前余额:  " + User::fun(u.getLastMoney(u.getLastRe()));
	TextLineThree = &str_money[0];
}

//交易详情
void CHomeDialog::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	CDetailsDialog cDD;
	cDD.DoModal();
}

//缴费
void CHomeDialog::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CPaymentDialog cP;
	cP.cH = this;
	cP.DoModal();
}


void CHomeDialog::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	six->id = "";
	six->key = "";
	six->UpdateData(false);
	CDialog::OnCancel();
}


void CHomeDialog::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}
