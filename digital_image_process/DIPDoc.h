#if !defined(AFX_DIPDemoDOC_H__766DD4EA_BF18_426A_BA52_B747D78F541C__INCLUDED_)
#define AFX_DIPDemoDOC_H__766DD4EA_BF18_426A_BA52_B747D78F541C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Img.h"
#include "ImgProcess.h"

class CDIPDoc : public CDocument
{
protected: // create from serialization only
	CDIPDoc();
	DECLARE_DYNCREATE(CDIPDoc)


	// Operations
public:
	CSize GetDocSize() const 
	{
		return m_sizeDoc;
	}
	CPalette* GetDocPalette() const 
	{	//�����߼���ɫ�壬��256ɫ��ʾģʽ����Ҫ
		return m_pPalette;
	}

// Overrides
// ClassWizard generated virtual function overrides
//{{AFX_VIRTUAL(CDIPDoc)
public:
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL CanCloseFrame(CFrameWnd* pFrame);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:
	CImgProcess m_Image;	// ��Ӧ��CImgProcess���󣨵�ǰ��
	CImgProcess m_OImage;	// ��Ӧ��CImgProcess���󣨺�̨��
	CPalette* m_pPalette;	// �߼���ɫ�壬��256ɫ��ʾģʽ����Ҫ
	void Init();			// ��ʼ��
	virtual ~CDIPDoc();	// DIPDemoDoc
	COLORREF m_refColorBKG; // ����ɫ
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	// Generated message map functions
protected:
	afx_msg void OnFileReopen();//{{AFX_MSG(CDIPDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
protected:
	CSize m_sizeDoc;
};

//{{AFX_INSERT_LOCATION}}
#endif // !defined(AFX_DIPDemoDOC_H__766DD4EA_BF18_426A_BA52_B747D78F541C__INCLUDED_)
