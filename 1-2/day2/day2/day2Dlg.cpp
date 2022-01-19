
// day2Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "day2.h"
#include "day2Dlg.h"
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


// Cday2Dlg 대화 상자




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


// Cday2Dlg 메시지 처리기

BOOL Cday2Dlg::OnInitDialog()
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
	//디폴트 메시지
	m_strMessage = "Please a Message here.";

	//체크박스 체크
	m_bShowMsg = TRUE;
	m_bShowPgm = TRUE;
	m_bEnableMsg = TRUE;
	m_bEnablePgm = TRUE;

	//다이얼로그 컨트롤 값
	UpdateData(FALSE);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void Cday2Dlg::OnPaint()
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
HCURSOR Cday2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Cday2Dlg::OnClickedExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}


void Cday2Dlg::OnClickedShwmsg()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	MessageBox(m_strMessage);
}


void Cday2Dlg::OnClickedDflmsg()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_strMessage = "Please a Message here.";

	UpdateData(FALSE);
}


void Cday2Dlg::OnClickedClrmsg()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_strMessage = "";

	UpdateData(FALSE);
}


void Cday2Dlg::OnClickedRunpgm()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	
	CString strPgmName;

	strPgmName = m_strProgToRun;

	if (strPgmName == "메모장")
		WinExec("C:\\Windows\\system32\\notepad.exe", SW_SHOW);

	else if (strPgmName == "그림판")
		WinExec("C:\\Windows\\system32\\mspaint.exe", SW_SHOW);

	else if (strPgmName == "계산기")
		WinExec("C:\\Windows\\System32\\calc.exe", SW_SHOW);
	else
		MessageBox(L"프로그램을 선택하세요.");
}


void Cday2Dlg::OnClickedCkenblmsg()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
