
// Led5kSDKDemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Led5kSDKDemo.h"
#include "Led5kSDKDemoDlg.h"
#include "afxdialogex.h"
#include "AreaDlg.h"
#include "SoundAreaDlg.h"
#include "ProgramDlg.h"
#include <setupapi.h>
#include <devguid.h>
#include "..\\include\\Led5kSDK.h"


#ifdef _DEBUG
#pragma comment(lib,"..\\lib\\Led5kSdk.lib")
#else
#pragma comment(lib,"..\\lib\\Led5kSdk.lib")
#endif
#pragma comment(lib,"setupapi.lib")
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define WM_LED_CONNECT WM_USER+200
#define WM_LED_CLOSE WM_USER+201

BYTE gloabl_type[]={
	BX_Any,
	BX_5K1,
	BX_5K2,
	BX_5MK2,
	BX_5MK1,
	BX_5K1Q_YY,
	BX_6K1,
	BX_6K2,
	BX_6K3,
	BX_6K1_YY,
	BX_6K2_YY,
	BX_6K3_YY,
};

int   FindCommPort(   CComboBox   *pComboBox   ) 
{ 
	HDEVINFO   hDevInfo; 
	SP_DEVINFO_DATA   DeviceInfoData; 
	DWORD   i; 

	hDevInfo   =   SetupDiGetClassDevs((LPGUID)   &GUID_DEVCLASS_PORTS,   0,   0,DIGCF_PRESENT); 

	if   (hDevInfo   ==   INVALID_HANDLE_VALUE) 
	{ 
		//   Insert   error   handling   here. 
		return   1; 
	} 

	pComboBox->ResetContent();
	//   Enumerate   through   all   devices   in   Set. 

	DeviceInfoData.cbSize   =   sizeof(SP_DEVINFO_DATA); 
	for   (i=0;SetupDiEnumDeviceInfo(hDevInfo,i, 
		&DeviceInfoData);i++) 
	{ 
		DWORD   DataT; 
		//LPTSTR   buffer   =   NULL; 
		TCHAR   buffer[2048]; 
		DWORD   buffersize   =sizeof(buffer); 
		while   (!SetupDiGetDeviceRegistryProperty(
			hDevInfo, 
			&DeviceInfoData, 
			SPDRP_FRIENDLYNAME, 
			&DataT, 
			(PBYTE)buffer, 
			buffersize, 
			&buffersize)) 
		{ 
			break; 
		}
		CString str=buffer;
		if(!str.IsEmpty() ){
			str=str.Right(str.GetLength()-str.Find(_T("COM")));
			str=str.Mid(str.Find(_T("COM"))+3, str.Find(_T(")"))-str.Find(_T("COM"))-3);
			pComboBox->AddString(str);
		}
	} 
	if   (   GetLastError()!=NO_ERROR   && GetLastError()!=ERROR_NO_MORE_ITEMS   ) 
	{ 
		return   1; 
	} 
	//     Cleanup 
	SetupDiDestroyDeviceInfoList(hDevInfo); 

	if(   pComboBox-> GetCount()  >  0   )
	{ 
		pComboBox->SetCurSel(0);
	} 
	return 0;
}
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLed5kSDKDemoDlg 对话框




CLed5kSDKDemoDlg::CLed5kSDKDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLed5kSDKDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLed5kSDKDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, m_DynaAreaIDList);
	DDX_Control(pDX, IDC_COMBO17, m_cmbGprsList);
	DDX_Control(pDX, IDC_COMBO18, m_cmbClientList);
}

