
// Led5kSDKDemo.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CLed5kSDKDemoApp:
// 有关此类的实现，请参阅 Led5kSDKDemo.cpp
//

class CLed5kSDKDemoApp : public CWinApp
{
public:
	CLed5kSDKDemoApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CLed5kSDKDemoApp theApp;

void Char2TCHAR(TCHAR *pwstr,size_t len,const char *str);
void CString2Char(CString str, char ch[]);
BYTE byte2bcd(BYTE num);
BYTE bcd2byte(BYTE num);
USHORT short2bcd(USHORT num);