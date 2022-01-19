// MsgDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "day5.h"
#include "MsgDlg.h"
#include "afxdialogex.h"


// CMsgDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMsgDlg, CDialogEx)

CMsgDlg::CMsgDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMsgDlg::IDD, pParent)
{

	m_sMessage = _T("");
	m_iOption = 0;
}

CMsgDlg::~CMsgDlg()
{
}

void CMsgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MESSAGE, m_sMessage);
	DDX_Radio(pDX, IDC_OPTION1, m_iOption);
}


BEGIN_MESSAGE_MAP(CMsgDlg, CDialogEx)
END_MESSAGE_MAP()


// CMsgDlg 메시지 처리기입니다.