BEGIN_MESSAGE_MAP(CLed5kSDKDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON7, &CLed5kSDKDemoDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON3, &CLed5kSDKDemoDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CLed5kSDKDemoDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON33, &CLed5kSDKDemoDlg::OnBnClickedButton33)
	ON_BN_CLICKED(IDC_BUTTON12, &CLed5kSDKDemoDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON46, &CLed5kSDKDemoDlg::OnBnClickedButton46)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON44, &CLed5kSDKDemoDlg::OnBnClickedButton44)
	ON_BN_CLICKED(IDC_BUTTON43, &CLed5kSDKDemoDlg::OnBnClickedButton43)
	ON_BN_CLICKED(IDC_BUTTON42, &CLed5kSDKDemoDlg::OnBnClickedButton42)
	ON_BN_CLICKED(IDC_BUTTON1, &CLed5kSDKDemoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CLed5kSDKDemoDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON41, &CLed5kSDKDemoDlg::OnBnClickedButton41)
	ON_BN_CLICKED(IDC_BUTTON31, &CLed5kSDKDemoDlg::OnBnClickedButton31)
	ON_BN_CLICKED(IDC_BUTTON4, &CLed5kSDKDemoDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON9, &CLed5kSDKDemoDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CLed5kSDKDemoDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON6, &CLed5kSDKDemoDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON8, &CLed5kSDKDemoDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON40, &CLed5kSDKDemoDlg::OnBnClickedButton40)
	ON_BN_CLICKED(IDC_CHECK1, &CLed5kSDKDemoDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CLed5kSDKDemoDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CLed5kSDKDemoDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_BUTTON39, &CLed5kSDKDemoDlg::OnBnClickedButton39)
	ON_BN_CLICKED(IDC_BUTTON18, &CLed5kSDKDemoDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON14, &CLed5kSDKDemoDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON32, &CLed5kSDKDemoDlg::OnBnClickedButton32)
	ON_BN_CLICKED(IDC_BUTTON34, &CLed5kSDKDemoDlg::OnBnClickedButton34)
	ON_BN_CLICKED(IDC_BUTTON35, &CLed5kSDKDemoDlg::OnBnClickedButton35)
	ON_BN_CLICKED(IDC_BUTTON36, &CLed5kSDKDemoDlg::OnBnClickedButton36)
	ON_BN_CLICKED(IDC_BUTTON38, &CLed5kSDKDemoDlg::OnBnClickedButton38)
	ON_BN_CLICKED(IDC_BUTTON21, &CLed5kSDKDemoDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON24, &CLed5kSDKDemoDlg::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON27, &CLed5kSDKDemoDlg::OnBnClickedButton27)
	ON_BN_CLICKED(IDC_BUTTON30, &CLed5kSDKDemoDlg::OnBnClickedButton30)
	ON_BN_CLICKED(IDC_BUTTON28, &CLed5kSDKDemoDlg::OnBnClickedButton28)
	ON_BN_CLICKED(IDC_BUTTON25, &CLed5kSDKDemoDlg::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON22, &CLed5kSDKDemoDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON11, &CLed5kSDKDemoDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON19, &CLed5kSDKDemoDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CLed5kSDKDemoDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON23, &CLed5kSDKDemoDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON26, &CLed5kSDKDemoDlg::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON29, &CLed5kSDKDemoDlg::OnBnClickedButton29)
	ON_BN_CLICKED(IDC_BUTTON37, &CLed5kSDKDemoDlg::OnBnClickedButton37)
	ON_BN_CLICKED(IDC_BUTTON45, &CLed5kSDKDemoDlg::OnBnClickedButton45)
	ON_BN_CLICKED(IDC_BUTTON13, &CLed5kSDKDemoDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON16, &CLed5kSDKDemoDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON15, &CLed5kSDKDemoDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON17, &CLed5kSDKDemoDlg::OnBnClickedButton17)
	ON_MESSAGE(WM_LED_CONNECT,&CLed5kSDKDemoDlg::OnLedConnect)
	ON_MESSAGE(WM_LED_CLOSE,&CLed5kSDKDemoDlg::OnLedClose)
	ON_MESSAGE(WM_LED_CONNECT,&CLed5kSDKDemoDlg::OnGprsConnect)
	ON_MESSAGE(WM_LED_CLOSE,&CLed5kSDKDemoDlg::OnGprsClose)
	ON_BN_CLICKED(IDC_BUTTON47, &CLed5kSDKDemoDlg::OnBnClickedButton47)
	ON_BN_CLICKED(IDC_BUTTON48, &CLed5kSDKDemoDlg::OnBnClickedButton48)
	ON_CBN_SELCHANGE(IDC_COMBO17, &CLed5kSDKDemoDlg::OnCbnSelchangeCombo17)
	ON_CBN_SELCHANGE(IDC_COMBO18, &CLed5kSDKDemoDlg::OnCbnSelchangeCombo18)
END_MESSAGE_MAP()


// CLed5kSDKDemoDlg 消息处理程序

BOOL CLed5kSDKDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	CComboBox* pCombox=(CComboBox*)GetDlgItem(IDC_COMBO1);
	pCombox->Clear();
	FindCommPort(pCombox);
	pCombox=(CComboBox*)GetDlgItem(IDC_COMBO2);
	pCombox->SetCurSel(0);
	pCombox=(CComboBox*)GetDlgItem(IDC_COMBO3);
	pCombox->Clear();
	FindCommPort(pCombox);
	pCombox=(CComboBox*)GetDlgItem(IDC_COMBO4);
	pCombox->SetCurSel(6);
	pCombox=(CComboBox*)GetDlgItem(IDC_COMBO5);
	pCombox->SetCurSel(0);
	pCombox=(CComboBox*)GetDlgItem(IDC_COMBO6);
	pCombox->SetCurSel(4);
	pCombox=(CComboBox*)GetDlgItem(IDC_COMBO7);
	pCombox->SetCurSel(0);
	pCombox=(CComboBox*)GetDlgItem(IDC_COMBO8);
	pCombox->SetCurSel(1);
	pCombox=(CComboBox*)GetDlgItem(IDC_COMBO9);
	pCombox->SetCurSel(1);
	pCombox=(CComboBox*)GetDlgItem(IDC_COMBO10);
	pCombox->SetCurSel(1);
	pCombox=(CComboBox*)GetDlgItem(IDC_COMBO11);
	pCombox->SetCurSel(1);
	pCombox=(CComboBox*)GetDlgItem(IDC_COMBO12);
	pCombox->SetCurSel(1);

	GetDlgItem(IDC_EDIT4)->SetWindowText(_T("5007"));
	GetDlgItem(IDC_EDIT6)->SetWindowText(_T("5005"));

	GetDlgItem(IDC_EDIT5)->SetWindowText(_T("1"));
	GetDlgItem(IDC_EDIT2)->SetWindowText(_T("1"));

	GetDlgItem(IDC_IPADDRESS2)->SetWindowText(_T("255.255.255.255"));
	GetDlgItem(IDC_IPADDRESS3)->SetWindowText(_T("192.168.5.10"));
	GetDlgItem(IDC_IPADDRESS4)->SetWindowText(_T("192.168.1.100"));

	GetDlgItem(IDC_EDIT1)->SetWindowText(_T("10"));
	GetDlgItem(IDC_EDIT21)->SetWindowText(_T("5"));
	GetDlgItem(IDC_EDIT19)->SetWindowText(_T("10"));
	GetDlgItem(IDC_EDIT20)->SetWindowText(_T("10"));

	GetDlgItem(IDC_BUTTON11)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON22)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON25)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON28)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON46)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON47)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON48)->EnableWindow(FALSE);

	GetDlgItem(IDC_EDIT25)->SetWindowText(_T("8117"));
	GetDlgItem(IDC_EDIT26)->SetWindowText(_T("8118"));
	InitSdk(2,2);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CLed5kSDKDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLed5kSDKDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CLed5kSDKDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CLed5kSDKDemoDlg::OnBnClickedButton7()
{
	//打开广播
	CWnd* pWnd=GetDlgItem(IDC_IPADDRESS2);
	CString str;
	pWnd->GetWindowText(str);
	char ip[16]={0};
	CString2Char(str,ip);
	CString tmp;
	GetDlgItem(IDC_EDIT4)->GetWindowText(tmp);
	USHORT port=_tstoi(tmp);
	int sel=((CComboBox*)GetDlgItem(IDC_COMBO12))->GetCurSel();
	unsigned char bar[16]={0};

	DWORD hand=CreateBroadCast(ip,port,(bx_5k_card_type)gloabl_type[sel],bar,0,1);
	if (hand==0)
	{
		MessageBox(_T("连接控制器失败"));
		return;
	}
	this->m_dwCurHand=hand;

	GetDlgItem(IDC_BUTTON46)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON33)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON12)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);

	GetDlgItem(IDC_BUTTON11)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON22)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON25)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON28)->EnableWindow(FALSE);


}


