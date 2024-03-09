#pragma once



// CalculatorFormMFC form view

class CalculatorFormMFC : public CFormView
{
	DECLARE_DYNCREATE(CalculatorFormMFC)

protected:
	CalculatorFormMFC();           // protected constructor used by dynamic creation
	virtual ~CalculatorFormMFC();

private:
	HINSTANCE hDll;

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CalculatorFormMFC };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

protected:
	void OnButtonDigitClicked(UINT nID);
	void OnButtonOperatorClicked(UINT nID);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMfcbutton0();
	afx_msg void OnBnClickedMfcbutton1();
	afx_msg void OnBnClickedMfcbutton2();
	afx_msg void OnBnClickedMfcbutton3();
	afx_msg void OnBnClickedMfcbutton4();
	afx_msg void OnBnClickedMfcbutton5();
	afx_msg void OnBnClickedMfcbutton6();
	afx_msg void OnBnClickedMfcbutton7();
	afx_msg void OnBnClickedMfcbutton8();
	afx_msg void OnBnClickedMfcbutton9();
	afx_msg void OnBnClickedMfcbuttonDivide();
	afx_msg void OnBnClickedMfcbuttonMultiply();
	afx_msg void OnBnClickedMfcbuttonMinus();
	afx_msg void OnBnClickedMfcbuttonPlus();
	afx_msg void OnBnClickedMfcbuttonDecimal();
	afx_msg void OnBnClickedMfcbuttonEquals();
	afx_msg void OnBnClickedMfcbuttonClear();
};


