
// day2Dlg.h : 헤더 파일
//

#pragma once


// Cday2Dlg 대화 상자
class Cday2Dlg : public CDialogEx
{
// 생성입니다.
public:
	Cday2Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DAY2_DIALOG };

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
	CString m_strProgToRun;
	BOOL m_bEnableMsg;
	BOOL m_bEnablePgm;
	BOOL m_bShowMsg;
	BOOL m_bShowPgm;
	afx_msg void OnClickedExit();
	afx_msg void OnClickedShwmsg();
	afx_msg void OnClickedClrmsg();
	afx_msg void OnClickedDflmsg();
	afx_msg void OnClickedRunpgm();
	afx_msg void OnClickedCkenblmsg();
	afx_msg void OnClickedCkenblpgm();
	afx_msg void OnClickedCkshwmsg();
	afx_msg void OnClickedCkshwpgm();
};
