/* This file is part of IntelliData application developed by Mihai MOGA.

IntelliData is free software: you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the Open
Source Initiative, either version 3 of the License, or any later version.

IntelliData is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
IntelliData.  If not, see <http://www.opensource.org/licenses/gpl-3.0.html>*/

// IntelliDataView.h : interface of the CIntelliDataView class
//

#pragma once


class CIntelliDataView : public CListView
{
protected: // create from serialization only
	CIntelliDataView() noexcept;
	DECLARE_DYNCREATE(CIntelliDataView)

// Attributes
public:
	CIntelliDataDoc* GetDocument() const;

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
	virtual ~CIntelliDataView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in IntelliDataView.cpp
inline CIntelliDataDoc* CIntelliDataView::GetDocument() const
   { return reinterpret_cast<CIntelliDataDoc*>(m_pDocument); }
#endif

