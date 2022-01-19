
// finalDlg.h : 헤더 파일
//

#pragma once
#include "userdlg.h"


// CfinalDlg 대화 상자
class CfinalDlg : public CDialogEx
{
// 생성입니다.
public:
	CfinalDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FINAL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strMessage;
	afx_msg void OnClickedCancel();
	afx_msg void OnClickedShwmsg();
	afx_msg void OnClickedClrmsg();
	afx_msg void OnClickedDfltmsg();
	CString m_sTime;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	BOOL m_check;
	afx_msg void OnBnClickedCheck();
protected:
//	CUSERDlg m_dUserDlg;
public:
	afx_msg void OnClickedUserdlg();
	CString m_sResults;
	afx_msg void OnClickedSelopt();
	char gender;
private:
	CUSERDlg m_dUserDlg;
public:
//	CEdit m_sMessage;
	CString m_sMessage;
};
