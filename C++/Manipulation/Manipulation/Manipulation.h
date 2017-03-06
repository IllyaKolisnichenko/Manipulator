
// Manipulation.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CManipulationApp:
// О реализации данного класса см. Manipulation.cpp
//

class CManipulationApp : public CWinApp
{
public:
	CManipulationApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CManipulationApp theApp;