void CLed5kSDKDemoDlg::OnBnClickedButton3()
{
	// 固定ip
	CWnd* pWnd=GetDlgItem(IDC_IPADDRESS3);
	CString str;
	pWnd->GetWindowText(str);
	char ip[16]={0};
	CString2Char(str,ip);
	CString tmp;
	GetDlgItem(IDC_EDIT6)->GetWindowText(tmp);
	USHORT port=_tstoi(tmp);
	int sel=((CComboBox*)GetDlgItem(IDC_COMBO11))->GetCurSel();

	DWORD hand=CreateClient(ip,port,(bx_5k_card_type)gloabl_type[sel],1,NULL);
	if (hand==0)
	{
		MessageBox(_T("连接控制器失败"));
		return;
	}
	this->m_dwCurHand=hand;

	GetDlgItem(IDC_BUTTON46)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON33)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON12)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);

	GetDlgItem(IDC_BUTTON11)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON22)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON25)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON28)->EnableWindow(FALSE);
}


void CLed5kSDKDemoDlg::OnBnClickedButton5()
{
	// tcp modbus
	CWnd* pWnd=GetDlgItem(IDC_IPADDRESS4);
	CString str;
	pWnd->GetWindowText(str);
	char ip[16]={0};
	CString2Char(str,ip);

	int sel=((CComboBox*)GetDlgItem(IDC_COMBO10))->GetCurSel();

	DWORD hand=CreateTcpModbus(ip,(bx_5k_card_type)gloabl_type[sel],NULL);
	if (hand==0)
	{
		MessageBox(_T("连接控制器失败"));
		return;
	}
	this->m_dwCurHand=hand;
	GetDlgItem(IDC_BUTTON46)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON33)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON12)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);

	GetDlgItem(IDC_BUTTON11)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON22)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON25)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON28)->EnableWindow(FALSE);
}


void CLed5kSDKDemoDlg::OnBnClickedButton33()
{
	// 串口
	CString tmp;
	GetDlgItem(IDC_COMBO1)->GetWindowText(tmp);
	BYTE com=_tstoi(tmp);

	GetDlgItem(IDC_COMBO2)->GetWindowText(tmp);
	DWORD baud=_tstoi(tmp);

	int sel=((CComboBox*)GetDlgItem(IDC_COMBO9))->GetCurSel();

	GetDlgItem(IDC_EDIT5)->GetWindowText(tmp);
	USHORT screenid=_tstoi(tmp);

	DWORD hand=CreateComClient(com,baud,(bx_5k_card_type)gloabl_type[sel],1,screenid);
	if (hand==0)
	{
		MessageBox(_T("连接控制器失败"));
		return;
	}
	this->m_dwCurHand=hand;
	GetDlgItem(IDC_BUTTON46)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON33)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON12)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);

	GetDlgItem(IDC_BUTTON11)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON22)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON25)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON28)->EnableWindow(TRUE);
}


