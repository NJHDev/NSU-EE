
// day5Dlg.h : ��� ����
//

#pragma once
#include "msgdlg.h"


// Cday5Dlg ��ȭ ����
class Cday5Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	Cday5Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DAY5_DIALOG };

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
