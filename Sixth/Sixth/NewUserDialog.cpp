// NewUserDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include"User.h"
#include "Sixth.h"
#include "NewUserDialog.h"
#include "afxdialogex.h"
#include<fstream>
using namespace std;

// CNewUserDialog �Ի���

IMPLEMENT_DYNAMIC(CNewUserDialog, CDialog)

CNewUserDialog::CNewUserDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1, pParent)
	, new_name(_T(""))
	, new_id(_T(""))
	, new_key(_T(""))
	, new_key_com(_T(""))
{
	cD = NULL;
}

CNewUserDialog::~CNewUserDialog()
{
}

void CNewUserDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, new_name);
	DDX_Text(pDX, IDC_EDIT2, new_id);
	DDX_Text(pDX, IDC_EDIT3, new_key);
	DDX_Text(pDX, IDC_EDIT4, new_key_com);
}

void CNewUserDialog::writeCache(string str)
{
	fstream f("File\\cache.mfc", ios::trunc | ios::out);
	f <<str;
	f.close();
}


BEGIN_MESSAGE_MAP(CNewUserDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CNewUserDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// CNewUserDialog ��Ϣ�������


void CNewUserDialog::OnBnClickedButton1()
{
	//string name=

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	string name = LPCSTR(new_name);
	string id = LPCSTR(new_id);
	string key = LPCSTR(new_key);
	string key_com = LPCSTR(new_key_com);
	if (name == "" || id == "" || key == "" || key_com == "")
	{

		MessageBox("������",__T("ע��ʱ�������"));
		//CDialog::OnCancel();
		return;
	}
	if ((!User::isHeFa(id))&&(!User::isHeFa(key)) &&(!User::isHeFa(key_com))&& (!User::isHeFa(name)))
	{
		MessageBox("�˺������д��ڲ��Ϸ����ַ����߹���",__T("������"));
		new_name = "";
		new_id = "";
		new_key = "";
		new_key_com = "";
		UpdateData(false);
		return;
	}


	fstream file("File\\u_id_key.mfc", ios::in);
	if (file.fail())
	{
		AfxMessageBox(__T("File\\·��������,ע��ʧ��"));
		return;
	}
	string str;
	User new_u(id, key, name);

	//����Ƿ������ͬid
	while (getline(file, str))
	{
		User A_u = User::getObject(str);
		User B_u = User::getObject(new_u.getInfor());


		//���id����
		if (A_u.getId() == B_u.getId()) {
			//	new_name = "";
			new_id = "";
			new_key = "";
			new_key_com = "";
			UpdateData(false);
			AfxMessageBox(__T("id�Ѿ����ڣ����������������һ��id"));
			return;
		}
	}
	file.close();
	//�ж����������Ƿ���ͬ
	if (new_key != new_key_com)
	{
		new_key = "";
		new_key_com = "";
		UpdateData(false);
		AfxMessageBox(__T("�������벻��ͬ������������"));
		return;
	}
	//�������㣬��ʼ����,ӦΪ�ײ����д�ã����������д�ļ�
	User n(id, key, name, true);
	string m_str = "�����ɹ������ס�Լ���id " + id + " ������" + key;
	//д�뻺���ļ�
	writeCache(n.getInfor());
	cD->id = &id[0];
	cD->key = &key[0];
	cD->UpdateData(false);
	AfxMessageBox(__T(&m_str[0]));
	CDialog::OnCancel();
}
