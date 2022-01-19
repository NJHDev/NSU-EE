
// midDlg.h : 헤더 파일
//

#pragma once


// CmidDlg 대화 상자
class CmidDlg : public CDialogEx
{
// 생성입니다.
public:
	CmidDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MID_DIALOG };

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
	afx_msg void OnBnClickedExit();
	CString m_sTime;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CString m_strMessage;
	BOOL m_bEnableTime;
	BOOL m_bShowMsg;
//	CButton m_bShowTime;
	BOOL m_bShowTime;
//	CButton m_bEnableMsg;
//	BOOL m_m_bEnableMsg;
	BOOL m_bEnableMsg;
	afx_msg void OnEnChangeMsg();
	afx_msg void OnBnClickedShwmsg();
	afx_msg void OnBnClickedClrmsg();
	afx_msg void OnBnClickedCkenbtime();
	afx_msg void OnBnClickedCkenbmsg();
	afx_msg void OnBnClickedCkshwtime();
	afx_msg void OnBnClickedCkshwmsg();
	afx_msg void OnBnClickedDfltmsg();
	afx_msg void OnStnClickedStatictime();
};
