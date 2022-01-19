
// day7Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "day7.h"
#include "day7Dlg.h"
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


// Cday7Dlg ��ȭ ����




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


// Cday7Dlg �޽��� ó����

BOOL Cday7Dlg::OnInitDialog()
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
	FillFontList();

	//�Է� �ؽ�Ʈ �ʱ�ȭ
	m_strSampText = "Testing";
	//��Ʈ ���� ������ �ؽ�Ʈ ����
	m_strDisplayText = m_strSampText;
	//Dlg Update
	UpdateData(FALSE);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void Cday7Dlg::OnPaint()
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
HCURSOR Cday7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//��Ʈ �ݹ� �Լ� Body
int CALLBACK EnumFontFamProc(LPENUMLOGFONT lpelf,
	LPNEWTEXTMETRIC lpntm, DWORD nFontType, long lParam)
{
	//Dlg�������� �����ͷ� ĳ����
	Cday7Dlg* pWnd = (Cday7Dlg*) lParam;

	//��Ʈ �̸� ����Ʈ�� �߰�
	pWnd->m_ctlFontList.AddString(lpelf->elfLogFont.lfFaceName);

	//���� �ݺ��� ���� 1
	return 1;
}

void Cday7Dlg::OnClickedExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}


void Cday7Dlg::FillFontList(void)
{
	int iCount;
	int iCurCount;
	CString strCurFont;
	CString strPrevFont = L"";
	LOGFONT lf;

	//LOGFONT ����ü �ʱ�ȭ
	lf.lfCharSet = DEFAULT_CHARSET;
	lstrcpy(lf.lfFaceName, L"");

	//����Ʈ �ڽ� û��
	m_ctlFontList.ResetContent();
	//����̽� ���ؽ�Ʈ ��Ƴ���
	CClientDC dc (this);
	//��Ʈ �η� ����
	::EnumFontFamiliesEx((HDC) dc, &lf,
		(FONTENUMPROC) EnumFontFamProc, (LPARAM) this, 0);
	//��Ʈ �� ���
	iCount = m_ctlFontList.GetCount();
	//����Ʈ �ڽ� ������ ó������ ��ȯ�ϸ鼭 �ߺ��� ��Ʈ�� ����
	for (iCurCount = iCount; iCurCount > 0; iCurCount--)
	{
		//���� ��Ʈ �̸�
		m_ctlFontList.GetText((iCurCount - 1), strCurFont);
		//��Ʈ �̸� ������?
		if (strCurFont == strPrevFont)
		{
			m_ctlFontList.DeleteString((iCurCount - 1));
		}
		//���� ��Ʈ �̸��� ���� ��Ʈ �̸����� ����
		strPrevFont = strCurFont;
	}
}


void Cday7Dlg::OnChangeEsamptext()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	m_strDisplayText = m_strSampText;

	UpdateData(FALSE);
}


void Cday7Dlg::OnSelchangeLfonts()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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