void CLed5kSDKDemoDlg::OnBnClickedButton12()
{
	// 串行modbus
	CString tmp;
	GetDlgItem(IDC_COMBO3)->GetWindowText(tmp);
	BYTE com=_tstoi(tmp);

	GetDlgItem(IDC_COMBO4)->GetWindowText(tmp);
	DWORD baud=_tstoi(tmp);

	int sel=((CComboBox*)GetDlgItem(IDC_COMBO8))->GetCurSel();

	GetDlgItem(IDC_EDIT2)->GetWindowText(tmp);
	USHORT screenid=_tstoi(tmp);

	BYTE parity=((CComboBox*)GetDlgItem(IDC_COMBO5))->GetCurSel();

	BYTE stopbits=((CComboBox*)GetDlgItem(IDC_COMBO7))->GetCurSel();

	BYTE databits=((CComboBox*)GetDlgItem(IDC_COMBO6))->GetCurSel()+4;

	DWORD hand=CreateComModbus(com,baud,(serial_parity)parity,(serial_databits)databits,(serial_stopbits)stopbits,(bx_5k_card_type)gloabl_type[sel],screenid);
	if (hand==0)
	{
		MessageBox(_T("连接控制器失败"));
		return;
	}
	this->m_dwCurHand=hand;
	GetDlgItem(IDC_BUTTON46)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON33)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON12)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);

	GetDlgItem(IDC_BUTTON11)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON22)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON25)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON28)->EnableWindow(FALSE);
}


void CLed5kSDKDemoDlg::OnBnClickedButton46()
{
	// 断开
	Destroy(m_dwCurHand);
	GetDlgItem(IDC_BUTTON46)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON33)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON12)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON7)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);

	GetDlgItem(IDC_BUTTON11)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON22)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON25)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON28)->EnableWindow(FALSE);
}


void CLed5kSDKDemoDlg::OnClose()
{
	ReleaseSdk();

	CDialogEx::OnClose();
}


void CLed5kSDKDemoDlg::OnBnClickedButton44()
{
	// 查询控制器
	BYTE pStatus[1024]={0};
	USHORT len=0;
	int err=CON_ControllerStatus(m_dwCurHand,pStatus,&len);
	if (err==NO_ERROR)
	{
		BYTE onoff=pStatus[0];
		((CComboBox*)GetDlgItem(IDC_COMBO13))->SetCurSel(onoff-1);//开机状态
		BYTE brightness=pStatus[1];

		USHORT year=pStatus[3]/16*10+pStatus[3]%16+pStatus[2]/16*1000+pStatus[2]%16*100;
		BYTE month=pStatus[4]/16*10+pStatus[4]%16;
		BYTE day=pStatus[5]/16*10+pStatus[5]%16;
		BYTE hour=pStatus[7]/16*10+pStatus[7]%16;
		BYTE minute=pStatus[8]/16*10+pStatus[8]%16;
		BYTE sec=pStatus[6]/16*10+pStatus[6]%16;
		BYTE week=pStatus[9]/16*10+pStatus[9]%16;
		CString str;
		str.Format(_T("%d"),brightness);
		GetDlgItem(IDC_EDIT15)->SetWindowText(str);

		str.Format(_T("%4d/%2d/%2d %2d:%2d:%2d"),year,month,day,hour,minute,sec);
		GetDlgItem(IDC_EDIT16)->SetWindowText(str);//控制器时间
		BYTE programnum=pStatus[10];
		str.Format(_T("%d"),programnum);
		GetDlgItem(IDC_EDIT12)->SetWindowText(str);//节目个数
		char name[5]={0};
		memcpy(name,pStatus+11,4);
		TCHAR cur_program[5];
		Char2TCHAR(cur_program,sizeof(cur_program),name);
		GetDlgItem(IDC_EDIT13)->SetWindowText(cur_program);//当前节目
		BYTE SpecialDynaArea=pStatus[16];
		str.Format(_T("%d"),SpecialDynaArea);
		((CComboBox*)GetDlgItem(IDC_COMBO14))->SetCurSel(SpecialDynaArea);//特殊动态群
		BYTE PageNum=pStatus[18];
		str.Format(_T("%d"),PageNum);
		GetDlgItem(IDC_EDIT17)->SetWindowText(str);//页数
		BYTE DynaAreaNum=pStatus[17];
		str.Format(_T("%d"),DynaAreaNum);
		GetDlgItem(IDC_EDIT14)->SetWindowText(str);//动态区个数
		for (int i=m_DynaAreaIDList.GetCount();i>0;i--)
		{
			m_DynaAreaIDList.DeleteString(i-1);
		}
		for (int i=0;i<DynaAreaNum;i++)
		{
			str.Format(_T("%d"),pStatus[15+i]);
			m_DynaAreaIDList.AddString(str);
		}
	}
}


void CLed5kSDKDemoDlg::OnBnClickedButton43()
{
	// 设置屏号
	if (m_dwCurHand)
	{	
		CString str;
		GetDlgItem(IDC_EDIT11)->GetWindowText(str);
		USHORT screenid=_tstoi(str);
		int err=CON_SetScreenID(m_dwCurHand,screenid);
		if (err!=0)
		{
			MessageBox(_T("设置屏号失败"));
		}
	}
}


void CLed5kSDKDemoDlg::OnBnClickedButton42()
{
	// 读屏号
	if (m_dwCurHand)
	{	
		USHORT screenid=0;
		int err=CON_ReadScreenID(m_dwCurHand,&screenid);
		if (err==0)
		{
			CString str;
			str.Format(_T("%d"),screenid);
			GetDlgItem(IDC_EDIT11)->SetWindowText(str);		
		}
	}
}


void CLed5kSDKDemoDlg::OnBnClickedButton1()
{
	// ping
	if (m_dwCurHand)
	{	
		int err=CON_PING(m_dwCurHand);
		if (err!=0)
		{	
			MessageBox(_T("ping失败"));
		}
	}
}


void CLed5kSDKDemoDlg::OnBnClickedButton2()
{
	// 复位
	if (m_dwCurHand)
	{	
		int err=CON_Reset(m_dwCurHand);
		if (err!=0)
		{	
			MessageBox(_T("复位失败"));
		}
	}
}


