
// Led5kSDKDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CLed5kSDKDemoApp:
// �йش����ʵ�֣������ Led5kSDKDemo.cpp
//

class CLed5kSDKDemoApp : public CWinApp
{
public:
	CLed5kSDKDemoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CLed5kSDKDemoApp theApp;

void Char2TCHAR(TCHAR *pwstr,size_t len,const char *str);
void CString2Char(CString str, char ch[]);
BYTE byte2bcd(BYTE num);
BYTE bcd2byte(BYTE num);
USHORT short2bcd(USHORT num);