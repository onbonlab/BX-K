// ProgramDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Led5kSDKDemo.h"
#include "ProgramDlg.h"
#include "afxdialogex.h"
#include "AreaDlg.h"
#include "StaticAreaDlg.h"

// CProgramDlg 对话框



IMPLEMENT_DYNAMIC(CProgramDlg, CDialog)

CProgramDlg::CProgramDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProgramDlg::IDD, pParent)
	, m_Name(_T("P001"))
	, m_DisplayMode(0)
	, m_PlayTimes(1)
	, m_DuringTime(10)
{

}

CProgramDlg::~CProgramDlg()
{
}

void CProgramDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	DDV_MaxChars(pDX, m_Name, 4);
	DDX_Control(pDX, IDC_LIST1, m_AreaList);
	DDX_Radio(pDX,IDC_RADIO1,m_DisplayMode);
	DDX_Text(pDX,IDC_EDIT2,m_PlayTimes);
	DDX_Text(pDX,IDC_EDIT3,m_DuringTime);
}


BEGIN_MESSAGE_MAP(CProgramDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CProgramDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CProgramDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO1, &CProgramDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CProgramDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_CHECK9, &CProgramDlg::OnBnClickedCheck9)
	ON_BN_CLICKED(IDC_CHECK8, &CProgramDlg::OnBnClickedCheck8)
	ON_BN_CLICKED(IDC_BUTTON3, &CProgramDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_CHECK10, &CProgramDlg::OnBnClickedCheck10)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CProgramDlg 消息处理程序


void CProgramDlg::OnBnClickedButton1()
{
	CStaticAreaDlg dlg;
	if (dlg.DoModal()==IDOK)
	{
		int len=sizeof(bx_5k_area_header)+dlg.data_len;
		BYTE *buff=new BYTE[4+len];
		memcpy(buff,&len,4);
		memcpy(buff+4,&dlg.m_AreaHeader,sizeof(bx_5k_area_header));
		memcpy(buff+4+sizeof(bx_5k_area_header),dlg.data,dlg.data_len);
		int index=m_AreaList.AddString(dlg.m_Name);
		m_AreaList.SetItemData(index,(DWORD)buff);
	}
}

void CProgramDlg::OnBnClickedButton3()
{
	int index=m_AreaList.GetCurSel();
	if (index!=-1)
	{
		int index=m_AreaList.GetCurSel();
		BYTE* buff=(BYTE*)m_AreaList.GetItemData(index);
		delete[] buff;
		m_AreaList.DeleteString(index);
	}
}


void CProgramDlg::OnBnClickedOk()
{
	
	UpdateData(TRUE);
	if (m_Name.IsEmpty())
	{
		MessageBox(_T("请输入文件名"));
		return;
	}


	memset(name,0,sizeof(name));
	CString2Char(m_Name,name);

	CButton * btn=(CButton *)GetDlgItem(IDC_CHECK9);
	if (btn->GetCheck())
	{
		memset(ProgramLife,0xff,sizeof(ProgramLife));
	}
	else
	{
		CDateTimeCtrl * pCtrl=(CDateTimeCtrl *)GetDlgItem(IDC_DATETIMEPICKER1);
		CTime t1;
		pCtrl->GetTime(t1);
		pCtrl=(CDateTimeCtrl *)GetDlgItem(IDC_DATETIMEPICKER2);
		CTime t2;
		pCtrl->GetTime(t2);
		USHORT StartYear=short2bcd(t1.GetYear());
		BYTE StartMonth=byte2bcd(t1.GetMonth());
		BYTE StartDay=byte2bcd(t1.GetDay());
		USHORT EndYear=short2bcd(t2.GetYear());
		BYTE EndMonth=byte2bcd(t2.GetMonth());
		BYTE EndDay=byte2bcd(t2.GetDay());
		memcpy(ProgramLife,&StartYear,2);
		ProgramLife[2]=StartMonth;
		ProgramLife[3]=StartDay;
		memcpy(ProgramLife+4,&EndYear,2);
		ProgramLife[6]=StartMonth;
		ProgramLife[7]=StartDay;
	}
	btn=(CButton *)GetDlgItem(IDC_CHECK10);
	if (btn->GetCheck())
	{
		ProgramWeek=1;
	}
	else
	{
		ProgramWeek=((CButton *)GetDlgItem(IDC_CHECK1))->GetCheck()*(1<<1)+
			((CButton *)GetDlgItem(IDC_CHECK2))->GetCheck()*(1<<2)+
			((CButton *)GetDlgItem(IDC_CHECK3))->GetCheck()*(1<<3)+
			((CButton *)GetDlgItem(IDC_CHECK4))->GetCheck()*(1<<4)+
			((CButton *)GetDlgItem(IDC_CHECK5))->GetCheck()*(1<<5)+
			((CButton *)GetDlgItem(IDC_CHECK6))->GetCheck()*(1<<6)+
			((CButton *)GetDlgItem(IDC_CHECK7))->GetCheck()*(1<<7);
	}

	btn=(CButton *)GetDlgItem(IDC_CHECK8);
	if (btn->GetCheck())
	{
		ProgramTime=0;
	}
	else
	{
		ProgramTime=1;
		CDateTimeCtrl * pCtrl=(CDateTimeCtrl *)GetDlgItem(IDC_DATETIMEPICKER3);
		CTime t1;
		pCtrl->GetTime(t1);
		pCtrl=(CDateTimeCtrl *)GetDlgItem(IDC_DATETIMEPICKER4);
		CTime t2;
		pCtrl->GetTime(t2);


		period[0]=byte2bcd(t1.GetHour());
		period[1]=byte2bcd(t1.GetMinute());
		period[2]=byte2bcd(t1.GetSecond());
		period[3]=byte2bcd(t2.GetHour());
		period[4]=byte2bcd(t2.GetMinute());
		period[5]=byte2bcd(t2.GetSecond());
		period[6]=0;

	}

	m_AreaListDataLen=0;
	for (int i=0;i<m_AreaList.GetCount();i++)
	{
		BYTE* buff=(BYTE*)m_AreaList.GetItemData(i);
		int len=0;
		memcpy(&len,buff,4);
		m_AreaListDataLen+=len+4;
	}
	m_AreaListData=new BYTE[m_AreaListDataLen];
	BYTE* pos=m_AreaListData;
	for (int i=0;i<m_AreaList.GetCount();i++)
	{
		BYTE* buff=(BYTE*)m_AreaList.GetItemData(i);
		int len=0;
		memcpy(&len,buff,4);
		memcpy(pos,buff,len+4);
		pos+=len+4;
	}
	m_AreaNum=m_AreaList.GetCount();
	CDialogEx::OnOK();
}


