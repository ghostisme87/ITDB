
// ITDBServerView.h : interface of the CITDBServerView class
//

#pragma once


class CITDBServerView : public CScrollView
{
protected: // create from serialization only
	CITDBServerView();
	DECLARE_DYNCREATE(CITDBServerView)

// Attributes
public:
	CITDBServerDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CITDBServerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ITDBServerView.cpp
inline CITDBServerDoc* CITDBServerView::GetDocument() const
   { return reinterpret_cast<CITDBServerDoc*>(m_pDocument); }
#endif

