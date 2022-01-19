
// day5Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "day5.h"
#include "MsgDlg.h"
#include "day5Dlg.h"
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


// Cday5Dlg ��ȭ ����




Cday5Dlg::Cday5Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cday5Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_sResults = _T("");
}

void Cday5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BWHICHOPTION, m_cWhichOption);
	DDX_Text(pDX, IDC_RESULTS, m_sResults);
}

BEGIN_MESSAGE_MAP(Cday5Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_YESNOCANCEL, &Cday5Dlg::OnClickedYesnocancel)
	ON_BN_CLICKED(IDC_ABORTRETRYIGNORE, &Cday5Dlg::OnBnClickedAbortretryignore)
	ON_BN_CLICKED(IDC_FILEOPEN, &Cday5Dlg::OnClickedFileopen)
	ON_BN_CLICKED(IDC_BCUSTOMDIALOG, &Cday5Dlg::OnClickedBcustomdialog)
	ON_BN_CLICKED(IDC_BWHICHOPTION, &Cday5Dlg::OnClickedBwhichoption)
	ON_BN_CLICKED(IDC_EXIT, &Cday5Dlg::OnClickedExit)
END_MESSAGE_MAP()


// Cday5Dlg �޽��� ó����

BOOL Cday5Dlg::OnInitDialog()
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

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void Cday5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cday5Dlg::OnPaint()
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
HCURSOR Cday5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cday5Dlg::OnClickedYesnocancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int iResults;  // ���ư �˱����� ����

	//Ask the User (Yes, No, Cancel)
	iResults = MessageBox(L"Press the Yes, No, or Cancel button",
		L"Yes, No, Cancel Dialog",
		MB_YESNOCANCEL | MB_ICONINFORMATION);

	switch (iResults)
	{
	case IDYES:
		m_sResults = "Yes! Yes! Yes! ";
		break;
	case IDNO:
		m_sResults = "No, no, no, no, no ";
		break;
	case IDCANCEL:
		m_sResults = "Sorry, Canceled. ";
		break;
	}

	//Update Dlg
	UpdateData(FALSE);
}


void Cday5Dlg::OnBnClickedAbortretryignore()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int iResults;  // ���ư �˱����� ����

	//Ask the User (Abort, Retry, Ignore)
	iResults = MessageBox(L"Press the Abort, Retry, or Ignore button",
		L"Abort, Retry, Ignore Dialog",
		MB_ABORTRETRYIGNORE | MB_ICONSTOP);

	switch (iResults)
	{
	case IDABORT:
		m_sResults = "Abort! Abort! Abort! ";
		break;
	case IDRETRY:
		m_sResults = "Retry, retry, retry, retry, retry ";
		break;
	case IDIGNORE:
		m_sResults = "Sorry, Ignored. ";
		break;
	}

	//Update Dlg
	UpdateData(FALSE);
}


void Cday5Dlg::OnClickedFileopen()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CFileDialog m_ldFile(TRUE);

	if (m_ldFile.DoModal () == IDOK)
	{
		//���õ� ���� �̸�
		m_sResults = m_ldFile.GetFileName();

		//Update Dlg
		UpdateData(false);
	}
}


void Cday5Dlg::OnClickedBcustomdialog()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_dMsgDlg. DoModal () == IDOK)
	{
		// OKŬ���� ������ �޽��� ������
		m_sResults = m_dMsgDlg.m_sMessage;
		//Update Dlg
		UpdateData(FALSE);
		//��ư Ȱ��ȭ
		m_cWhichOption.EnableWindow(TRUE);
	}
}


void Cday5Dlg::OnClickedBwhichoption()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	switch(m_dMsgDlg.m_iOption)
	{
	case 0:
			m_sResults = "The first option was selected.";
			break;
	case 1:
		m_sResults = "The second option was selected.";
			break;
	case 2:
		m_sResults = "The third option was selected.";
			break;
	case 3:
		m_sResults = "The fourth option was selected.";
			break;
/*
	default:
		m_sResults = "To option was selected.";
			break;
*/
	}
	UpdateData(FALSE);
}


void Cday5Dlg::OnClickedExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}
