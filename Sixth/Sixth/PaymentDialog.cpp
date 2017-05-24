// PaymentDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Sixth.h"
#include "PaymentDialog.h"
#include "afxdialogex.h"
#include"HomeDialog.h"
#include"URecord.h"
#include<string>
using namespace std;

// CPaymentDialog �Ի���

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


// CPaymentDialog ��Ϣ�������


void CPaymentDialog::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	string str = LPCSTR(shuo);
	if (much<=0)
	{
		MessageBox("�ɷѽ��Ƿ�", __T("�������"));
		shuo = "";
		much = 0;
		UpdateData(false);
		return;
	}
	try
	{
		CHomeDialog::readCache().doSomesthing(URecord::Do_Deduct, str, much);
		MessageBox("�ɷѳɹ�", __T("��ϲ��"));
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
