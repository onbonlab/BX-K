
// Led5kSDKDemoDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CLed5kSDKDemoDlg 对话框
class CLed5kSDKDemoDlg : public CDialogEx
{
// 构造
public:
	CLed5kSDKDemoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LED5KSDKDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton33();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton46();
public:
	DWORD m_dwCurHand;
	afx_msg void OnClose();
	afx_msg void OnBnClickedButton44();
	CListBox m_DynaAreaIDList;
	afx_msg void OnBnClickedButton43();
	afx_msg void OnBnClickedButton42();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton41();
	afx_msg void OnBnClickedButton31();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton40();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedButton39();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton32();
	afx_msg void OnBnClickedButton34();
	afx_msg void OnBnClickedButton35();
	afx_msg void OnBnClickedButton36();
	afx_msg void OnBnClickedButton38();
	afx_msg void OnBnClickedButton21();
	afx_msg void OnBnClickedButton24();
	afx_msg void OnBnClickedButton27();
	afx_msg void OnBnClickedButton30();
	afx_msg void OnBnClickedButton28();
	afx_msg void OnBnClickedButton25();
	afx_msg void OnBnClickedButton22();
	afx_msg void OnBnClickedButton11();
	void UpdateArea(int areaID);
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton23();
	afx_msg void OnBnClickedButton26();
	afx_msg void OnBnClickedButton29();
	afx_msg void OnBnClickedButton37();
	afx_msg void OnBnClickedButton45();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton17();
	afx_msg LRESULT OnLedConnect(WPARAM w,LPARAM l);
	afx_msg LRESULT OnLedClose(WPARAM w,LPARAM l);
	afx_msg LRESULT OnGprsConnect(WPARAM w,LPARAM l);
	afx_msg LRESULT OnGprsClose(WPARAM w,LPARAM l);
	CComboBox m_cmbGprsList;
	CComboBox m_cmbClientList;
	afx_msg void OnBnClickedButton47();
	afx_msg void OnBnClickedButton48();
	afx_msg void OnCbnSelchangeCombo17();
	afx_msg void OnCbnSelchangeCombo18();
//public:
//	bx_5k_area_header m_AreaHeader;
//	CComboBox m_cmbSinglLine;
//	CComboBox m_cmbNewLine;
//	CComboBox m_cmbDisplayMode;
//	CComboBox m_cmdSpeed;
//	CComboBox m_cmbSoundMode;
//	CComboBox m_cmbSoundPerson;
//	CComboBox m_cmbSoundVolume;
//	CComboBox m_cmbSoundSpeed;
//	CString m_SoundText;
//	char Sounddata[1024*64];
//	int Sounddata_len;
//	CString m_Text;
//	char data[1024*64];
//	DWORD data_len;
};
