
// day4Dlg.h : ��� ����
//

#pragma once


// Cday4Dlg ��ȭ ����
class Cday4Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	Cday4Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DAY4_DIALOG };

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
