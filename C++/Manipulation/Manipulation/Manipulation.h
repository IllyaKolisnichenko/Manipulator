
// Manipulation.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CManipulationApp:
// � ���������� ������� ������ ��. Manipulation.cpp
//

class CManipulationApp : public CWinApp
{
public:
	CManipulationApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CManipulationApp theApp;