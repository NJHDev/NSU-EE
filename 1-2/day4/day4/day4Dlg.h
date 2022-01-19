
// day4Dlg.h : 헤더 파일
//

#pragma once


// Cday4Dlg 대화 상자
class Cday4Dlg : public CDialogEx
{
// 생성입니다.
public:
	Cday4Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DAY4_DIALOG };

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
	CString m_sTime;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CString m_sCount;
//	int m_iInterval;
	CButton m_cStartTime;
	CButton m_cStopTime;
	int m_iInterval;
	afx_msg void OnChangeInterval();
	afx_msg void OnClickedStarttime();
private:
	int m_iCount;
public:
	afx_msg void OnClickedStoptimer();
	afx_msg void OnClickedExit();
};
