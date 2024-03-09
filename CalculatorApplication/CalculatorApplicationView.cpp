
// CalculatorApplicationView.cpp : implementation of the CCalculatorApplicationView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CalculatorApplication.h"
#endif

#include "CalculatorApplicationDoc.h"
#include "CalculatorApplicationView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCalculatorApplicationView

IMPLEMENT_DYNCREATE(CCalculatorApplicationView, CView)

BEGIN_MESSAGE_MAP(CCalculatorApplicationView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCalculatorApplicationView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CCalculatorApplicationView construction/destruction

CCalculatorApplicationView::CCalculatorApplicationView() noexcept
{
	// TODO: add construction code here

}

CCalculatorApplicationView::~CCalculatorApplicationView()
{
}

BOOL CCalculatorApplicationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCalculatorApplicationView drawing

void CCalculatorApplicationView::OnDraw(CDC* /*pDC*/)
{
	CCalculatorApplicationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CCalculatorApplicationView printing


void CCalculatorApplicationView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCalculatorApplicationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCalculatorApplicationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCalculatorApplicationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CCalculatorApplicationView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCalculatorApplicationView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCalculatorApplicationView diagnostics

#ifdef _DEBUG
void CCalculatorApplicationView::AssertValid() const
{
	CView::AssertValid();
}

void CCalculatorApplicationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCalculatorApplicationDoc* CCalculatorApplicationView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCalculatorApplicationDoc)));
	return (CCalculatorApplicationDoc*)m_pDocument;
}
#endif //_DEBUG


// CCalculatorApplicationView message handlers
