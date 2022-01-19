#pragma once


// CPaintDlg 대화 상자입니다.

class CPaintDlg : public CDialog
{
	DECLARE_DYNAMIC(CPaintDlg)

public:
	CPaintDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CPaintDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_PAINT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