void CProgramDlg::OnBnClickedRadio1()
{
	CButton * btn=(CButton *)GetDlgItem(IDC_RADIO1);
	if(btn->GetCheck())
	{
		GetDlgItem(IDC_EDIT2)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
	}
}


void CProgramDlg::OnBnClickedRadio2()
{
	CButton * btn=(CButton *)GetDlgItem(IDC_RADIO2);
	if(btn->GetCheck())
	{
		GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT3)->EnableWindow(TRUE);
	}
}


void CProgramDlg::OnBnClickedCheck9()
{
	CButton * btn=(CButton *)GetDlgItem(IDC_CHECK9);
	if (btn->GetCheck())
	{
		GetDlgItem(IDC_DATETIMEPICKER1)->EnableWindow(FALSE);
		GetDlgItem(IDC_DATETIMEPICKER2)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_DATETIMEPICKER1)->EnableWindow(TRUE);
		GetDlgItem(IDC_DATETIMEPICKER2)->EnableWindow(TRUE);
	}
}


void CProgramDlg::OnBnClickedCheck8()
{
	CButton * btn=(CButton *)GetDlgItem(IDC_CHECK8);
	if (btn->GetCheck())
	{
		GetDlgItem(IDC_DATETIMEPICKER3)->EnableWindow(FALSE);
		GetDlgItem(IDC_DATETIMEPICKER4)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_DATETIMEPICKER3)->EnableWindow(TRUE);
		GetDlgItem(IDC_DATETIMEPICKER4)->EnableWindow(TRUE);
	}
}

void CProgramDlg::OnBnClickedCheck10()
{
	CButton * btn=(CButton *)GetDlgItem(IDC_CHECK10);
	if (btn->GetCheck())
	{
		GetDlgItem(IDC_CHECK1)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK2)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK3)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK4)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK5)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK6)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK7)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_CHECK1)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK2)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK3)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK4)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK5)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK6)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK7)->EnableWindow(TRUE);
	}
}


void CProgramDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	for (int i=0;i<m_AreaList.GetCount();i++)
	{
		BYTE* buff=(BYTE*)m_AreaList.GetItemData(i);
		delete[] buff;
	}
}

//数据初始化
BOOL CProgramDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CButton * btn=(CButton *)GetDlgItem(IDC_CHECK9);
	btn->SetCheck(1);
	btn=(CButton *)GetDlgItem(IDC_CHECK8);
	btn->SetCheck(1);
	btn=(CButton *)GetDlgItem(IDC_CHECK10);
	btn->SetCheck(1);
	GetDlgItem(IDC_DATETIMEPICKER1)->EnableWindow(FALSE);
	GetDlgItem(IDC_DATETIMEPICKER2)->EnableWindow(FALSE);
	GetDlgItem(IDC_DATETIMEPICKER3)->EnableWindow(FALSE);
	GetDlgItem(IDC_DATETIMEPICKER4)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK1)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK2)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK3)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK4)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK5)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK6)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK7)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
