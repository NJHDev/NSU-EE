#pragma once


// CMsgDlg 대화 상자입니다.

class CMsgDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMsgDlg)

public:
	CMsgDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMsgDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MESSAGEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_sMessage;
	int m_iOption;
private:
//	CMsgDlg mk_dMsgDlg;
};
