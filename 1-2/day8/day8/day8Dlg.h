
// day8Dlg.h : ��� ����
//

#pragma once
#include "paintdlg.h"
#include "afxwin.h"


// Cday8Dlg ��ȭ ����
class Cday8Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	Cday8Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DAY8_DIALOG };

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
//	BOOL m_iTool;
	int m_iShape;
	int m_iTool;
	int m_iColor;
	afx_msg void OnClickedBexit();
	CPaintDlg m_dlgPaint;
	afx_msg void OnClickedRcblack();
	afx_msg void OnRcblue();
	afx_msg void OnRccyan();
	afx_msg void OnRcgreen();
	afx_msg void OnRcmagenta();
	afx_msg void OnRcred();
	afx_msg void OnRcwhite();
	afx_msg void OnRcyellow();
	afx_msg void OnRscircle();
	afx_msg void OnClickedRsline();
	afx_msg void OnRssquare();
	afx_msg void OnRtbitmap();
	afx_msg void OnRtbrush();
	afx_msg void OnClickedRtpen();
	CString m_sBitmap;
	CBitmap m_bmpBitmap;
	afx_msg void OnClickedBbitmap();
};
