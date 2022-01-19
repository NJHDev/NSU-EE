
// day8Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "day8.h"
#include "PaintDlg.h"
#include "day8Dlg.h"
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


// Cday8Dlg 대화 상자




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


// Cday8Dlg 메시지 처리기

BOOL Cday8Dlg::OnInitDialog()
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
	m_iColor = 0;
	m_iShape = 0;
	m_iTool = 0;
	UpdateData(FALSE);

	m_dlgPaint.Create(IDD_PAINT_DLG, this);
	m_dlgPaint.ShowWindow(SW_SHOW);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void Cday8Dlg::OnPaint()
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
HCURSOR Cday8Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Cday8Dlg::OnClickedBexit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}


void Cday8Dlg::OnClickedRcblack()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnRcblue()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnRccyan()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnRcgreen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnRcmagenta()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnRcred()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnRcwhite()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnRcyellow()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnRscircle()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnClickedRsline()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnRssquare()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnRtbitmap()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnRtbrush()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnClickedRtpen()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_dlgPaint.Invalidate();
}


void Cday8Dlg::OnClickedBbitmap()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	// 파일 열기 다이얼로그에 대한 필터링 문자열을 만든다.
	//static char BASED_CODE szFilter[]="Bitmap Files (*.bmp)|*.bmp||";
	//파일 열기 다이얼로그를 생성한다.
	CFileDialog m_ldFile(TRUE);
	/*, ".bmp", m_sBitmap,
		OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,szFilter);
	*/

	//파일 열기 다이얼로그를 보이고 결과값을 얻는다.
	if(m_ldFile.DoModal()==IDOK)
	{
		//선택된 파일 이름을 얻는다.
		m_sBitmap = m_ldFile.GetPathName();
		//선택된 비트맵 파일을 로드한다.
		HBITMAP hBitmap=(HBITMAP) ::LoadImage(AfxGetInstanceHandle(),m_sBitmap, IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
		if(hBitmap)
		{
			if(m_bmpBitmap.DeleteObject())
				m_bmpBitmap.Detach();
			//현재 로드된 비트맵을 CBitmap 개체에 부착한다.
			m_bmpBitmap.Attach(hBitmap);
		}
		//두번째 다이얼로그 윈도우를 무효화한다.
		m_dlgPaint.Invalidate();
	}
}
