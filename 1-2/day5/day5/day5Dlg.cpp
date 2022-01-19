
// day5Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "day5.h"
#include "MsgDlg.h"
#include "day5Dlg.h"
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


// Cday5Dlg 대화 상자




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


// Cday5Dlg 메시지 처리기

BOOL Cday5Dlg::OnInitDialog()
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void Cday5Dlg::OnPaint()
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
HCURSOR Cday5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cday5Dlg::OnClickedYesnocancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int iResults;  // 어떤버튼 알기위한 변수

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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int iResults;  // 어떤버튼 알기위한 변수

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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog m_ldFile(TRUE);

	if (m_ldFile.DoModal () == IDOK)
	{
		//선택된 파일 이름
		m_sResults = m_ldFile.GetFileName();

		//Update Dlg
		UpdateData(false);
	}
}


void Cday5Dlg::OnClickedBcustomdialog()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_dMsgDlg. DoModal () == IDOK)
	{
		// OK클릭시 적절한 메시지 뜨위기
		m_sResults = m_dMsgDlg.m_sMessage;
		//Update Dlg
		UpdateData(FALSE);
		//버튼 활성화
		m_cWhichOption.EnableWindow(TRUE);
	}
}


void Cday5Dlg::OnClickedBwhichoption()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}
