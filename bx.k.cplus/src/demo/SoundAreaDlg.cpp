// SoundAreaDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Led5kSDKDemo.h"
#include "SoundAreaDlg.h"
#include "afxdialogex.h"


// SoundAreaDlg 对话框

IMPLEMENT_DYNAMIC(SoundAreaDlg, CDialogEx)

SoundAreaDlg::SoundAreaDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(SoundAreaDlg::IDD, pParent)
	, m_X(0)
	, m_Y(0)
	, m_W(64)
	, m_H(32)
	, m_LineInterval(0)
	, m_Timeout(2)
	, m_StayTime(10)
	, m_Text(_T(""))
{

}

SoundAreaDlg::~SoundAreaDlg()
{
}

void SoundAreaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX,IDC_EDIT1,m_X);
	DDX_Text(pDX,IDC_EDIT18,m_Y);
	DDX_Text(pDX,IDC_EDIT22,m_W);
	DDX_Text(pDX,IDC_EDIT23,m_H);
	DDX_Text(pDX,IDC_EDIT6,m_LineInterval);
	DDX_Text(pDX,IDC_EDIT4,m_Timeout);
	DDX_Text(pDX,IDC_EDIT5,m_StayTime);
	DDX_Control(pDX, IDC_COMBO1, m_cmbSinglLine);
	DDX_Control(pDX, IDC_COMBO2, m_cmbNewLine);
	DDX_Control(pDX, IDC_COMBO5, m_cmbDisplayMode);
	DDX_Control(pDX, IDC_COMBO6, m_cmdSpeed);
	DDX_Control(pDX, IDC_COMBO3, m_cmbSoundMode);
	DDX_Control(pDX, IDC_COMBO7, m_cmbSoundPerson);
	DDX_Control(pDX, IDC_COMBO9, m_cmbSoundVolume);
	DDX_Control(pDX, IDC_COMBO10, m_cmbSoundSpeed);
	DDX_Text(pDX,IDC_EDIT3,m_Text);
	DDX_Text(pDX,IDC_EDIT24,m_SoundText);
	DDX_Control(pDX, IDC_COMBO4, m_cmbRunMode);
}


BEGIN_MESSAGE_MAP(SoundAreaDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &SoundAreaDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &SoundAreaDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// SoundAreaDlg 消息处理程序


void SoundAreaDlg::OnBnClickedOk()
{
	UpdateData(TRUE);
	m_AreaHeader.AreaX=m_X/8;
	m_AreaHeader.AreaY=m_Y;
	m_AreaHeader.AreaWidth=m_W/8;
	m_AreaHeader.AreaHeight=m_H;
	m_AreaHeader.Timeout=m_Timeout;
	m_AreaHeader.StayTime=m_StayTime;
	m_AreaHeader.Lines_sizes=m_LineInterval;

	m_AreaHeader.NewLine=m_cmbNewLine.GetCurSel()+1;
	m_AreaHeader.DisplayMode=m_cmbDisplayMode.GetCurSel()+1;
	m_AreaHeader.Speed=m_cmdSpeed.GetCurSel()+1;
	m_AreaHeader.RunMode=m_cmbRunMode.GetCurSel();
	m_AreaHeader.SingleLine=m_cmbSinglLine.GetCurSel()+1;
	m_AreaHeader.AreaType=6;
	m_AreaHeader.ExitMode=0;

	SoundMode = m_cmbSoundMode.GetCurSel();
	SoundPerson = m_cmbSoundPerson.GetCurSel();
	SoundVolume = m_cmbSoundVolume.GetCurSel();
	SoundSpeed = m_cmbSoundSpeed.GetCurSel();

	memset(Sounddata,0,sizeof(Sounddata));
	CString2Char(m_SoundText,Sounddata);
	Sounddata_len=strlen(Sounddata); 
	

	memset(m_AreaHeader.Reserved,0,sizeof(m_AreaHeader.Reserved));

	memset(data,0,sizeof(data));
	CString2Char(m_Text,data);
	data_len=strlen(data);
	m_AreaHeader.DataLen=data_len;
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}

BOOL SoundAreaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_cmbDisplayMode.SetCurSel(0);
	m_cmbSinglLine.SetCurSel(0);
	m_cmbNewLine.SetCurSel(0);
	m_cmdSpeed.SetCurSel(0);
	m_cmbRunMode.SetCurSel(1);
	m_cmbSoundMode.SetCurSel(0);
	m_cmbSoundPerson.SetCurSel(0);
	m_cmbSoundVolume.SetCurSel(0);
	m_cmbSoundSpeed.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void SoundAreaDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
