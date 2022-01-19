
// midDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "mid.h"
#include "midDlg.h"
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


// CmidDlg 대화 상자




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


// CmidDlg 메시지 처리기

BOOL CmidDlg::OnInitDialog()
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
	SetTimer(ID_CLOCK_TIMER, 100, NULL);
	m_strMessage = "여기에 입력해주세요!";
	m_bShowTime = TRUE;
	m_bShowMsg = TRUE;
	m_bEnableTime = TRUE;
	m_bEnableMsg = TRUE;

	UpdateData(FALSE);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CmidDlg::OnPaint()
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
HCURSOR CmidDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmidDlg::OnBnClickedExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}


void CmidDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CTime curTime = CTime::GetCurrentTime();
	m_sTime.Format(L"%02d:%02d:%02d", curTime.GetHour(),
		curTime.GetMinute(), 
		curTime.GetSecond());

	UpdateData(FALSE);
}


void CmidDlg::OnEnChangeMsg()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.
	UpdateData(TRUE);
	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CmidDlg::OnBnClickedShwmsg()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	MessageBox(m_strMessage);
	
}


void CmidDlg::OnBnClickedClrmsg()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_strMessage = "",

	UpdateData(FALSE);
}


void CmidDlg::OnBnClickedCkenbtime()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_strMessage = "여기에 입력해주세요!",

	UpdateData(FALSE);
}

void CmidDlg::OnStnClickedStatictime()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

}
