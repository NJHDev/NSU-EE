
// day6Dlg.h : 헤더 파일
//

#pragma once


// Cday6Dlg 대화 상자
class Cday6Dlg : public CDialogEx
{
// 생성입니다.
public:
	Cday6Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DAY6_DIALOG };

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
	afx_msg void OnClickedHello();
	afx_msg void OnFileHello();
	afx_msg void OnFileExit();
	afx_msg void OnHelpAbout();
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
};