void CLed5kSDKDemoDlg::OnBnClickedButton41()
{
	// 设置亮度
	if (m_dwCurHand)
	{	
		CString str;
		GetDlgItem(IDC_EDIT10)->GetWindowText(str);
		BYTE brightness=_tstoi(str);
		int err=SCREEN_SetBrightness(m_dwCurHand,1,brightness,NULL);
		if (err!=0)
		{
			MessageBox(_T("设置亮度失败"));
		}
	}
}


void CLed5kSDKDemoDlg::OnBnClickedButton31()
{
	// 定时调亮
	if (m_dwCurHand)
	{	
		CString str;
		GetDlgItem(IDC_EDIT10)->GetWindowText(str);
		BYTE brightness[48]={0};
		memset(brightness,10,sizeof(brightness));
		int err=SCREEN_SetBrightness(m_dwCurHand,2,0,brightness);
		if (err!=0)
		{
			MessageBox(_T("设置亮度失败"));
		}
	}
}


void CLed5kSDKDemoDlg::OnBnClickedButton4()
{
	// 校时
	if (m_dwCurHand)
	{	
		int err=CON_SytemClockCorrect(m_dwCurHand);
		if (err!=0)
		{	
			MessageBox(_T("校时失败"));
		}
	}
}


void CLed5kSDKDemoDlg::OnBnClickedButton9()
{
	// 查询固件CON_ControllerStatus
	char name[5]={0};
	char version[9]={0};
	char datetime[20]={0};
	int err=CON_CheckCurrentFirmware(m_dwCurHand,name,version,datetime);
	if (err==NO_ERROR)
	{
		TCHAR buff[20]={0};
		Char2TCHAR(buff,sizeof(buff),name);
		GetDlgItem(IDC_EDIT7)->SetWindowText(buff);
		memset(buff,0,sizeof(buff));
		Char2TCHAR(buff,sizeof(buff),version);
		GetDlgItem(IDC_EDIT8)->SetWindowText(buff);
		memset(buff,0,sizeof(buff));
		Char2TCHAR(buff,sizeof(buff),datetime);
		GetDlgItem(IDC_EDIT9)->SetWindowText(buff);
	}
}


void CLed5kSDKDemoDlg::OnBnClickedButton10()
{
	// 激活固件
	if (m_dwCurHand)
	{	
		CString str;
		char buff[5]={0};
		GetDlgItem(IDC_EDIT7)->GetWindowText(str);
		CString2Char(str,buff);

		int err=CON_FirmwareActivate(m_dwCurHand,buff);
		if (err!=0)
		{	
			MessageBox(_T("激活失败"));
		}
	}
}


void CLed5kSDKDemoDlg::OnBnClickedButton6()
{
	// 开机
	if (m_dwCurHand)
	{	
		int err=SCREEN_ForceOnOff(m_dwCurHand,1);
		if (err!=0)
		{	
			MessageBox(_T("开机失败"));
		}
	}
}


void CLed5kSDKDemoDlg::OnBnClickedButton8()
{
	// 关机
	if (m_dwCurHand)
	{	
		int err=SCREEN_ForceOnOff(m_dwCurHand,2);
		if (err!=0)
		{	
			MessageBox(_T("关机失败"));
		}
	}
}


void CLed5kSDKDemoDlg::OnBnClickedButton40()
{
	// 定时开关机
	BYTE buff[12];
	int pos=0;
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK1);
	if (btn->GetCheck())
	{
		CDateTimeCtrl* pCtrl=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1);
		CTime t1;
		pCtrl->GetTime(t1);
		pCtrl=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER4);
		CTime t2;
		pCtrl->GetTime(t2);
		buff[0]=byte2bcd(t1.GetHour());
		buff[1]=byte2bcd(t1.GetMinute());
		buff[2]=byte2bcd(t2.GetHour());
		buff[3]=byte2bcd(t2.GetMinute());
		pos+=4;
	}
	btn=(CButton*)GetDlgItem(IDC_CHECK2);
	if (btn->GetCheck())
	{
		CDateTimeCtrl* pCtrl=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER2);
		CTime t1;
		pCtrl->GetTime(t1);
		pCtrl=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER5);
		CTime t2;
		pCtrl->GetTime(t2);
		buff[pos+0]=byte2bcd(t1.GetHour());
		buff[pos+1]=byte2bcd(t1.GetMinute());
		buff[pos+2]=byte2bcd(t2.GetHour());
		buff[pos+3]=byte2bcd(t2.GetMinute());
		pos+=4;
	}
	btn=(CButton*)GetDlgItem(IDC_CHECK3);
	if (btn->GetCheck())
	{
		CDateTimeCtrl* pCtrl=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER3);
		CTime t1;
		pCtrl->GetTime(t1);
		pCtrl=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER6);
		CTime t2;
		pCtrl->GetTime(t2);
		buff[pos+0]=byte2bcd(t1.GetHour());
		buff[pos+1]=byte2bcd(t1.GetMinute());
		buff[pos+2]=byte2bcd(t2.GetHour());
		buff[pos+3]=byte2bcd(t2.GetMinute());
		pos+=4;
	}
	if (m_dwCurHand)
	{	
		BYTE pTimer[13]={0};
		pTimer[0]=pos/4;
		memcpy(pTimer+1,buff,pos);
		int err=SCREEN_TimeTurnOnOff(m_dwCurHand,pTimer,pos/4);
		if (err!=0)
		{	
			MessageBox(_T("设定定时开关机失败"));
		}
	}
}


