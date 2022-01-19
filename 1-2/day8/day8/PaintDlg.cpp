// PaintDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "day8.h"
#include "PaintDlg.h"
#include "day8Dlg.h"
#include "afxdialogex.h"

const COLORREF CPaintDlg::m_crColors[8] = {
	RGB( 0 , 0, 0), //Black
	RGB( 0 , 0, 255), //Blue
	RGB( 0 , 255, 0), //Green
	RGB( 0 , 255, 255), //Cyan
	RGB( 255 , 0, 0),  //Red
	RGB( 255 , 0, 255), //Magenta
	RGB( 255 , 255, 0), //Yellow
	RGB( 255 , 255, 255) //White
};

// CPaintDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CPaintDlg, CDialog)

CPaintDlg::CPaintDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPaintDlg::IDD, pParent)
{

}

CPaintDlg::~CPaintDlg()
{
}

void CPaintDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPaintDlg, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CPaintDlg 메시지 처리기입니다.


void CPaintDlg::DrawLine(CPaintDC* pdc, int iColor)
{
	//펜 선언&생성
	CPen lSolidPen (PS_SOLID, 1, m_crColors[iColor]);
	CPen lDotPen (PS_DOT, 1, m_crColors[iColor]);
	CPen lDashPen (PS_DASH, 1, m_crColors[iColor]);
	CPen lDashDotPen (PS_DASHDOT, 1, m_crColors[iColor]);
	CPen lDashDotDotPen (PS_DASHDOTDOT, 1, m_crColors[iColor]);
	CPen lNullPen (PS_NULL, 1, m_crColors[iColor]);
	CPen lInsidePen (PS_INSIDEFRAME, 1, m_crColors[iColor]);
	
	//그릴 영역 얻기
	CRect lRect;
	GetClientRect(lRect);
	lRect.NormalizeRect();

	//선 사이의 거리 계산
	CPoint pStart;
	CPoint pEnd;
	int liDist = lRect.Height() / 8;
	CPen *lOldPen;

	//시작점 설정
	pStart.y = lRect.top;
	pStart.x = lRect.left;
	pEnd.y = pStart.y;
	pEnd.x = lRect.right;
	int i;

	//펜들을 모두 순환
	for ( i = 0; i < 7; i++ )
	{
		//어떤 펜?
		switch(i)
		{
		case 0 : //실선
			lOldPen = pdc->SelectObject(&lSolidPen);
			break;
		case 1 : //점선
			pdc->SelectObject(&lDotPen);
			break;
		case 2 : //쇄선
			lOldPen = pdc->SelectObject(&lDashPen);
			break;
		case 3 : //점쇄선
			pdc->SelectObject(&lDashDotPen);
			break;
		case 4 : //이점 쇄선
			lOldPen = pdc->SelectObject(&lDashDotDotPen);
			break;
		case 5 : //투명선
			pdc->SelectObject(&lNullPen);
			break;
		case 6 : //내부
			lOldPen = pdc->SelectObject(&lInsidePen);
			break;
		}
		//다음 아래 위치로 이동
		pStart.y = pStart.y + liDist;
		pEnd.y = pStart.y;
		//선 그리기
		pdc->MoveTo(pStart);
		pdc->LineTo(pEnd);
	}
	//원래 펜으로 되돌리기
	pdc->SelectObject(lOldPen);
}


void CPaintDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	//부모 윈도우의 포인터 얻기
	Cday8Dlg *pWnd = (Cday8Dlg*)GetParent();

	//포인터가 제대로 되있음?
	if(pWnd)
	{
		//if 선택된 도구 = 비트맵
		if(pWnd->m_iTool ==2)
		{
			//비트맵이 선택되어있고 로드되어있음?
			if (pWnd->m_sBitmap !="")
				//표시하자
				ShowBitmap(&dc, pWnd);
		}
		else	//아님, 도형그리는거임
		{
			//선 그리는거임?
			if (pWnd->m_iShape == 0)
				DrawLine(&dc, pWnd->m_iColor);
			else  //원,사각형 그릴꺼임
				DrawRegion(&dc, pWnd->m_iColor, pWnd->m_iTool, pWnd->m_iShape);
		}
	}
	// 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
}


