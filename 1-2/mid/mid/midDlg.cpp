
// midDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "mid.h"
#include "midDlg.h"
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


// CmidDlg ��ȭ ����




CmidDlg::CmidDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CmidDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_sTime = _T("");
	m_strMessage = _T("");
}

void CmidDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATICTIME, m_sTime);
	DDX_Text(pDX, IDC_MSG, m_strMessage);
	DDX_Check(pDX, IDC_CKENBTIME, m_bEnableTime);
	DDX_Check(pDX, IDC_CKSHWMSG, m_bShowMsg);
	//  DDX_Control(pDX, IDC_CKSHWTIME, m_bShowTime);
	DDX_Check(pDX, IDC_CKSHWTIME, m_bShowTime);
	//  DDX_Control(pDX, IDC_CKENBMSG, m_bEnableMsg);
	//  DDX_Check(pDX, IDC_CKENBMSG, m_m_bEnableMsg);
	DDX_Check(pDX, IDC_CKENBMSG, m_bEnableMsg);
}

BEGIN_MESSAGE_MAP(CmidDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, &CmidDlg::OnBnClickedExit)
	ON_WM_TIMER()
	ON_EN_CHANGE(IDC_MSG, &CmidDlg::OnEnChangeMsg)
	ON_BN_CLICKED(IDC_SHWMSG, &CmidDlg::OnBnClickedShwmsg)
	ON_BN_CLICKED(IDC_CLRMSG, &CmidDlg::OnBnClickedClrmsg)
	ON_BN_CLICKED(IDC_CKENBTIME, &CmidDlg::OnBnClickedCkenbtime)
	ON_BN_CLICKED(IDC_CKENBMSG, &CmidDlg::OnBnClickedCkenbmsg)
	ON_BN_CLICKED(IDC_CKSHWTIME, &CmidDlg::OnBnClickedCkshwtime)
	ON_BN_CLICKED(IDC_CKSHWMSG, &CmidDlg::OnBnClickedCkshwmsg)
	ON_BN_CLICKED(IDC_DFLTMSG, &CmidDlg::OnBnClickedDfltmsg)
	ON_STN_CLICKED(IDC_STATICTIME, &CmidDlg::OnStnClickedStatictime)
END_MESSAGE_MAP()


// CmidDlg �޽��� ó����

BOOL CmidDlg::OnInitDialog()
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
	SetTimer(ID_CLOCK_TIMER, 100, NULL);
	m_strMessage = "���⿡ �Է����ּ���!";
	m_bShowTime = TRUE;
	m_bShowMsg = TRUE;
	m_bEnableTime = TRUE;
	m_bEnableMsg = TRUE;

	UpdateData(FALSE);
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CmidDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CmidDlg::OnPaint()
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
HCURSOR CmidDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmidDlg::OnBnClickedExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}


void CmidDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CTime curTime = CTime::GetCurrentTime();
	m_sTime.Format(L"%02d:%02d:%02d", curTime.GetHour(),
		curTime.GetMinute(), 
		curTime.GetSecond());

	UpdateData(FALSE);
}


void CmidDlg::OnEnChangeMsg()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.
	UpdateData(TRUE);
	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CmidDlg::OnBnClickedShwmsg()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	MessageBox(m_strMessage);
	
}


void CmidDlg::OnBnClickedClrmsg()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_strMessage = "",

	UpdateData(FALSE);
}


void CmidDlg::OnBnClickedCkenbtime()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	if (m_bEnableTime == TRUE)
	{
		GetDlgItem(IDC_STATICTIME)->EnableWindow(TRUE);
		GetDlgItem(IDC_TIME)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_STATICTIME)->EnableWindow(FALSE);
		GetDlgItem(IDC_TIME)->EnableWindow(FALSE);
	}
}


void CmidDlg::OnBnClickedCkenbmsg()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	if (m_bEnableMsg == TRUE)
	{
		GetDlgItem(IDC_MSG)->EnableWindow(TRUE);
		GetDlgItem(IDC_MSGTEXT)->EnableWindow(TRUE);
		GetDlgItem(IDC_SHWMSG)->EnableWindow(TRUE);
		GetDlgItem(IDC_DFLTMSG)->EnableWindow(TRUE);
		GetDlgItem(IDC_CLRMSG)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_MSG)->EnableWindow(FALSE);
		GetDlgItem(IDC_MSGTEXT)->EnableWindow(FALSE);
		GetDlgItem(IDC_SHWMSG)->EnableWindow(FALSE);
		GetDlgItem(IDC_DFLTMSG)->EnableWindow(FALSE);
		GetDlgItem(IDC_CLRMSG)->EnableWindow(FALSE);
	}
}



void CmidDlg::OnBnClickedCkshwtime()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	if (m_bShowTime == TRUE)
	{
		GetDlgItem(IDC_STATICTIME)->ShowWindow(TRUE);
		GetDlgItem(IDC_TIME)->ShowWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_STATICTIME)->ShowWindow(FALSE);
		GetDlgItem(IDC_TIME)->ShowWindow(FALSE);
	}
}


void CmidDlg::OnBnClickedCkshwmsg()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	if (m_bShowMsg == TRUE)
	{
		GetDlgItem(IDC_MSG)->ShowWindow(TRUE);
		GetDlgItem(IDC_MSGTEXT)->ShowWindow(TRUE);
		GetDlgItem(IDC_SHWMSG)->ShowWindow(TRUE);
		GetDlgItem(IDC_DFLTMSG)->ShowWindow(TRUE);
		GetDlgItem(IDC_CLRMSG)->ShowWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_MSG)->ShowWindow(FALSE);
		GetDlgItem(IDC_MSGTEXT)->ShowWindow(FALSE);
		GetDlgItem(IDC_SHWMSG)->ShowWindow(FALSE);
		GetDlgItem(IDC_DFLTMSG)->ShowWindow(FALSE);
		GetDlgItem(IDC_CLRMSG)->ShowWindow(FALSE);
	}
}


void CmidDlg::OnBnClickedDfltmsg()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_strMessage = "���⿡ �Է����ּ���!",

	UpdateData(FALSE);
}

void CmidDlg::OnStnClickedStatictime()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

}
