
// day2Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "day2.h"
#include "day2Dlg.h"
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


// Cday2Dlg ��ȭ ����




Cday2Dlg::Cday2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cday2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strMessage = _T("");
	m_strProgToRun = _T("");
}

void Cday2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MSG, m_strMessage);
	DDX_CBString(pDX, IDC_PROGTORUN, m_strProgToRun);
	DDX_Check(pDX, IDC_CKENBLMSG, m_bEnableMsg);
	DDX_Check(pDX, IDC_CKENBLPGM, m_bEnablePgm);
	DDX_Check(pDX, IDC_CKSHWMSG, m_bShowMsg);
	DDX_Check(pDX, IDC_CKSHWPGM, m_bShowPgm);
}

BEGIN_MESSAGE_MAP(Cday2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, &Cday2Dlg::OnClickedExit)
	ON_BN_CLICKED(IDC_SHWMSG, &Cday2Dlg::OnClickedShwmsg)
	ON_BN_CLICKED(IDC_CLRMSG, &Cday2Dlg::OnClickedClrmsg)
	ON_BN_CLICKED(IDC_DFLMSG, &Cday2Dlg::OnClickedDflmsg)
	ON_BN_CLICKED(IDC_RUNPGM, &Cday2Dlg::OnClickedRunpgm)
	ON_BN_CLICKED(IDC_CKENBLMSG, &Cday2Dlg::OnClickedCkenblmsg)
	ON_BN_CLICKED(IDC_CKENBLPGM, &Cday2Dlg::OnClickedCkenblpgm)
	ON_BN_CLICKED(IDC_CKSHWMSG, &Cday2Dlg::OnClickedCkshwmsg)
	ON_BN_CLICKED(IDC_CKSHWPGM, &Cday2Dlg::OnClickedCkshwpgm)
END_MESSAGE_MAP()


// Cday2Dlg �޽��� ó����

BOOL Cday2Dlg::OnInitDialog()
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
	//����Ʈ �޽���
	m_strMessage = "Please a Message here.";

	//üũ�ڽ� üũ
	m_bShowMsg = TRUE;
	m_bShowPgm = TRUE;
	m_bEnableMsg = TRUE;
	m_bEnablePgm = TRUE;

	//���̾�α� ��Ʈ�� ��
	UpdateData(FALSE);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void Cday2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cday2Dlg::OnPaint()
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
HCURSOR Cday2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Cday2Dlg::OnClickedExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}


void Cday2Dlg::OnClickedShwmsg()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	MessageBox(m_strMessage);
}


void Cday2Dlg::OnClickedDflmsg()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_strMessage = "Please a Message here.";

	UpdateData(FALSE);
}


void Cday2Dlg::OnClickedClrmsg()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_strMessage = "";

	UpdateData(FALSE);
}


void Cday2Dlg::OnClickedRunpgm()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	
	CString strPgmName;

	strPgmName = m_strProgToRun;

	if (strPgmName == "�޸���")
		WinExec("C:\\Windows\\system32\\notepad.exe", SW_SHOW);

	else if (strPgmName == "�׸���")
		WinExec("C:\\Windows\\system32\\mspaint.exe", SW_SHOW);

	else if (strPgmName == "����")
		WinExec("C:\\Windows\\System32\\calc.exe", SW_SHOW);
	else
		MessageBox(L"���α׷��� �����ϼ���.");
}


void Cday2Dlg::OnClickedCkenblmsg()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	if (m_bEnableMsg ==TRUE)
	{
		GetDlgItem(IDC_MSG) -> EnableWindow(TRUE);
		GetDlgItem(IDC_SHWMSG) -> EnableWindow(TRUE);
		GetDlgItem(IDC_DFLMSG) -> EnableWindow(TRUE);
		GetDlgItem(IDC_CLRMSG) -> EnableWindow(TRUE);
		GetDlgItem(IDC_STATICMSG) -> EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_MSG) -> EnableWindow(FALSE);
		GetDlgItem(IDC_SHWMSG) -> EnableWindow(FALSE);
		GetDlgItem(IDC_DFLMSG) -> EnableWindow(FALSE);
		GetDlgItem(IDC_CLRMSG) -> EnableWindow(FALSE);
		GetDlgItem(IDC_STATICMSG) -> EnableWindow(FALSE);
	}
}


void Cday2Dlg::OnClickedCkenblpgm()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	if (m_bEnablePgm ==TRUE)
	{
		GetDlgItem(IDC_PROGTORUN) -> EnableWindow(TRUE);
		GetDlgItem(IDC_RUNPGM) -> EnableWindow(TRUE);
		GetDlgItem(IDC_STATICPGM) -> EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_PROGTORUN) -> EnableWindow(FALSE);
		GetDlgItem(IDC_RUNPGM) -> EnableWindow(FALSE);
		GetDlgItem(IDC_STATICPGM) -> EnableWindow(FALSE);
	}
}

void Cday2Dlg::OnClickedCkshwmsg()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	if (m_bShowMsg == TRUE)
	{
		GetDlgItem(IDC_MSG)->ShowWindow(TRUE);
		GetDlgItem(IDC_SHWMSG)->ShowWindow(TRUE);
		GetDlgItem(IDC_DFLMSG)->ShowWindow(TRUE);
		GetDlgItem(IDC_CLRMSG)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATICMSG)->ShowWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_MSG)->ShowWindow(FALSE);
		GetDlgItem(IDC_SHWMSG)->ShowWindow(FALSE);
		GetDlgItem(IDC_DFLMSG)->ShowWindow(FALSE);
		GetDlgItem(IDC_CLRMSG)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATICMSG)->ShowWindow(FALSE);
	}
}

void Cday2Dlg::OnClickedCkshwpgm()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	if (m_bShowPgm ==TRUE)
	{
		GetDlgItem(IDC_PROGTORUN)->ShowWindow(TRUE);
		GetDlgItem(IDC_RUNPGM)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATICPGM)->ShowWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_PROGTORUN)->ShowWindow(FALSE);
		GetDlgItem(IDC_RUNPGM)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATICPGM)->ShowWindow(FALSE);
	}
}