void CLed5kSDKDemoDlg::OnBnClickedCheck1()
{
	// 1
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK1);
	GetDlgItem(IDC_DATETIMEPICKER1)->EnableWindow(btn->GetCheck());
	GetDlgItem(IDC_DATETIMEPICKER4)->EnableWindow(btn->GetCheck());
}


void CLed5kSDKDemoDlg::OnBnClickedCheck2()
{
	// 2
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK2);
	GetDlgItem(IDC_DATETIMEPICKER2)->EnableWindow(btn->GetCheck());
	GetDlgItem(IDC_DATETIMEPICKER5)->EnableWindow(btn->GetCheck());
}


void CLed5kSDKDemoDlg::OnBnClickedCheck3()
{
	// 3
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK3);
	GetDlgItem(IDC_DATETIMEPICKER3)->EnableWindow(btn->GetCheck());
	GetDlgItem(IDC_DATETIMEPICKER6)->EnableWindow(btn->GetCheck());
}


void CLed5kSDKDemoDlg::OnBnClickedButton39()
{
	// 取消定时
	if (m_dwCurHand)
	{	
		int err=SCREEN_CancelTimeOnOff(m_dwCurHand);
		if (err!=0)
		{	
			MessageBox(_T("取消定时失败"));
		}
	}
}

void CLed5kSDKDemoDlg::OnBnClickedButton14()
{
	// 发送节目
	CProgramDlg dlg;
	if (dlg.DoModal()==IDOK)
	{
		GetDlgItem(IDC_EDIT3)->SetWindowText(dlg.m_Name);
		if (m_dwCurHand)
		{	

			if (dlg.m_DisplayMode==1)
			{
				int err=OFS_SendFileData(m_dwCurHand,true,dlg.name,dlg.m_DuringTime,dlg.m_PlayTimes,dlg.ProgramLife,dlg.ProgramWeek,dlg.ProgramTime,dlg.period,dlg.m_AreaNum,dlg.m_AreaListData,dlg.m_AreaListDataLen);
				if (err!=0)
				{	
					MessageBox(_T("发送节目失败"));
				}
			}
			else
			{
			int err=OFS_SendFileData(m_dwCurHand,true,dlg.name,dlg.m_DisplayMode,dlg.m_PlayTimes,dlg.ProgramLife,dlg.ProgramWeek,dlg.ProgramTime,dlg.period,dlg.m_AreaNum,dlg.m_AreaListData,dlg.m_AreaListDataLen);
			if (err!=0)
			{	
				MessageBox(_T("发送节目失败"));
			}
			}

		}
		delete[] dlg.m_AreaListData;
	}

}



void CLed5kSDKDemoDlg::OnBnClickedButton32()
{
	// 锁定节目
	char name[5]={0};
	CString str;
	GetDlgItem(IDC_EDIT3)->GetWindowText(str);
	CString2Char(str,name);
	int err=SCREEN_LockProgram(m_dwCurHand,1,0,name);
	if (err!=0)
	{	
		MessageBox(_T("锁定节目失败"));
	}
}


void CLed5kSDKDemoDlg::OnBnClickedButton34()
{
	// 解锁节目
	char name[5]={0};
	CString str;
	GetDlgItem(IDC_EDIT3)->GetWindowText(str);
	CString2Char(str,name);
	int err=SCREEN_LockProgram(m_dwCurHand,0,0,name);
	if (err!=0)
	{	
		MessageBox(_T("解锁节目失败"));
	}
}


void CLed5kSDKDemoDlg::OnBnClickedButton35()
{
	// 删除节目
	char name[5]={0};
	CString str;
	GetDlgItem(IDC_EDIT3)->GetWindowText(str);
	CString2Char(str,name);
	int err=OFS_DeleteFile(m_dwCurHand,1,name);
	if (err!=0)
	{	
		MessageBox(_T("删除节目失败"));
	}
}


void CLed5kSDKDemoDlg::OnBnClickedButton36()
{
	// 删除所有节目
	int err=OFS_DeleteFile(m_dwCurHand,0,NULL);
	if (err!=0)
	{	
		MessageBox(_T("删除所有节目失败"));
	}
}


void CLed5kSDKDemoDlg::OnBnClickedButton38()
{
	// 格式化
	int err=OFS_Formatting(m_dwCurHand);
	if (err!=0)
	{	
		MessageBox(_T("格式化失败"));
	}
}

void CLed5kSDKDemoDlg::UpdateArea(int areaID)
{
	if(areaID == 0)
	{
		SoundAreaDlg dlg;
		int err;
		if (dlg.DoModal()==IDOK)
		{
			dlg.m_AreaHeader.DynamicAreaLoc=areaID;
			if(dlg.SoundMode == 0)
			{
				err=SCREEN_SendDynamicArea(m_dwCurHand,dlg.m_AreaHeader,dlg.data_len,(BYTE*)dlg.data);
				if (err!=0)
				{	
					MessageBox(_T("更新动态区失败"));
				}
			}
			else
			{
				err=SCREEN_SendSoundDynamicArea(m_dwCurHand,dlg.m_AreaHeader,dlg.data_len,(BYTE*)dlg.data, dlg.SoundMode, dlg.SoundPerson, dlg.SoundVolume, dlg.SoundSpeed, dlg.Sounddata_len, (BYTE*)dlg.Sounddata);
				if (err!=0)
				{	
					MessageBox(_T("更新动态区失败"));
				}
			}	
		}
	}
	else
	{
		CAreaDlg dlg;
		if (dlg.DoModal()==IDOK)
		{
			dlg.m_AreaHeader.DynamicAreaLoc=areaID;

			int err=SCREEN_SendDynamicArea(m_dwCurHand,dlg.m_AreaHeader,dlg.data_len,(BYTE*)dlg.data);
			if (err!=0)
			{	
				MessageBox(_T("更新动态区失败"));
			}
		}
	}
	
}
void CLed5kSDKDemoDlg::OnBnClickedButton18()
{
	UpdateArea(0);
	// 更新动态区1
}

