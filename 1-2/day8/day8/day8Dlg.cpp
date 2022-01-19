
// day8Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "day8.h"
#include "PaintDlg.h"
#include "day8Dlg.h"
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


// Cday8Dlg ��ȭ ����




Cday8Dlg::Cday8Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cday8Dlg::IDD, pParent)
	, m_dlgPaint(0)
	, m_sBitmap(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_iShape = 0;
	m_iTool = 0;
	m_iColor = 0;
}

void Cday8Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Radio(pDX, IDC_RTPEN, m_iTool);
	DDX_Radio(pDX, IDC_RSLINE, m_iShape);
	DDX_Radio(pDX, IDC_RTPEN, m_iTool);
	DDX_Radio(pDX, IDC_RCBLACK, m_iColor);
}

BEGIN_MESSAGE_MAP(Cday8Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BEXIT, &Cday8Dlg::OnClickedBexit)
	ON_BN_CLICKED(IDC_RCBLACK, &Cday8Dlg::OnClickedRcblack)
	ON_COMMAND(IDC_RCBLUE, &Cday8Dlg::OnRcblue)
	ON_COMMAND(IDC_RCCYAN, &Cday8Dlg::OnRccyan)
	ON_COMMAND(IDC_RCGREEN, &Cday8Dlg::OnRcgreen)
	ON_COMMAND(IDC_RCMAGENTA, &Cday8Dlg::OnRcmagenta)
	ON_COMMAND(IDC_RCRED, &Cday8Dlg::OnRcred)
	ON_COMMAND(IDC_RCWHITE, &Cday8Dlg::OnRcwhite)
	ON_COMMAND(IDC_RCYELLOW, &Cday8Dlg::OnRcyellow)
	ON_COMMAND(IDC_RSCIRCLE, &Cday8Dlg::OnRscircle)
	ON_BN_CLICKED(IDC_RSLINE, &Cday8Dlg::OnClickedRsline)
	ON_COMMAND(IDC_RSSQUARE, &Cday8Dlg::OnRssquare)
	ON_COMMAND(IDC_RTBITMAP, &Cday8Dlg::OnRtbitmap)
	ON_COMMAND(IDC_RTBRUSH, &Cday8Dlg::OnRtbrush)
	ON_BN_CLICKED(IDC_RTPEN, &Cday8Dlg::OnClickedRtpen)
	ON_BN_CLICKED(IDC_BBITMAP, &Cday8Dlg::OnClickedBbitmap)
END_MESSAGE_MAP()


// Cday8Dlg �޽��� ó����

BOOL Cday8Dlg::OnInitDialog()
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
	m_iColor = 0;
	m_iShape = 0;
	m_iTool = 0;
	UpdateData(FALSE);

	m_dlgPaint.Create(IDD_PAINT_DLG, this);
	m_dlgPaint.ShowWindow(SW_SHOW);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void Cday8Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cday8Dlg::OnPaint()
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
HCURSOR Cday8Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Cday8Dlg::OnClickedBexit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}


void Cday8Dlg::OnClickedRcblack()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnRcblue()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnRccyan()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnRcgreen()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnRcmagenta()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnRcred()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnRcwhite()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnRcyellow()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnRscircle()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnClickedRsline()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnRssquare()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnRtbitmap()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnRtbrush()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnClickedRtpen()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnClickedBbitmap()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	// ���� ���� ���̾�α׿� ���� ���͸� ���ڿ��� �����.
	//static char BASED_CODE szFilter[]="Bitmap Files (*.bmp)|*.bmp||";
	//���� ���� ���̾�α׸� �����Ѵ�.
	CFileDialog m_ldFile(TRUE);
	/*, ".bmp", m_sBitmap,
		OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,szFilter);
	*/

	//���� ���� ���̾�α׸� ���̰� ������� ��´�.
	if(m_ldFile.DoModal()==IDOK)
	{
		//���õ� ���� �̸��� ��´�.
		m_sBitmap = m_ldFile.GetPathName();
		//���õ� ��Ʈ�� ������ �ε��Ѵ�.
		HBITMAP hBitmap=(HBITMAP) ::LoadImage(AfxGetInstanceHandle(),m_sBitmap, IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
		if(hBitmap)
		{
			if(m_bmpBitmap.DeleteObject())
				m_bmpBitmap.Detach();
			//���� �ε�� ��Ʈ���� CBitmap ��ü�� �����Ѵ�.
			m_bmpBitmap.Attach(hBitmap);
		}
		//�ι�° ���̾�α� �����츦 ��ȿȭ�Ѵ�.
		m_dlgPaint.Invalidate();
	}
}
