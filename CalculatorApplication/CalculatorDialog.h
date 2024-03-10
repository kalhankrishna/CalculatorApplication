#pragma once


// CalculatorDialog dialog

class CalculatorDialog : public CDialog
{
	DECLARE_DYNAMIC(CalculatorDialog)

public:
	CalculatorDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CalculatorDialog();

private:
	HINSTANCE hDll;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CalculatorDialog };
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
