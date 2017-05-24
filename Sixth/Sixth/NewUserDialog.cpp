// NewUserDialog.cpp : 实现文件
//

#include "stdafx.h"
#include"User.h"
#include "Sixth.h"
#include "NewUserDialog.h"
#include "afxdialogex.h"
#include<fstream>
using namespace std;

// CNewUserDialog 对话框

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


// CNewUserDialog 消息处理程序


void CNewUserDialog::OnBnClickedButton1()
{
	//string name=

	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	string name = LPCSTR(new_name);
	string id = LPCSTR(new_id);
	string key = LPCSTR(new_key);
	string key_com = LPCSTR(new_key_com);
	if (name == "" || id == "" || key == "" || key_com == "")
	{

		MessageBox("请填满",__T("注册时别搞事情"));
		//CDialog::OnCancel();
		return;
	}
	if ((!User::isHeFa(id))&&(!User::isHeFa(key)) &&(!User::isHeFa(key_com))&& (!User::isHeFa(name)))
	{
		MessageBox("账号密码中存在不合法的字符或者过长",__T("别乱来"));
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
		AfxMessageBox(__T("File\\路径不存在,注册失败"));
		return;
	}
	string str;
	User new_u(id, key, name);

	//检查是否存在相同id
	while (getline(file, str))
	{
		User A_u = User::getObject(str);
		User B_u = User::getObject(new_u.getInfor());


		//如果id存在
		if (A_u.getId() == B_u.getId()) {
			//	new_name = "";
			new_id = "";
			new_key = "";
			new_key_com = "";
			UpdateData(false);
			AfxMessageBox(__T("id已经存在，额，或许你可以申请过一个id"));
			return;
		}
	}
	file.close();
	//判断两次密码是否相同
	if (new_key != new_key_com)
	{
		new_key = "";
		new_key_com = "";
		UpdateData(false);
		AfxMessageBox(__T("两次密码不相同，请重新输入"));
		return;
	}
	//条件满足，开始创建,应为底层代码写好，所以无需读写文件
	User n(id, key, name, true);
	string m_str = "创建成功，请记住自己的id " + id + " 与密码" + key;
	//写入缓存文件
	writeCache(n.getInfor());
	cD->id = &id[0];
	cD->key = &key[0];
	cD->UpdateData(false);
	AfxMessageBox(__T(&m_str[0]));
	CDialog::OnCancel();
}
