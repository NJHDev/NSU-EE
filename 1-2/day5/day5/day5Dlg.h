
// day5Dlg.h : 헤더 파일
//

#pragma once
#include "msgdlg.h"


// Cday5Dlg 대화 상자
class Cday5Dlg : public CDialogEx
{
// 생성입니다.
public:
	Cday5Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DAY5_DIALOG };

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
	CButton m_cWhichOption;
	afx_msg void OnClickedYesnocancel();
	afx_msg void OnBnClickedAbortretryignore();
	afx_msg void OnClickedFileopen();
	afx_msg void OnClickedBcustomdialog();
	afx_msg void OnClickedBwhichoption();
	afx_msg void OnClickedExit();
	CString m_sResults;
private:
	CMsgDlg m_dMsgDlg;
};
