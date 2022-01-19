
// day4Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "day4.h"
#include "day4Dlg.h"
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


// Cday4Dlg ��ȭ ����




Cday4Dlg::Cday4Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cday4Dlg::IDD, pParent)
	, m_iCount(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_sTime = _T("");
	m_sCount = _T("");
	//  m_iInterval = 0;
	m_iInterval = 0;
}

void Cday4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATICTIME, m_sTime);
	DDX_Text(pDX, IDC_STATICCOUNT, m_sCount);
	//  DDX_Text(pDX, IDC_INTERVAL, m_iInterval);
	DDX_Control(pDX, IDC_STARTTIME, m_cStartTime);
	DDX_Control(pDX, IDC_STOPTIMER, m_cStopTime);
	DDX_Text(pDX, IDC_INTERVAL, m_iInterval);
}

BEGIN_MESSAGE_MAP(Cday4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_EN_CHANGE(IDC_INTERVAL, &Cday4Dlg::OnChangeInterval)
	ON_BN_CLICKED(IDC_STARTTIME, &Cday4Dlg::OnClickedStarttime)
	ON_BN_CLICKED(IDC_STOPTIMER, &Cday4Dlg::OnClickedStoptimer)
	ON_BN_CLICKED(IDC_EXIT, &Cday4Dlg::OnClickedExit)
END_MESSAGE_MAP()


// Cday4Dlg �޽��� ó����

BOOL Cday4Dlg::OnInitDialog()
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
	m_iInterval = 1000;

	UpdateData(FALSE);

	SetTimer(ID_CLOCK_TIMER, 1000, NULL);
	
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void Cday4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cday4Dlg::OnPaint()
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
HCURSOR Cday4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cday4Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	
	//����ð� ���
	CTime curTime = CTime::GetCurrentTime();

	//��� Ÿ�̸Ӱ� �̺�Ʈ �߻�?
	switch (nIDEvent)
	{
	//�ð��?
	case ID_CLOCK_TIMER:
		//ǥ���ص帲
		m_sTime.Format(L"%02d:%02d:%02d", curTime.GetHour(), curTime.GetMinute(), curTime.GetSecond());
		break;
	//ī��Ʈ Ÿ�̸ӳ�?
	case ID_COUNT_TIMER:
		//ī��Ʈ �÷��帲
		m_iCount++;
		m_sCount.Format(L"%d", m_iCount);
		break;
	}

	//Dlg ����
	UpdateData(FALSE);

	CDialogEx::OnTimer(nIDEvent);
}


void Cday4Dlg::OnChangeInterval()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
}


void Cday4Dlg::OnClickedStarttime()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	
	//���� Update
	UpdateData(TRUE);

	//ī��Ʈ �ʱ�ȭ
	m_iCount = 0;

	//ī��Ʈ ������ ���ڿ� ����ȭ
	m_sCount.Format(L"%d", m_iCount);

	//Dlg Update
	UpdateData(FALSE);

	//START
	SetTimer(ID_COUNT_TIMER, m_iInterval, NULL);

	//If START_Button Clicked
	m_cStartTime.EnableWindow(FALSE);
	m_cStopTime.EnableWindow(TRUE);
}

void Cday4Dlg::OnClickedStoptimer()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	//Ÿ�̸� ����
	KillTimer(ID_COUNT_TIMER);

	//If STOP_Button Clicked
	m_cStartTime.EnableWindow(TRUE);
	m_cStopTime.EnableWindow(FALSE);
}

void Cday4Dlg::OnClickedExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}