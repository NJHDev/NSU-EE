
// finalDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "final.h"
#include "finalDlg.h"
#include "USERDlg.h"
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


// CfinalDlg ��ȭ ����




CfinalDlg::CfinalDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CfinalDlg::IDD, pParent)
	, gender(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strMessage = _T("");
	m_sTime = _T("");
	m_sResults = _T("");
	m_sMessage = _T("");
}

void CfinalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TIME, m_sTime);
	DDX_Check(pDX, IDC_CHECK, m_check);
	DDX_Text(pDX, IDC_RESULTS, m_sResults);
	//  DDX_Control(pDX, IDC_MESSAGE, m_sMessage);
	DDX_Text(pDX, IDC_MESSAGE, m_sMessage);
}

BEGIN_MESSAGE_MAP(CfinalDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CANCEL, &CfinalDlg::OnClickedCancel)
	ON_BN_CLICKED(IDC_SHWMSG, &CfinalDlg::OnClickedShwmsg)
	ON_BN_CLICKED(IDC_CLRMSG, &CfinalDlg::OnClickedClrmsg)
	ON_BN_CLICKED(IDC_DFLTMSG, &CfinalDlg::OnClickedDfltmsg)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CHECK, &CfinalDlg::OnBnClickedCheck)
	ON_BN_CLICKED(IDC_USERDLG, &CfinalDlg::OnClickedUserdlg)
	ON_BN_CLICKED(IDC_SELOPT, &CfinalDlg::OnClickedSelopt)
END_MESSAGE_MAP()


// CfinalDlg �޽��� ó����

BOOL CfinalDlg::OnInitDialog()
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
	m_sMessage = "���⿡ �޽����� �Է��ϼ���.";
	m_check = TRUE;
	UpdateData(FALSE);
	
	SetTimer(ID_CLOCK_TIMER, 1000, NULL);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CfinalDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CfinalDlg::OnPaint()
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
HCURSOR CfinalDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CfinalDlg::OnClickedCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}


void CfinalDlg::OnClickedShwmsg()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	MessageBox(m_strMessage, L"�޽���", MB_YESNO | MB_ICONQUESTION);
}


void CfinalDlg::OnClickedClrmsg()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_sMessage="";\
	UpdateData(FALSE);
}

void CfinalDlg::OnClickedDfltmsg()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_sMessage = "���⿡ �޽����� �Է��ϼ���.";
	UpdateData(FALSE);
}


void CfinalDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CTime curTime = CTime::GetCurrentTime();
	m_sTime.Format(L"%02d:%02d:%02d", curTime.GetHour(),
		curTime.GetMinute(), curTime.GetSecond());
	
	UpdateData(FALSE);
	
	CDialogEx::OnTimer(nIDEvent);
}


void CfinalDlg::OnBnClickedCheck()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	if (m_check ==TRUE)
	{
		GetDlgItem(IDC_USERDLG) -> EnableWindow(TRUE);
		GetDlgItem(IDC_SELOPT) -> EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_USERDLG) -> EnableWindow(FALSE);
		GetDlgItem(IDC_SELOPT) -> EnableWindow(FALSE);
	}
}


void CfinalDlg::OnClickedUserdlg()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_dUserDlg. DoModal () == IDOK)
	{
		// OKŬ���� ������ �޽��� ������
		//m_sResults = m_dUserDlg.m_sMessage;
		//Update Dlg
		UpdateData(FALSE);
	}
}


void CfinalDlg::OnClickedSelopt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	switch(m_dUserDlg.m_igen)
	{
	case 0:
			m_sResults = "����";
			break;
	case 1:
		m_sResults = "����";
			break;
	}
}
