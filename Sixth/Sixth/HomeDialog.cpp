// HomeDialog.cpp : ʵ���ļ�
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

// CHomeDialog �Ի���

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


// CHomeDialog ��Ϣ�������





void CHomeDialog::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CTransferDialog cD;
	cD.cH = this;
	cD.DoModal();
}


void CHomeDialog::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CSaveDialog cD;
	cD.cH = this;
	cD.DoModal();
}

void CHomeDialog::refresh()
{

	User u = readCache();
	string str_name = ("���ѽ:  " + u.getName());
	TextLineOne = &str_name[0];
	string str_id = "ID:  " + u.getId();
	TextLineTwo = &str_id[0];
	string str_money = "��ǰ���:  " + User::fun(u.getLastMoney(u.getLastRe()));
	TextLineThree = &str_money[0];
}

//��������
void CHomeDialog::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDetailsDialog cDD;
	cDD.DoModal();
}

//�ɷ�
void CHomeDialog::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CPaymentDialog cP;
	cP.cH = this;
	cP.DoModal();
}


void CHomeDialog::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	six->id = "";
	six->key = "";
	six->UpdateData(false);
	CDialog::OnCancel();
}


void CHomeDialog::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}
