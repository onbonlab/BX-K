#pragma once
#include "..\\include\\Led5kSDK.h"
#include "afxwin.h"

// CProgramDlg �Ի���

class CProgramDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CProgramDlg)

public:
	CProgramDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CProgramDlg();

// �Ի�������
	enum { IDD = IDD_PROGRAMDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedCheck9();
	afx_msg void OnBnClickedCheck8();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedCheck10();
	afx_msg void OnDestroy();
	virtual BOOL OnInitDialog();
public:
	CString m_Name;
	CListBox m_AreaList;

	char name[5];
	int m_DisplayMode;
	BYTE m_PlayTimes;
	BYTE m_DuringTime;
	BYTE ProgramLife[8];
	BYTE ProgramWeek;
	BYTE ProgramTime;
	BYTE period[7];
	BYTE* m_AreaListData;
	int m_AreaListDataLen;
	int m_AreaNum;
};
