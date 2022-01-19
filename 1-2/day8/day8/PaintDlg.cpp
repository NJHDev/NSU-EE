// PaintDlg.cpp : ���� �����Դϴ�.
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

// CPaintDlg ��ȭ �����Դϴ�.

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


// CPaintDlg �޽��� ó�����Դϴ�.


void CPaintDlg::DrawLine(CPaintDC* pdc, int iColor)
{
	//�� ����&����
	CPen lSolidPen (PS_SOLID, 1, m_crColors[iColor]);
	CPen lDotPen (PS_DOT, 1, m_crColors[iColor]);
	CPen lDashPen (PS_DASH, 1, m_crColors[iColor]);
	CPen lDashDotPen (PS_DASHDOT, 1, m_crColors[iColor]);
	CPen lDashDotDotPen (PS_DASHDOTDOT, 1, m_crColors[iColor]);
	CPen lNullPen (PS_NULL, 1, m_crColors[iColor]);
	CPen lInsidePen (PS_INSIDEFRAME, 1, m_crColors[iColor]);
	
	//�׸� ���� ���
	CRect lRect;
	GetClientRect(lRect);
	lRect.NormalizeRect();

	//�� ������ �Ÿ� ���
	CPoint pStart;
	CPoint pEnd;
	int liDist = lRect.Height() / 8;
	CPen *lOldPen;

	//������ ����
	pStart.y = lRect.top;
	pStart.x = lRect.left;
	pEnd.y = pStart.y;
	pEnd.x = lRect.right;
	int i;

	//����� ��� ��ȯ
	for ( i = 0; i < 7; i++ )
	{
		//� ��?
		switch(i)
		{
		case 0 : //�Ǽ�
			lOldPen = pdc->SelectObject(&lSolidPen);
			break;
		case 1 : //����
			pdc->SelectObject(&lDotPen);
			break;
		case 2 : //�⼱
			lOldPen = pdc->SelectObject(&lDashPen);
			break;
		case 3 : //���⼱
			pdc->SelectObject(&lDashDotPen);
			break;
		case 4 : //���� �⼱
			lOldPen = pdc->SelectObject(&lDashDotDotPen);
			break;
		case 5 : //����
			pdc->SelectObject(&lNullPen);
			break;
		case 6 : //����
			lOldPen = pdc->SelectObject(&lInsidePen);
			break;
		}
		//���� �Ʒ� ��ġ�� �̵�
		pStart.y = pStart.y + liDist;
		pEnd.y = pStart.y;
		//�� �׸���
		pdc->MoveTo(pStart);
		pdc->LineTo(pEnd);
	}
	//���� ������ �ǵ�����
	pdc->SelectObject(lOldPen);
}


void CPaintDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	//�θ� �������� ������ ���
	Cday8Dlg *pWnd = (Cday8Dlg*)GetParent();

	//�����Ͱ� ����� ������?
	if(pWnd)
	{
		//if ���õ� ���� = ��Ʈ��
		if(pWnd->m_iTool ==2)
		{
			//��Ʈ���� ���õǾ��ְ� �ε�Ǿ�����?
			if (pWnd->m_sBitmap !="")
				//ǥ������
				ShowBitmap(&dc, pWnd);
		}
		else	//�ƴ�, �����׸��°���
		{
			//�� �׸��°���?
			if (pWnd->m_iShape == 0)
				DrawLine(&dc, pWnd->m_iColor);
			else  //��,�簢�� �׸�����
				DrawRegion(&dc, pWnd->m_iColor, pWnd->m_iTool, pWnd->m_iShape);
		}
	}
	// �׸��� �޽����� ���ؼ��� CDialog::OnPaint()��(��) ȣ������ ���ʽÿ�.
}


