#pragma once


// CUSERDlg ��ȭ �����Դϴ�.

class CUSERDlg : public CDialog
{
	DECLARE_DYNAMIC(CUSERDlg)

public:
	CUSERDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CUSERDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_USERDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
