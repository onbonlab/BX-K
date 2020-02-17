#pragma once

#include "..\\include\\Led5kSDK.h"
// CStaticAreaDlg 对话框

class CStaticAreaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStaticAreaDlg)

public:
	CStaticAreaDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStaticAreaDlg();

// 对话框数据
	enum { IDD = IDD_STATICAREADLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
public:
	bx_5k_area_header m_AreaHeader;
	short m_X;
	short m_Y;
	short m_W;
	short m_H;
	BYTE m_LineInterval;
	BYTE m_StayTime;
	CComboBox m_cmbSinglLine;
	CComboBox m_cmbNewLine;
	CComboBox m_cmbDisplayMode;
	CComboBox m_cmdSpeed;
	CString m_Text;
	char data[1024];
	DWORD data_len;
	virtual BOOL OnInitDialog();
	CString m_Name;
};
