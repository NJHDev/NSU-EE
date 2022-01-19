
// day7Dlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"

//폰트 불러오기
int CALLBACK EnumFontFamProc(LPENUMLOGFONT lpelf,
	LPNEWTEXTMETRIC lpntm, DWORD nFontType, long lParam);

// Cday7Dlg 대화 상자
class Cday7Dlg : public CDialogEx
{
// 생성입니다.
public:
	Cday7Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DAY7_DIALOG };

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
	CStatic m_ctlDisplayText;
	CString m_strDisplayText;
	CString m_strSampText;
	CListBox m_ctlFontList;
	CString m_strFontName;
	afx_msg void OnClickedExit();
private:
	void FillFontList(void);
public:
	afx_msg void OnChangeEsamptext();
public:
	afx_msg void OnSelchangeLfonts();
};
