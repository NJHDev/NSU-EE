#pragma once


// CPaintDlg ��ȭ �����Դϴ�.

class CPaintDlg : public CDialog
{
	DECLARE_DYNAMIC(CPaintDlg)

public:
	CPaintDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPaintDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PAINT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	static const COLORREF m_crColors[8];
private:
	void DrawLine(CPaintDC* pdc, int iColor);
public:
	afx_msg void OnPaint();
private:
	void DrawRegion(CPaintDC* pdc, int iColor, int iTool, int iShape);
	void ShowBitmap(CPaintDC* pdc, CWnd* pWnd);
};
