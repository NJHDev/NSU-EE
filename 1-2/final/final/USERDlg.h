#pragma once


// CUSERDlg 대화 상자입니다.

class CUSERDlg : public CDialog
{
	DECLARE_DYNAMIC(CUSERDlg)

public:
	CUSERDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CUSERDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_USERDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
//	int m_gender;
//	int m_iinterval;
//	CButton m_cstop;
	CButton m_cstart;
	CButton m_cstop;
	int m_iinterval;
	CString m_scount;
	BOOL m_igen;
	BOOL m_bsoc;
	BOOL m_bbas;
	afx_msg void OnBnClickedStarttime();
};
