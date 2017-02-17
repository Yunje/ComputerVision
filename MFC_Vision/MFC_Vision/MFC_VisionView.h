
// MFC_VisionView.h : CMFC_VisionView Ŭ������ �������̽�
//

#pragma once


class CMFC_VisionView : public CView
{
protected: // serialization������ ��������ϴ�.
	CMFC_VisionView();
	DECLARE_DYNCREATE(CMFC_VisionView)

// Ư���Դϴ�.
public:
	CMFC_VisionDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMFC_VisionView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC_VisionView.cpp�� ����� ����
inline CMFC_VisionDoc* CMFC_VisionView::GetDocument() const
   { return reinterpret_cast<CMFC_VisionDoc*>(m_pDocument); }
#endif

