// StaticAreaDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Led5kSDKDemo.h"
#include "StaticAreaDlg.h"
#include "afxdialogex.h"


// CStaticAreaDlg 对话框

IMPLEMENT_DYNAMIC(CStaticAreaDlg, CDialogEx)

CStaticAreaDlg::CStaticAreaDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStaticAreaDlg::IDD, pParent)
	, m_X(0)
	, m_Y(0)
	, m_W(64)
	, m_H(32)
	, m_LineInterval(0)
	, m_StayTime(10)
	, m_Text(_T(""))
	, m_Name(_T(""))
{

}

CStaticAreaDlg::~CStaticAreaDlg()
{
}

void CStaticAreaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX,IDC_EDIT1,m_X);
	DDX_Text(pDX,IDC_EDIT18,m_Y);
	DDX_Text(pDX,IDC_EDIT22,m_W);
	DDX_Text(pDX,IDC_EDIT23,m_H);
	DDX_Text(pDX,IDC_EDIT6,m_LineInterval);
	DDX_Text(pDX,IDC_EDIT5,m_StayTime);
	DDX_Control(pDX, IDC_COMBO1, m_cmbSinglLine);
	DDX_Control(pDX, IDC_COMBO2, m_cmbNewLine);
	DDX_Control(pDX, IDC_COMBO5, m_cmbDisplayMode);
	DDX_Control(pDX, IDC_COMBO6, m_cmdSpeed);
	DDX_Text(pDX,IDC_EDIT3,m_Text);

	DDX_Text(pDX, IDC_EDIT4, m_Name);
}


BEGIN_MESSAGE_MAP(CStaticAreaDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CStaticAreaDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CStaticAreaDlg 消息处理程序


void CStaticAreaDlg::OnBnClickedOk()
{
	UpdateData(TRUE);
	if (m_Name.IsEmpty())
	{
		MessageBox(_T("请给个名称"));
		return;
	}
	m_AreaHeader.AreaType=0;
	m_AreaHeader.AreaX=m_X/8;
	m_AreaHeader.AreaY=m_Y;
	m_AreaHeader.AreaWidth=m_W/8;
	m_AreaHeader.AreaHeight=m_H;
	m_AreaHeader.DynamicAreaLoc=0xff;
	m_AreaHeader.Lines_sizes=m_LineInterval;
	m_AreaHeader.RunMode=0;
	m_AreaHeader.Timeout=0;
	memset(m_AreaHeader.Reserved,0,sizeof(m_AreaHeader.Reserved));
	m_AreaHeader.SingleLine=m_cmbSinglLine.GetCurSel()+1;
	m_AreaHeader.NewLine=m_cmbNewLine.GetCurSel()+1;
	m_AreaHeader.DisplayMode=m_cmbDisplayMode.GetCurSel()+1;
	m_AreaHeader.ExitMode=0;
	m_AreaHeader.Speed=m_cmdSpeed.GetCurSel()+1;
	m_AreaHeader.StayTime=m_StayTime;

	memset(data,0,sizeof(data));
	CString2Char(m_Text,data);
	data_len=strlen(data);
	m_AreaHeader.DataLen=data_len;
	CDialogEx::OnOK();
}


BOOL CStaticAreaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_cmbDisplayMode.SetCurSel(0);
	m_cmbSinglLine.SetCurSel(0);
	m_cmbNewLine.SetCurSel(0);
	m_cmdSpeed.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
