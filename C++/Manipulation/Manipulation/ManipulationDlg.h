
// ManipulationDlg.h : ���� ���������
//

#pragma once
#include "afxwin.h"


// ���������� ���� CManipulationDlg
class CManipulationDlg : public CDialogEx
{
// ��������
public:
	CManipulationDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
	enum { IDD = IDD_MANIPULATION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
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