void CLed5kSDKDemoDlg::OnBnClickedButton21()
{
	// 更新动态区2
	UpdateArea(1);
}


void CLed5kSDKDemoDlg::OnBnClickedButton24()
{
	// 更新动态区3
	UpdateArea(2);
}


void CLed5kSDKDemoDlg::OnBnClickedButton27()
{
	// 更新动态区4
	UpdateArea(3);
}


void CLed5kSDKDemoDlg::OnBnClickedButton30()
{
	// 更新动态区5
	UpdateArea(4);
}


void CLed5kSDKDemoDlg::OnBnClickedButton28()
{
	CString tmp;
	GetDlgItem(IDC_EDIT21)->GetWindowText(tmp);
	DWORD nTime=_tstoi(tmp);
	SetTimeout(m_dwCurHand,nTime);
}


void CLed5kSDKDemoDlg::OnBnClickedButton25()
{
	CString tmp;
	GetDlgItem(IDC_EDIT20)->GetWindowText(tmp);
	DWORD nTime=_tstoi(tmp);
	SetTimeout(m_dwCurHand,nTime);
}


void CLed5kSDKDemoDlg::OnBnClickedButton22()
{
	CString tmp;
	GetDlgItem(IDC_EDIT19)->GetWindowText(tmp);
	DWORD nTime=_tstoi(tmp);
	SetTimeout(m_dwCurHand,nTime);
}


void CLed5kSDKDemoDlg::OnBnClickedButton11()
{
	CString tmp;
	GetDlgItem(IDC_EDIT1)->GetWindowText(tmp);
	DWORD nTime=_tstoi(tmp);
	SetTimeout(m_dwCurHand,nTime);
}


void CLed5kSDKDemoDlg::OnBnClickedButton19()
{
	int err=SCREEN_DelDynamicArea(m_dwCurHand,0);
	if (err!=0)
	{	
		MessageBox(_T("删除动态区失败"));
	}
}


void CLed5kSDKDemoDlg::OnBnClickedButton20()
{
	int err=SCREEN_DelDynamicArea(m_dwCurHand,1);
	if (err!=0)
	{	
		MessageBox(_T("删除动态区失败"));
	}
}


void CLed5kSDKDemoDlg::OnBnClickedButton23()
{
	int err=SCREEN_DelDynamicArea(m_dwCurHand,2);
	if (err!=0)
	{	
		MessageBox(_T("删除动态区失败"));
	}
}


void CLed5kSDKDemoDlg::OnBnClickedButton26()
{
	int err=SCREEN_DelDynamicArea(m_dwCurHand,3);
	if (err!=0)
	{	
		MessageBox(_T("删除动态区失败"));
	}
}


void CLed5kSDKDemoDlg::OnBnClickedButton29()
{
	int err=SCREEN_DelDynamicArea(m_dwCurHand,4);
	if (err!=0)
	{	
		MessageBox(_T("删除动态区失败"));
	}
}


void CLed5kSDKDemoDlg::OnBnClickedButton37()
{
	// 固定ip
	CWnd* pWnd=GetDlgItem(IDC_IPADDRESS3);
	CString str;
	pWnd->GetWindowText(str);
	char ip[16]={0};
	CString2Char(str,ip);
	CString tmp;
	GetDlgItem(IDC_EDIT6)->GetWindowText(tmp);
	USHORT port=_tstoi(tmp);
	int sel=((CComboBox*)GetDlgItem(IDC_COMBO11))->GetCurSel();

	//DWORD hand=CreateClient(ip,port,(bx_5k_card_type)gloabl_type[sel],1,NULL);
	//
	//CString tmp;
	//GetDlgItem(IDC_EDIT19)->GetWindowText(tmp);
	//DWORD nTime=_tstoi(tmp);
	//SetTimeout(hand,nTime);


	//
	//m_AreaHeader.AreaX=0;
	//m_AreaHeader.AreaY=0;
	//m_AreaHeader.AreaWidth=32/8;
	//m_AreaHeader.AreaHeight=32;
	//m_AreaHeader.Timeout=10;
	//m_AreaHeader.StayTime=10;
	//m_AreaHeader.Lines_sizes=1;

	//m_AreaHeader.NewLine=1;
	//m_AreaHeader.DisplayMode=1;
	//m_AreaHeader.Speed=1;
	//m_AreaHeader.RunMode=0;
	//m_AreaHeader.SingleLine=1;
	//m_AreaHeader.AreaType=6;
	//m_AreaHeader.ExitMode=0;

	//SoundMode = m_cmbSoundMode.GetCurSel();
	//SoundPerson = m_cmbSoundPerson.GetCurSel();
	//SoundVolume = m_cmbSoundVolume.GetCurSel();
	//SoundSpeed = m_cmbSoundSpeed.GetCurSel();

	//memset(Sounddata,0,sizeof(Sounddata));
	//CString2Char(m_SoundText,Sounddata);
	//Sounddata_len=strlen(Sounddata); 
	//

	//memset(m_AreaHeader.Reserved,0,sizeof(m_AreaHeader.Reserved));

	//memset(data,0,sizeof(data));
	//CString2Char(m_Text,data);
	//data_len=strlen(data);
	//m_AreaHeader.DataLen=data_len;

	
	Destroy(m_dwCurHand);
}


