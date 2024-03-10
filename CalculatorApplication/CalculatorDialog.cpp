// CalculatorDialog.cpp : implementation file
//

#include "pch.h"
#include <Windows.h>
#include "CalculatorApplication.h"
#include "CalculatorDialog.h"
#include <iostream>
#include <afxwin.h>
#include "afxdialogex.h"


// CalculatorDialog dialog

IMPLEMENT_DYNAMIC(CalculatorDialog, CDialog)

typedef double (*EvaluateExpressionFunc)(const std::string&);

CalculatorDialog::CalculatorDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CalculatorDialog, pParent), hDll(nullptr)
{
	// Load the DLL
	hDll = LoadLibrary(_T("MathFunctions.dll"));
	if (hDll == nullptr) {
		MessageBox(_T("Error: Could not load the DLL!"), _T("Error"), MB_ICONERROR);
	}
}

CalculatorDialog::~CalculatorDialog()
{
	if (hDll != nullptr) {
		FreeLibrary(hDll);
	}
}

void CalculatorDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

void CalculatorDialog::OnButtonDigitClicked(UINT nID) {
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

void CalculatorDialog::OnButtonOperatorClicked(UINT nID)
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

BEGIN_MESSAGE_MAP(CalculatorDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON0, &CalculatorDialog::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON1, &CalculatorDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CalculatorDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CalculatorDialog::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CalculatorDialog::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CalculatorDialog::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CalculatorDialog::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CalculatorDialog::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CalculatorDialog::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CalculatorDialog::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CalculatorDialog::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, &CalculatorDialog::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CalculatorDialog::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CalculatorDialog::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_DECIMAL, &CalculatorDialog::OnBnClickedButtonDecimal)
	ON_BN_CLICKED(IDC_BUTTON_EQUALS, &CalculatorDialog::OnBnClickedButtonEquals)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CalculatorDialog::OnBnClickedButtonClear)
END_MESSAGE_MAP()


// CalculatorDialog message handlers


void CalculatorDialog::OnBnClickedButton0()
{
	OnButtonDigitClicked(IDC_BUTTON0);
}


void CalculatorDialog::OnBnClickedButton1()
{
	OnButtonDigitClicked(IDC_BUTTON1);
}


void CalculatorDialog::OnBnClickedButton2()
{
	OnButtonDigitClicked(IDC_BUTTON2);
}


void CalculatorDialog::OnBnClickedButton3()
{
	OnButtonDigitClicked(IDC_BUTTON3);
}


void CalculatorDialog::OnBnClickedButton4()
{
	OnButtonDigitClicked(IDC_BUTTON4);
}


void CalculatorDialog::OnBnClickedButton5()
{
	OnButtonDigitClicked(IDC_BUTTON5);
}


void CalculatorDialog::OnBnClickedButton6()
{
	OnButtonDigitClicked(IDC_BUTTON6);
}


void CalculatorDialog::OnBnClickedButton7()
{
	OnButtonDigitClicked(IDC_BUTTON7);
}


void CalculatorDialog::OnBnClickedButton8()
{
	OnButtonDigitClicked(IDC_BUTTON8);
}


void CalculatorDialog::OnBnClickedButton9()
{
	OnButtonDigitClicked(IDC_BUTTON9);
}


void CalculatorDialog::OnBnClickedButtonDivide()
{
	OnButtonOperatorClicked(IDC_BUTTON_DIVIDE);
}


void CalculatorDialog::OnBnClickedButtonMultiply()
{
	OnButtonOperatorClicked(IDC_BUTTON_MULTIPLY);
}


void CalculatorDialog::OnBnClickedButtonMinus()
{
	OnButtonOperatorClicked(IDC_BUTTON_MINUS);
}


void CalculatorDialog::OnBnClickedButtonPlus()
{
	OnButtonOperatorClicked(IDC_BUTTON_PLUS);
}


void CalculatorDialog::OnBnClickedButtonDecimal()
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


void CalculatorDialog::OnBnClickedButtonEquals()
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


void CalculatorDialog::OnBnClickedButtonClear()
{
	SetDlgItemText(IDC_EDIT1, _T(""));
}