void CPaintDlg::DrawRegion(CPaintDC* pdc, int iColor, int iTool, int iShape)
{
	// ���� �����ϰ� ����
	CPen lSolidPen (PS_SOLID, 1, m_crColors[iColor]);
	CPen lDotPen (PS_DOT, 1, m_crColors[iColor]);
	CPen lDashPen (PS_DASH, 1, m_crColors[iColor]);
	CPen lDashDotPen (PS_DASHDOT, 1, m_crColors[iColor]);
	CPen lDashDotDotPen (PS_DASHDOTDOT, 1, m_crColors[iColor]);
	CPen lNullPen (PS_NULL, 1, m_crColors[iColor]);
	CPen lInsidePen (PS_INSIDEFRAME, 1, m_crColors[iColor]);

	// �귯�� �����ϰ� ����
	CBrush lSolidBrush(m_crColors[iColor]);
	CBrush lBDiagBrush(HS_BDIAGONAL, m_crColors[iColor]);
	CBrush lCrossBrush(HS_CROSS, m_crColors[iColor]);
	CBrush lDiagCrossBrush(HS_DIAGCROSS, m_crColors[iColor]);
	CBrush lFDiagBrush(HS_FDIAGONAL, m_crColors[iColor]);
	CBrush lHorizBrush(HS_HORIZONTAL, m_crColors[iColor]);
	CBrush lVertBrush(HS_VERTICAL, m_crColors[iColor]);
	CBrush lNullBrush(RGB(192, 192, 192));

	//�׸� ������ ũ�� ���
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
	//��� ��� �귯���� ���� ����
	for (i = 0; i < 7; i++)
	{
		switch (i)
		{
		case 0: // �Ǽ�
			// ������ ��ġ ����
			// ù°�� ����
			lDrawRect.top = lRect.top + 5;
			lDrawRect.left = lRect.left + 5;
			lDrawRect.bottom = lDrawRect.top + iHeight;
			lDrawRect.right = lDrawRect.left + iWidth;
			//������ ��� �귯�� ����
			pOldPen = pdc->SelectObject(&lSolidPen);
			pOldBrush = pdc->SelectObject(&lSolidBrush);
			break;

		case 1: //����, ���밢 ���� �귯��
			//������ ��ġ ����
			lDrawRect.left = lDrawRect.left + iHorz;
			lDrawRect.right = lDrawRect.left + iWidth;
			//������ ��� �귯�� ����
			pdc->SelectObject(&lDotPen);
			pdc->SelectObject(&lBDiagBrush);
			break;
		case 2: //�⼱, �ٵ��� ���� �귯��
			//������ ��ġ ����
			lDrawRect.left = lDrawRect.left + iHorz;
			lDrawRect.right = lDrawRect.left + iWidth;
			//������ ��� �귯�� ����
			pdc->SelectObject(&lDashPen);
			pdc->SelectObject(&lCrossBrush);
			break;
		case 3: //�� �⼱ -X�� ���� �귯��
			//������ ��ġ ����
			lDrawRect.left = lDrawRect.left + iHorz;
			lDrawRect.right = lDrawRect.left + iWidth;
			//������ ��� �귯�� ����
			pdc->SelectObject(&lDashDotPen);
			pdc->SelectObject(&lDiagCrossBrush);
			break;
		case 4: //���� �⼱, �밢 ���� �귯��
			//������ ��ġ ����
			//��°�� ����
			lDrawRect.top = lDrawRect.top + iVert;
			lDrawRect.left = lRect.left + 5;
			lDrawRect.bottom = lDrawRect.top + iHeight;
			lDrawRect.right = lDrawRect.left + iWidth;
			//������ ��� �귯�� ����
			pdc->SelectObject(&lDashDotDotPen);
			pdc->SelectObject(&lFDiagBrush);
			break;
		case 5: //�� ��, ���򹫴� �귯��
			//������ ��ġ ����
			lDrawRect.left = lDrawRect.left + iHorz;
			lDrawRect.right = lDrawRect.left + iWidth;
			//������ ��� �귯�� ����
			pdc->SelectObject(&lNullPen);
			pdc->SelectObject(&lHorizBrush);
			break;
		case 6: //����, ���� ���� �귯��
			//������ ��ġ ����
			lDrawRect.left = lDrawRect.left + iHorz;
			lDrawRect.right = lDrawRect.left + iWidth;
			//������ ��� �귯�� ����
			pdc->SelectObject(&lInsidePen);
			pdc->SelectObject(&lVertBrush);
			break;
		}
		//� ���� �����?
		if (iTool == 0)
			pdc->SelectObject(lNullBrush);
		else
			pdc->SelectObject(lNullPen);
		//� ���� �׸�����?
		if (iShape == 1)
			pdc->Ellipse(lDrawRect);
		else
			pdc->Rectangle(lDrawRect);
	}

	// ���� �귯���� �ǵ�����
	pdc->SelectObject(pOldBrush);
	pdc->SelectObject(pOldPen);
}

void CPaintDlg::ShowBitmap(CPaintDC* pdc, CWnd* pWnd)
{
	//�����͸� ���� ���̾�α� Ŭ������ �����ͷ� ĳ�����Ѵ�.
	Cday8Dlg *lpWnd=(Cday8Dlg*)pWnd;
	BITMAP bm;
	lpWnd->m_bmpBitmap.GetBitmap(&bm);
	CDC dcMem;
	//��Ʈ���� �ε��� ȣȯ ����̽� ���ؽ�Ʈ�� �����Ѵ�.
	dcMem.CreateCompatibleDC(pdc);
	//ȣȯ ����̽� ���ؽ�Ʈ�� ��Ʈ���� ������ �ִ´�.
	CBitmap* pOldBitmap=(CBitmap*)dcMem.SelectObject(lpWnd->m_bmpBitmap);
	CRect lRect;
	//���÷��� ������ ����.
	GetClientRect(lRect);
	lRect.NormalizeRect();
	//���̾�α� ������� ��Ʈ���� �����ϸ鼭 ũ�⸦ �����Ѵ�.
	pdc->StretchBlt(10,10,(lRect.Width()-20),
		(lRect.Height()-20),&dcMem,0,0,
		bm. bmWidth, bm.bmHeight, SRCCOPY);
}