void CLed5kSDKDemoDlg::OnBnClickedButton45()
{
	int err=SCREEN_DelDynamicArea(m_dwCurHand,5);
	if (err!=0)
	{	
		MessageBox(_T("删除动态区失败"));
	}
}
void WINAPI CallBackLedClose(DWORD dwHand,unsigned char* imei,int err)
{
	theApp.GetMainWnd()->SendMessage(WM_LED_CLOSE,(WPARAM)imei,(LPARAM)dwHand);
}
void WINAPI CallBackCon(DWORD dwHand,unsigned char* imei)
{
	theApp.GetMainWnd()->SendMessage(WM_LED_CONNECT,(WPARAM)imei,(LPARAM)dwHand);
}

void CLed5kSDKDemoDlg::OnBnClickedButton13()
{
	CString tmp;
	GetDlgItem(IDC_EDIT25)->GetWindowText(tmp);
	DWORD port=_tstoi(tmp);
	if (StartGprsServer(port,CallBackCon,CallBackLedClose))
	{
		GetDlgItem(IDC_BUTTON13)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON15)->EnableWindow(TRUE);
	}
}


void CLed5kSDKDemoDlg::OnBnClickedButton16()
{
	CString tmp;
	GetDlgItem(IDC_EDIT26)->GetWindowText(tmp);
	DWORD port=_tstoi(tmp);
	if(StartServer(port,CallBackCon,CallBackLedClose))
	{
		GetDlgItem(IDC_BUTTON16)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON17)->EnableWindow(TRUE);
	}
}


void CLed5kSDKDemoDlg::OnBnClickedButton15()
{
	CloseGprsServer();
	GetDlgItem(IDC_BUTTON13)->EnableWindow(TRUE);
}


void CLed5kSDKDemoDlg::OnBnClickedButton17()
{
	CloseServer();
	GetDlgItem(IDC_BUTTON16)->EnableWindow(TRUE);
}
LRESULT CLed5kSDKDemoDlg::OnLedConnect(WPARAM w,LPARAM l)
{
	DWORD dwHand=(DWORD)l;
	char *imei=(char*)w;
	TCHAR netid[13]={0};
	Char2TCHAR(netid,sizeof(netid),imei);
	int item=m_cmbGprsList.AddString(netid);
	m_cmbGprsList.SetItemData(item,dwHand);
	return 1;
}
LRESULT CLed5kSDKDemoDlg::OnLedClose(WPARAM w,LPARAM l)
{
	DWORD dwHand=(DWORD)l;
	for (int i=0;i<m_cmbGprsList.GetCount();i++)
	{
		if (m_cmbGprsList.GetItemData(i)==dwHand)
		{
			m_cmbGprsList.DeleteString(i);
			break;
		}
	}

	return 1;
}
LRESULT CLed5kSDKDemoDlg::OnGprsConnect(WPARAM w,LPARAM l)
{
	DWORD dwHand=(DWORD)l;
	char *imei=(char*)w;
	TCHAR netid[12]={0};
	Char2TCHAR(netid,sizeof(netid),imei);
	int item=m_cmbClientList.AddString(netid);
	m_cmbClientList.SetItemData(item,dwHand);
	return 1;
}
LRESULT CLed5kSDKDemoDlg::OnGprsClose(WPARAM w,LPARAM l)
{
	DWORD dwHand=(DWORD)l;
	for (int i=0;i<m_cmbClientList.GetCount();i++)
	{
		if (m_cmbClientList.GetItemData(i)==dwHand)
		{
			m_cmbClientList.DeleteString(i);
			break;
		}
	}
	return 1;
}

void CLed5kSDKDemoDlg::OnBnClickedButton47()
{
	CString tmp;
	GetDlgItem(IDC_EDIT24)->GetWindowText(tmp);
	DWORD tic=_tstoi(tmp);
	SetGprsAliveTick(m_dwCurHand,tic);
}


void CLed5kSDKDemoDlg::OnBnClickedButton48()
{
	CString tmp;
	GetDlgItem(IDC_EDIT27)->GetWindowText(tmp);
	DWORD tic=_tstoi(tmp);
	SetLedAliveTick(m_dwCurHand,tic);
}


void CLed5kSDKDemoDlg::OnCbnSelchangeCombo17()
{
	m_dwCurHand=m_cmbGprsList.GetItemData(m_cmbGprsList.GetCurSel());
	GetDlgItem(IDC_BUTTON47)->EnableWindow(TRUE);
}


void CLed5kSDKDemoDlg::OnCbnSelchangeCombo18()
{
	m_dwCurHand=m_cmbClientList.GetItemData(m_cmbClientList.GetCurSel());
	GetDlgItem(IDC_BUTTON48)->EnableWindow(TRUE);
}
