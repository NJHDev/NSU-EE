
// midDlg.h : ��� ����
//

#pragma once


// CmidDlg ��ȭ ����
class CmidDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CmidDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MID_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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
