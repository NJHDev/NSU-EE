
// day6Dlg.h : ��� ����
//

#pragma once


// Cday6Dlg ��ȭ ����
class Cday6Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	Cday6Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DAY6_DIALOG };

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
	afx_msg void OnClickedHello();
	afx_msg void OnFileHello();
	afx_msg void OnFileExit();
	afx_msg void OnHelpAbout();
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
};
