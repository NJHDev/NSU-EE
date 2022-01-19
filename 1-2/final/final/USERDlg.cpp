// USERDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "final.h"
#include "USERDlg.h"
#include "afxdialogex.h"


// CUSERDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CUSERDlg, CDialog)

CUSERDlg::CUSERDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUSERDlg::IDD, pParent)
{

	m_igen = 0;
	m_iinterval = 0;
	m_scount = _T("");
}

CUSERDlg::~CUSERDlg()
{
}

void CUSERDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Radio(pDX, IDC_MAN, m_gender);
	//  DDX_Text(pDX, IDC_STATICCOUNT, m_iinterval);
	//  DDX_Control(pDX, IDC_STARTTIME, m_cstop);
	DDX_Control(pDX, IDC_STARTTIME, m_cstart);
	DDX_Control(pDX, IDC_STOPTIME, m_cstop);
	DDX_Text(pDX, IDC_INTERVAL, m_iinterval);
	DDX_Text(pDX, IDC_STATICCOUNT, m_scount);
	DDX_Radio(pDX, IDC_MAN, m_igen);
	DDX_Check(pDX, IDC_SOCCER, m_bsoc);
	DDX_Check(pDX, IDC_BASEBALL, m_bbas);
}


BEGIN_MESSAGE_MAP(CUSERDlg, CDialog)
	ON_BN_CLICKED(IDC_STARTTIME, &CUSERDlg::OnBnClickedStarttime)
END_MESSAGE_MAP()


// CUSERDlg 메시지 처리기입니다.


void CUSERDlg::OnBnClickedStarttime()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

}
