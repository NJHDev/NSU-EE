
// finalDlg.h : ��� ����
//

#pragma once
#include "userdlg.h"


// CfinalDlg ��ȭ ����
class CfinalDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CfinalDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FINAL_DIALOG };

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
