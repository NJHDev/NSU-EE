
// day2Dlg.h : ��� ����
//

#pragma once


// Cday2Dlg ��ȭ ����
class Cday2Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	Cday2Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DAY2_DIALOG };

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
