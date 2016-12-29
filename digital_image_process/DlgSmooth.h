#if !defined(AFX_DLGSMOOTH_H__DA1CA811_9B09_49C3_9598_E62B2757D073__INCLUDED_)
#define AFX_DLGSMOOTH_H__DA1CA811_9B09_49C3_9598_E62B2757D073__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSmooth.h : header file
//
/**********************************************/
// CDlgSmooth dialog

class CDlgSmooth : public CDialog
{
	// Construction
public:
	void UpdateEdit();
	double* m_fpArray;					// ģ��Ԫ������ָ��
	CDlgSmooth(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
//{{AFX_DATA(CDlgSmooth)
	enum { IDD = IDD_DLG_Smooth };		
	int m_intType;						// ģ������
	int m_iTempH;						// ģ��߶�
	int m_iTempW;						// ģ����
	int m_iTempMX;						// ģ������Ԫ��X����
	int m_iTempMY;						// ģ������Ԫ��Y����
	double   m_fTempC;					// ģ��ϵ��
	//}}AFX_DATA

// Overrides
// ClassWizard generated virtual function overrides
//{{AFX_VIRTUAL(CDlgSmooth)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSmooth)
	afx_msg void OnRad1();
	afx_msg void OnRad2();
	afx_msg void OnRad3();
	afx_msg void OnChangeEditTempw();
	virtual void OnOK();
	afx_msg void OnKillfocusEditTemph();
	afx_msg void OnKillfocusEditTempw();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSMOOTH_H__DA1CA811_9B09_49C3_9598_E62B2757D073__INCLUDED_)