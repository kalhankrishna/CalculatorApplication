// CalculatorForm.cpp : implementation file
//

#include "pch.h"
#include <Windows.h>
#include "CalculatorApplication.h"
#include "CalculatorForm.h"
#include <iostream>
#include <afxwin.h>


// CalculatorForm

IMPLEMENT_DYNCREATE(CalculatorForm, CFormView)

typedef double (*EvaluateExpressionFunc)(const std::string&);

CalculatorForm::CalculatorForm()
	: CFormView(IDD_CalculatorForm), hDll(nullptr)
{
	// Load the DLL
	hDll = LoadLibrary(_T("MathFunctions.dll"));
	if (hDll == nullptr) {
		MessageBox(_T("Error: Could not load the DLL!"), _T("Error"), MB_ICONERROR);
	}
}

CalculatorForm::~CalculatorForm()
{
	if (hDll != nullptr) {
		FreeLibrary(hDll);
	}
}

void CalculatorForm::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

void CalculatorForm::OnButtonDigitClicked(UINT nID) {
	int digit = nID - IDC_BUTTON0;

	CEdit* pEditControl = (CEdit*)GetDlgItem(IDC_EDIT1);
	if (pEditControl == nullptr) {
		MessageBox(_T("Error: Something went wrong in getting the handle!"), _T("Error"), MB_ICONERROR);
		return;
	}

	CString currentExpression;
	pEditControl->GetWindowText(currentExpression);
	currentExpression.AppendFormat(_T("%d"), digit);
	pEditControl->SetWindowText(currentExpression);
}

void CalculatorForm::OnButtonOperatorClicked(UINT nID)
{
	char op;
	switch (nID) {
	case IDC_BUTTON_PLUS:
		op = '+';
		break;
	case IDC_BUTTON_MINUS:
		op = '-';
		break;
	case IDC_BUTTON_MULTIPLY:
		op = '*';
		break;
	case IDC_BUTTON_DIVIDE:
		op = '/';
		break;
	default:
		return;
	}

	CString currentExpression;
	GetDlgItemText(IDC_EDIT1, currentExpression);
	currentExpression += CString(op);
	SetDlgItemText(IDC_EDIT1, currentExpression);
}

BEGIN_MESSAGE_MAP(CalculatorForm, CFormView)
	ON_BN_CLICKED(IDC_BUTTON0, &CalculatorForm::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON1, &CalculatorForm::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CalculatorForm::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CalculatorForm::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CalculatorForm::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CalculatorForm::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CalculatorForm::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CalculatorForm::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CalculatorForm::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CalculatorForm::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CalculatorForm::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, &CalculatorForm::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CalculatorForm::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CalculatorForm::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_DECIMAL, &CalculatorForm::OnBnClickedButtonDecimal)
	ON_BN_CLICKED(IDC_BUTTON_EQUALS, &CalculatorForm::OnBnClickedButtonEquals)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CalculatorForm::OnBnClickedButtonClear)
END_MESSAGE_MAP()


// CalculatorForm diagnostics

#ifdef _DEBUG
void CalculatorForm::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CalculatorForm::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CalculatorForm message handlers


void CalculatorForm::OnBnClickedButton0()
{
	OnButtonDigitClicked(IDC_BUTTON0);
}


void CalculatorForm::OnBnClickedButton1()
{
	OnButtonDigitClicked(IDC_BUTTON1);
}


void CalculatorForm::OnBnClickedButton2()
{
	OnButtonDigitClicked(IDC_BUTTON2);
}


void CalculatorForm::OnBnClickedButton3()
{
	OnButtonDigitClicked(IDC_BUTTON3);
}


void CalculatorForm::OnBnClickedButton4()
{
	OnButtonDigitClicked(IDC_BUTTON4);
}


void CalculatorForm::OnBnClickedButton5()
{
	OnButtonDigitClicked(IDC_BUTTON5);
}


void CalculatorForm::OnBnClickedButton6()
{
	OnButtonDigitClicked(IDC_BUTTON6);
}


void CalculatorForm::OnBnClickedButton7()
{
	OnButtonDigitClicked(IDC_BUTTON7);
}


void CalculatorForm::OnBnClickedButton8()
{
	OnButtonDigitClicked(IDC_BUTTON8);
}


void CalculatorForm::OnBnClickedButton9()
{
	OnButtonDigitClicked(IDC_BUTTON9);
}


void CalculatorForm::OnBnClickedButtonDivide()
{
	OnButtonOperatorClicked(IDC_BUTTON_DIVIDE);
}


void CalculatorForm::OnBnClickedButtonMultiply()
{
	OnButtonOperatorClicked(IDC_BUTTON_MULTIPLY);
}


void CalculatorForm::OnBnClickedButtonMinus()
{
	OnButtonOperatorClicked(IDC_BUTTON_MINUS);
}


void CalculatorForm::OnBnClickedButtonPlus()
{
	OnButtonOperatorClicked(IDC_BUTTON_PLUS);
}


void CalculatorForm::OnBnClickedButtonDecimal()
{
	CString currentExpression;
	GetDlgItemText(IDC_EDIT1, currentExpression);

	// Find the position of the last operator
	int lastOperatorPos = -1;
	const char* operators = "+-*/";
	for (int i = currentExpression.GetLength() - 1; i >= 0; i--) {
		if (strchr(operators, currentExpression[i]) != nullptr) {
			lastOperatorPos = i;
			break;
		}
	}

	// Check if the current expression contains a decimal point after the last operator
	if (currentExpression.ReverseFind('.') == -1 || currentExpression.ReverseFind('.') < lastOperatorPos) {
		currentExpression += ".";
		SetDlgItemText(IDC_EDIT1, currentExpression);
	}
}


void CalculatorForm::OnBnClickedButtonEquals()
{
	CString expression;
	GetDlgItemText(IDC_EDIT1, expression);

	// Tokenize the expression
	CString spacedExpression;
	for (int i = 0; i < expression.GetLength(); ++i) {
		if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
			spacedExpression += ' ';
			spacedExpression += expression[i];
			spacedExpression += ' ';
		}
		else {
			spacedExpression += expression[i];
		}
	}

	CStringA spacedExpressionA(spacedExpression);
	const std::string expressionStr = spacedExpressionA;

	EvaluateExpressionFunc evaluateExpression = (EvaluateExpressionFunc)GetProcAddress(hDll, "evaluateExpression");

	if (evaluateExpression) {
		double result = evaluateExpression(expressionStr);

		if (result == -1) {
			MessageBox(_T("Error: Invalid Expression!"), _T("Error"), MB_ICONERROR);
		}
		else {
			CString strResult;
			strResult.Format(_T("%g"), result);
			SetDlgItemText(IDC_EDIT1, strResult);
		}
	}
	else {
		MessageBox(_T("Error: The function evaluateExpression was not found in the DLL"), _T("Error"), MB_ICONERROR);
	}
}


void CalculatorForm::OnBnClickedButtonClear()
{
	SetDlgItemText(IDC_EDIT1, _T(""));
}
