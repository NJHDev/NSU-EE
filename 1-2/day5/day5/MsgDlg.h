#pragma once


// CMsgDlg ��ȭ �����Դϴ�.

class CMsgDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMsgDlg)

public:
	CMsgDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMsgDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MESSAGEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_sMessage;
	int m_iOption;
private:
//	CMsgDlg mk_dMsgDlg;
};
