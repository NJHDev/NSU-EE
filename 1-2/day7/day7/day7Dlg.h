
// day7Dlg.h : ��� ����
//

#pragma once
#include "afxwin.h"

//��Ʈ �ҷ�����
int CALLBACK EnumFontFamProc(LPENUMLOGFONT lpelf,
	LPNEWTEXTMETRIC lpntm, DWORD nFontType, long lParam);

// Cday7Dlg ��ȭ ����
class Cday7Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	Cday7Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DAY7_DIALOG };

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
