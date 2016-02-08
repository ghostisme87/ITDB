
// ITDBServerView.cpp : implementation of the CITDBServerView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ITDBServer.h"
#endif

#include "ITDBServerDoc.h"
#include "ITDBServerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CITDBServerView

IMPLEMENT_DYNCREATE(CITDBServerView, CScrollView)

BEGIN_MESSAGE_MAP(CITDBServerView, CScrollView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CITDBServerView construction/destruction

CITDBServerView::CITDBServerView()
{
	// TODO: add construction code here

}

CITDBServerView::~CITDBServerView()
{
}

BOOL CITDBServerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// CITDBServerView drawing

void CITDBServerView::OnDraw(CDC* /*pDC*/)
{
	CITDBServerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CITDBServerView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CITDBServerView printing

BOOL CITDBServerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CITDBServerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CITDBServerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CITDBServerView diagnostics

#ifdef _DEBUG
void CITDBServerView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CITDBServerView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CITDBServerDoc* CITDBServerView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CITDBServerDoc)));
	return (CITDBServerDoc*)m_pDocument;
}
#endif //_DEBUG


// CITDBServerView message handlers
