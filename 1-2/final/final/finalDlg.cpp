
// finalDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "final.h"
#include "finalDlg.h"
#include "USERDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CfinalDlg 대화 상자




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


// CfinalDlg 메시지 처리기

BOOL CfinalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_sMessage = "여기에 메시지를 입력하세요.";
	m_check = TRUE;
	UpdateData(FALSE);
	
	SetTimer(ID_CLOCK_TIMER, 1000, NULL);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CfinalDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CfinalDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CfinalDlg::OnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}


void CfinalDlg::OnClickedShwmsg()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	MessageBox(m_strMessage, L"메시지", MB_YESNO | MB_ICONQUESTION);
}


void CfinalDlg::OnClickedClrmsg()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_sMessage="";\
	UpdateData(FALSE);
}

void CfinalDlg::OnClickedDfltmsg()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_sMessage = "여기에 메시지를 입력하세요.";
	UpdateData(FALSE);
}


void CfinalDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CTime curTime = CTime::GetCurrentTime();
	m_sTime.Format(L"%02d:%02d:%02d", curTime.GetHour(),
		curTime.GetMinute(), curTime.GetSecond());
	
	UpdateData(FALSE);
	
	CDialogEx::OnTimer(nIDEvent);
}


void CfinalDlg::OnBnClickedCheck()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_dUserDlg. DoModal () == IDOK)
	{
		// OK클릭시 적절한 메시지 뜨위기
		//m_sResults = m_dUserDlg.m_sMessage;
		//Update Dlg
		UpdateData(FALSE);
	}
}


void CfinalDlg::OnClickedSelopt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	switch(m_dUserDlg.m_igen)
	{
	case 0:
			m_sResults = "남성";
			break;
	case 1:
		m_sResults = "여성";
			break;
	}
}