void CPaintDlg::DrawRegion(CPaintDC* pdc, int iColor, int iTool, int iShape)
{
	// 펜을 선언하고 생성
	CPen lSolidPen (PS_SOLID, 1, m_crColors[iColor]);
	CPen lDotPen (PS_DOT, 1, m_crColors[iColor]);
	CPen lDashPen (PS_DASH, 1, m_crColors[iColor]);
	CPen lDashDotPen (PS_DASHDOT, 1, m_crColors[iColor]);
	CPen lDashDotDotPen (PS_DASHDOTDOT, 1, m_crColors[iColor]);
	CPen lNullPen (PS_NULL, 1, m_crColors[iColor]);
	CPen lInsidePen (PS_INSIDEFRAME, 1, m_crColors[iColor]);

	// 브러쉬 선언하고 생성
	CBrush lSolidBrush(m_crColors[iColor]);
	CBrush lBDiagBrush(HS_BDIAGONAL, m_crColors[iColor]);
	CBrush lCrossBrush(HS_CROSS, m_crColors[iColor]);
	CBrush lDiagCrossBrush(HS_DIAGCROSS, m_crColors[iColor]);
	CBrush lFDiagBrush(HS_FDIAGONAL, m_crColors[iColor]);
	CBrush lHorizBrush(HS_HORIZONTAL, m_crColors[iColor]);
	CBrush lVertBrush(HS_VERTICAL, m_crColors[iColor]);
	CBrush lNullBrush(RGB(192, 192, 192));

	//그릴 영역의 크기 계산
	CRect lRect;
	GetClientRect(lRect);
	lRect.NormalizeRect();
	int iVert = lRect.Height() / 2;
	int iHeight = iVert - 10;
	int iHorz = lRect.Width() / 4;
	int iWidth = iHorz - 10;
	CRect lDrawRect;
	CPen *pOldPen;
	CBrush *pOldBrush;
	int i;
	//모든 펜과 브러쉬에 대해 루프
	for (i = 0; i < 7; i++)
	{
		switch (i)
		{
		case 0: // 실선
			// 도형의 위치 결정
			// 첫째줄 시작
			lDrawRect.top = lRect.top + 5;
			lDrawRect.left = lRect.left + 5;
			lDrawRect.bottom = lDrawRect.top + iHeight;
			lDrawRect.right = lDrawRect.left + iWidth;
			//적당한 펜과 브러쉬 선택
			pOldPen = pdc->SelectObject(&lSolidPen);
			pOldBrush = pdc->SelectObject(&lSolidBrush);
			break;

		case 1: //점선, 역대각 빗금 브러쉬
			//도형의 위치 결정
			lDrawRect.left = lDrawRect.left + iHorz;
			lDrawRect.right = lDrawRect.left + iWidth;
			//적당한 펜과 브러쉬 선택
			pdc->SelectObject(&lDotPen);
			pdc->SelectObject(&lBDiagBrush);
			break;
		case 2: //쇄선, 바둑판 무의 브러쉬
			//도형의 위치 결정
			lDrawRect.left = lDrawRect.left + iHorz;
			lDrawRect.right = lDrawRect.left + iWidth;
			//적당한 펜과 브러쉬 선택
			pdc->SelectObject(&lDashPen);
			pdc->SelectObject(&lCrossBrush);
			break;
		case 3: //점 쇄선 -X자 무늬 브러쉬
			//도형의 위치 결정
			lDrawRect.left = lDrawRect.left + iHorz;
			lDrawRect.right = lDrawRect.left + iWidth;
			//적당한 펜과 브러쉬 선택
			pdc->SelectObject(&lDashDotPen);
			pdc->SelectObject(&lDiagCrossBrush);
			break;
		case 4: //이점 쇄선, 대각 빗금 브러쉬
			//도형의 위치 결정
			//둘째줄 시작
			lDrawRect.top = lDrawRect.top + iVert;
			lDrawRect.left = lRect.left + 5;
			lDrawRect.bottom = lDrawRect.top + iHeight;
			lDrawRect.right = lDrawRect.left + iWidth;
			//적당한 펜과 브러쉬 선택
			pdc->SelectObject(&lDashDotDotPen);
			pdc->SelectObject(&lFDiagBrush);
			break;
		case 5: //널 펜, 수평무늬 브러쉬
			//도형의 위치 결정
			lDrawRect.left = lDrawRect.left + iHorz;
			lDrawRect.right = lDrawRect.left + iWidth;
			//적당한 펜과 브러쉬 선택
			pdc->SelectObject(&lNullPen);
			pdc->SelectObject(&lHorizBrush);
			break;
		case 6: //내부, 수직 무늬 브러쉬
			//도형의 위치 결정
			lDrawRect.left = lDrawRect.left + iHorz;
			lDrawRect.right = lDrawRect.left + iWidth;
			//적당한 펜과 브러쉬 선택
			pdc->SelectObject(&lInsidePen);
			pdc->SelectObject(&lVertBrush);
			break;
		}
		//어떤 도구 사용중?
		if (iTool == 0)
			pdc->SelectObject(lNullBrush);
		else
			pdc->SelectObject(lNullPen);
		//어떤 도형 그릴꺼임?
		if (iShape == 1)
			pdc->Ellipse(lDrawRect);
		else
			pdc->Rectangle(lDrawRect);
	}

	// 원래 브러쉬로 되돌리기
	pdc->SelectObject(pOldBrush);
	pdc->SelectObject(pOldPen);
}

void CPaintDlg::ShowBitmap(CPaintDC* pdc, CWnd* pWnd)
{
	//포인터를 메인 다이얼로그 클래스의 포인터로 캐스팅한다.
	Cday8Dlg *lpWnd=(Cday8Dlg*)pWnd;
	BITMAP bm;
	lpWnd->m_bmpBitmap.GetBitmap(&bm);
	CDC dcMem;
	//비트맵을 로드할 호환 디바이스 컨텍스트를 생성한다.
	dcMem.CreateCompatibleDC(pdc);
	//호환 디바이스 컨텍스트에 비트맵을 선택해 넣는다.
	CBitmap* pOldBitmap=(CBitmap*)dcMem.SelectObject(lpWnd->m_bmpBitmap);
	CRect lRect;
	//디스플레이 영역을 얻어낸다.
	GetClientRect(lRect);
	lRect.NormalizeRect();
	//다이얼로그 윈도우로 비트맵을 복사하면서 크기를 조정한다.
	pdc->StretchBlt(10,10,(lRect.Width()-20),
		(lRect.Height()-20),&dcMem,0,0,
		bm. bmWidth, bm.bmHeight, SRCCOPY);
}
