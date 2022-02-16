/* This file is part of IntelliData application developed by Mihai MOGA.

IntelliData is free software: you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the Open
Source Initiative, either version 3 of the License, or any later version.

IntelliData is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
IntelliData.  If not, see <http://www.opensource.org/licenses/gpl-3.0.html>*/

// IntelliDataView.cpp : implementation of the CIntelliDataView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "IntelliData.h"
#endif

#include "IntelliDataDoc.h"
#include "IntelliDataView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIntelliDataView

IMPLEMENT_DYNCREATE(CIntelliDataView, CListView)

BEGIN_MESSAGE_MAP(CIntelliDataView, CListView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CIntelliDataView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CIntelliDataView construction/destruction

CIntelliDataView::CIntelliDataView() noexcept
{
	// TODO: add construction code here

}

CIntelliDataView::~CIntelliDataView()
{
}

BOOL CIntelliDataView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CListView::PreCreateWindow(cs);
}


void CIntelliDataView::OnDraw(CDC* /*pDC*/)
{
	CIntelliDataDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}


void CIntelliDataView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().
}


// CIntelliDataView printing


void CIntelliDataView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CIntelliDataView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CIntelliDataView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CIntelliDataView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CIntelliDataView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CIntelliDataView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CIntelliDataView diagnostics

#ifdef _DEBUG
void CIntelliDataView::AssertValid() const
{
	CListView::AssertValid();
}

void CIntelliDataView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CIntelliDataDoc* CIntelliDataView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIntelliDataDoc)));
	return (CIntelliDataDoc*)m_pDocument;
}
#endif //_DEBUG


// CIntelliDataView message handlers
