
// day3Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "day3.h"
#include "day3Dlg.h"
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


// Cday3Dlg 대화 상자




Cday3Dlg::Cday3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cday3Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_iPrevY = 0;
	m_iPrevX = 0;
}

void Cday3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cday3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// Cday3Dlg 메시지 처리기

BOOL Cday3Dlg::OnInitDialog()
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
	//커서를 화살표로 초기화
	m_bCursor = FALSE;

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void Cday3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cday3Dlg::OnPaint()
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
HCURSOR Cday3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cday3Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//왼쪽마우스 버튼 체크
	if ((nFlags & MK_LBUTTON) == MK_LBUTTON)
	{
		//디바이스 컨텍스트 잡기
		CClientDC dc(this);

		//바로 이전의 점과 현재 점 사이 연결
		dc.MoveTo(m_iPrevX, m_iPrevY);
		dc.LineTo(point.x, point.y);

		//현재 점을 (이후의) 이전 점으로 저장
		m_iPrevX = point.x;
		m_iPrevY = point.y;
	}

	CDialogEx::OnMouseMove(nFlags, point);
}


void Cday3Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//현재의 점을 시작점으로 설정
	m_iPrevX = point.x;
	m_iPrevY = point.y;

	CDialogEx::OnLButtonDown(nFlags, point);
}


void Cday3Dlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	char lsChar;					 //눌린 문자 키 코드
	HCURSOR lhCursor;		//표시될 커서의 핸들

	//키코드 to 문자
	lsChar = char(nChar);

	//A 누름??
	if ( lsChar == 'A' )
	{
		//화살표 커서
		lhCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		//화면 커서 설정
		SetCursor(lhCursor);
	}

	//B 누름?
	if ( lsChar == 'B' )
	{
		//I자 막대
		lhCursor = AfxGetApp()->LoadStandardCursor(IDC_IBEAM);
		//화면 커서 설정
		SetCursor(lhCursor);
	}

	//C 누름?
	if ( lsChar == 'C' )
	{
		//I자 막대
		lhCursor = AfxGetApp()->LoadStandardCursor(IDC_WAIT);
		//화면 커서 설정
		SetCursor(lhCursor);
	}

	//X 누름?
	if ( lsChar == 'X' )
	{
		//화살표 커서
		lhCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		//커서 플래그 설정
		m_bCursor = TRUE;
		//화면 커서 설정
		SetCursor(lhCursor);
		//종료
		OnOK();
	}
	else
	{
		//커서 플래그 설정
		m_bCursor = TRUE;
		//화면 커서 설정
		SetCursor(lhCursor);
	}

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL Cday3Dlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//TRUE커서 설정 -> TRUE 반환
	if (m_bCursor)
		return TRUE;
	else

	return CDialogEx::OnSetCursor(pWnd, nHitTest, message);
}
