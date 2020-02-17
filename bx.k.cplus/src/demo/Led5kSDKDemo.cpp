
// Led5kSDKDemo.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "Led5kSDKDemo.h"
#include "Led5kSDKDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLed5kSDKDemoApp

BEGIN_MESSAGE_MAP(CLed5kSDKDemoApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CLed5kSDKDemoApp 构造

CLed5kSDKDemoApp::CLed5kSDKDemoApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CLed5kSDKDemoApp 对象

CLed5kSDKDemoApp theApp;


// CLed5kSDKDemoApp 初始化

BOOL CLed5kSDKDemoApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	CLed5kSDKDemoDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}


void CString2Char(CString str, char ch[])
{
#ifdef _UNICODE
	int i;
	char *tmpch;
	int wLen = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);//得到Char的长度
	tmpch = new char[wLen + 1];                                             //分配变量的地址大小
	WideCharToMultiByte(CP_ACP, 0, str, -1, tmpch, wLen, NULL, NULL);       //将CString转换成char*

	for(i = 0; tmpch[i] != '\0'; i++) ch[i] = tmpch[i];
	ch[i] = '\0';
	delete tmpch;
#else
	strcpy(ch,str.GetBuffer());
#endif
}
/*/////
pwstr 输入缓冲
len   输入缓冲长度
*/////
void Char2TCHAR(TCHAR *pwstr,size_t len,const char *str)
{
#ifdef _UNICODE
	if(str)
	{
		size_t nu = strlen(str);
		size_t n =(size_t)MultiByteToWideChar(CP_ACP,0,(const char *)str,(int)nu,NULL,0);
		if(n>=len)
			n=len-1;
		memset(pwstr,0,len);
		MultiByteToWideChar(CP_ACP,0,(const char *)str,(int)nu,pwstr,(int)n);
	}
#else
	strcpy(pwstr,str);
#endif
}


BYTE byte2bcd(BYTE num)
{
	return num/10*16+num%10;
}
BYTE bcd2byte(BYTE num)
{
	return num/16*10+num%16;
}
USHORT short2bcd(USHORT num)
{
	BYTE high=num/100;
	BYTE low=num%100;
	return byte2bcd(high)*256+byte2bcd(low);
}