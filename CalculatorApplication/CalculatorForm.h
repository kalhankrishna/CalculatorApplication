#pragma once



// CalculatorForm form view

class CalculatorForm : public CFormView
{
	DECLARE_DYNCREATE(CalculatorForm)

protected:
	CalculatorForm();           // protected constructor used by dynamic creation
	virtual ~CalculatorForm();

private:
	HINSTANCE hDll;

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CalculatorForm };
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
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonDivide();
	afx_msg void OnBnClickedButtonMultiply();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonDecimal();
	afx_msg void OnBnClickedButtonEquals();
	afx_msg void OnBnClickedButtonClear();
};


