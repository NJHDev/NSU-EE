
// day1.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// Cday1App:
// �� Ŭ������ ������ ���ؼ��� day1.cpp�� �����Ͻʽÿ�.
//

class Cday1App : public CWinApp
{
public:
	Cday1App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern Cday1App theApp;