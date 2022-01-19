
// day7Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "day7.h"
#include "day7Dlg.h"
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


// Cday7Dlg 대화 상자




Cday7Dlg::Cday7Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cday7Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strDisplayText = _T("");
	m_strSampText = _T("");
	m_strFontName = _T("");
	m_strFontName = _T("");
}

void Cday7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DISPLAYTEXT, m_ctlDisplayText);
	DDX_Text(pDX, IDC_DISPLAYTEXT, m_strDisplayText);
	DDX_Text(pDX, IDC_ESAMPTEXT, m_strSampText);
	DDX_Control(pDX, IDC_LFONTS, m_ctlFontList);
	DDX_LBString(pDX, IDC_LFONTS, m_strFontName);
	DDX_LBString(pDX, IDC_LFONTS, m_strFontName);
}

BEGIN_MESSAGE_MAP(Cday7Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, &Cday7Dlg::OnClickedExit)
	ON_EN_CHANGE(IDC_ESAMPTEXT, &Cday7Dlg::OnChangeEsamptext)
	ON_LBN_SELCHANGE(IDC_LFONTS, &Cday7Dlg::OnSelchangeLfonts)
END_MESSAGE_MAP()


// Cday7Dlg 메시지 처리기

BOOL Cday7Dlg::OnInitDialog()
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
	FillFontList();

	//입력 텍스트 초기화
	m_strSampText = "Testing";
	//폰트 샘플 영역에 텍스트 복사
	m_strDisplayText = m_strSampText;
	//Dlg Update
	UpdateData(FALSE);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void Cday7Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cday7Dlg::OnPaint()
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
HCURSOR Cday7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//폰트 콜백 함수 Body
int CALLBACK EnumFontFamProc(LPENUMLOGFONT lpelf,
	LPNEWTEXTMETRIC lpntm, DWORD nFontType, long lParam)
{
	//Dlg윈도우의 포인터로 캐스팅
	Cday7Dlg* pWnd = (Cday7Dlg*) lParam;

	//폰트 이름 리스트에 추가
	pWnd->m_ctlFontList.AddString(lpelf->elfLogFont.lfFaceName);

	//동작 반복을 위한 1
	return 1;
}

void Cday7Dlg::OnClickedExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}


void Cday7Dlg::FillFontList(void)
{
	int iCount;
	int iCurCount;
	CString strCurFont;
	CString strPrevFont = L"";
	LOGFONT lf;

	//LOGFONT 구조체 초기화
	lf.lfCharSet = DEFAULT_CHARSET;
	lstrcpy(lf.lfFaceName, L"");

	//리스트 박스 청소
	m_ctlFontList.ResetContent();
	//디바이스 컨텍스트 잡아내기
	CClientDC dc (this);
	//폰트 부류 나열
	::EnumFontFamiliesEx((HDC) dc, &lf,
		(FONTENUMPROC) EnumFontFamProc, (LPARAM) this, 0);
	//폰트 수 얻기
	iCount = m_ctlFontList.GetCount();
	//리스트 박스 끝부터 처음까지 순환하면서 중복된 엔트리 제거
	for (iCurCount = iCount; iCurCount > 0; iCurCount--)
	{
		//현재 폰트 이름
		m_ctlFontList.GetText((iCurCount - 1), strCurFont);
		//폰트 이름 같은가?
		if (strCurFont == strPrevFont)
		{
			m_ctlFontList.DeleteString((iCurCount - 1));
		}
		//이전 폰트 이름을 현재 폰트 이름으로 설정
		strPrevFont = strCurFont;
	}
}


void Cday7Dlg::OnChangeEsamptext()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	m_strDisplayText = m_strSampText;

	UpdateData(FALSE);
}


void Cday7Dlg::OnSelchangeLfonts()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CRect rRect;
	int iHeight;
	CFont m_fSampFont;

	if (m_strFontName != "")
	{
		m_ctlDisplayText.GetWindowRect(&rRect);

		iHeight = rRect.top - rRect.bottom;

		if (iHeight < 0)
			iHeight = 0 - iHeight;

		m_fSampFont.Detach();

		m_fSampFont.CreateFont((iHeight - 5), 0, 0, 0, FW_NORMAL,
			0, 0, 0, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS,
			CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH |
			FF_DONTCARE, m_strFontName);

		m_ctlDisplayText.SetFont(&m_fSampFont);
	}
}