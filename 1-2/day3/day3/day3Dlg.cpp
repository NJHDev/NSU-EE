
// day3Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "day3.h"
#include "day3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cday3Dlg ��ȭ ����




Cday3Dlg::Cday3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cday3Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_iPrevY = 0;
	m_iPrevX = 0;
}

void Cday3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cday3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// Cday3Dlg �޽��� ó����

BOOL Cday3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	//Ŀ���� ȭ��ǥ�� �ʱ�ȭ
	m_bCursor = FALSE;

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void Cday3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void Cday3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR Cday3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cday3Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	//���ʸ��콺 ��ư üũ
	if ((nFlags & MK_LBUTTON) == MK_LBUTTON)
	{
		//����̽� ���ؽ�Ʈ ���
		CClientDC dc(this);

		//�ٷ� ������ ���� ���� �� ���� ����
		dc.MoveTo(m_iPrevX, m_iPrevY);
		dc.LineTo(point.x, point.y);

		//���� ���� (������) ���� ������ ����
		m_iPrevX = point.x;
		m_iPrevY = point.y;
	}

	CDialogEx::OnMouseMove(nFlags, point);
}


void Cday3Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	//������ ���� ���������� ����
	m_iPrevX = point.x;
	m_iPrevY = point.y;

	CDialogEx::OnLButtonDown(nFlags, point);
}


void Cday3Dlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	char lsChar;					 //���� ���� Ű �ڵ�
	HCURSOR lhCursor;		//ǥ�õ� Ŀ���� �ڵ�

	//Ű�ڵ� to ����
	lsChar = char(nChar);

	//A ����??
	if ( lsChar == 'A' )
	{
		//ȭ��ǥ Ŀ��
		lhCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		//ȭ�� Ŀ�� ����
		SetCursor(lhCursor);
	}

	//B ����?
	if ( lsChar == 'B' )
	{
		//I�� ����
		lhCursor = AfxGetApp()->LoadStandardCursor(IDC_IBEAM);
		//ȭ�� Ŀ�� ����
		SetCursor(lhCursor);
	}

	//C ����?
	if ( lsChar == 'C' )
	{
		//I�� ����
		lhCursor = AfxGetApp()->LoadStandardCursor(IDC_WAIT);
		//ȭ�� Ŀ�� ����
		SetCursor(lhCursor);
	}

	//X ����?
	if ( lsChar == 'X' )
	{
		//ȭ��ǥ Ŀ��
		lhCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		//Ŀ�� �÷��� ����
		m_bCursor = TRUE;
		//ȭ�� Ŀ�� ����
		SetCursor(lhCursor);
		//����
		OnOK();
	}
	else
	{
		//Ŀ�� �÷��� ����
		m_bCursor = TRUE;
		//ȭ�� Ŀ�� ����
		SetCursor(lhCursor);
	}

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL Cday3Dlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	//TRUEĿ�� ���� -> TRUE ��ȯ
	if (m_bCursor)
		return TRUE;
	else

	return CDialogEx::OnSetCursor(pWnd, nHitTest, message);
}
