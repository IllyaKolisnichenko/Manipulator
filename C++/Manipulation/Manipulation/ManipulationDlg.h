
// ManipulationDlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"


// диалоговое окно CManipulationDlg
class CManipulationDlg : public CDialogEx
{
// Создание
public:
	CManipulationDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_MANIPULATION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMove();
	afx_msg void OnBnClickedA1();
	CMFCButton a1;
};
