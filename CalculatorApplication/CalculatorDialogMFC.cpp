// CalculatorDialogMFC.cpp : implementation file
//

#include "pch.h"
#include <Windows.h>
#include "CalculatorApplication.h"
#include "CalculatorDialogMFC.h"
#include "afxdialogex.h"
#include <iostream>
#include <afxwin.h>


// CalculatorDialogMFC dialog

IMPLEMENT_DYNAMIC(CalculatorDialogMFC, CDialog)

typedef double (*EvaluateExpressionFunc)(const std::string&);

CalculatorDialogMFC::CalculatorDialogMFC(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CalculatorDialogMFC, pParent), hDll(nullptr)
{
	// Load the DLL
	hDll = LoadLibrary(_T("MathFunctions.dll"));
	if (hDll == nullptr) {
		MessageBox(_T("Error: Could not load the DLL!"), _T("Error"), MB_ICONERROR);
	}
}

CalculatorDialogMFC::~CalculatorDialogMFC()
{
	if (hDll != nullptr) {
		FreeLibrary(hDll);
	}
}

void CalculatorDialogMFC::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

void CalculatorDialogMFC::OnButtonDigitClicked(UINT nID) {
	int digit = nID - IDC_MFCBUTTON0;

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

void CalculatorDialogMFC::OnButtonOperatorClicked(UINT nID)
{
	char op;
	switch (nID) {
	case IDC_MFCBUTTON_PLUS:
		op = '+';
		break;
	case IDC_MFCBUTTON_MINUS:
		op = '-';
		break;
	case IDC_MFCBUTTON_MULTIPLY:
		op = '*';
		break;
	case IDC_MFCBUTTON_DIVIDE:
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

BEGIN_MESSAGE_MAP(CalculatorDialogMFC, CDialog)
	ON_BN_CLICKED(IDC_MFCBUTTON0, &CalculatorDialogMFC::OnBnClickedMfcbutton0)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &CalculatorDialogMFC::OnBnClickedMfcbutton1)
	ON_BN_CLICKED(IDC_MFCBUTTON2, &CalculatorDialogMFC::OnBnClickedMfcbutton2)
	ON_BN_CLICKED(IDC_MFCBUTTON3, &CalculatorDialogMFC::OnBnClickedMfcbutton3)
	ON_BN_CLICKED(IDC_MFCBUTTON4, &CalculatorDialogMFC::OnBnClickedMfcbutton4)
	ON_BN_CLICKED(IDC_MFCBUTTON5, &CalculatorDialogMFC::OnBnClickedMfcbutton5)
	ON_BN_CLICKED(IDC_MFCBUTTON6, &CalculatorDialogMFC::OnBnClickedMfcbutton6)
	ON_BN_CLICKED(IDC_MFCBUTTON7, &CalculatorDialogMFC::OnBnClickedMfcbutton7)
	ON_BN_CLICKED(IDC_MFCBUTTON8, &CalculatorDialogMFC::OnBnClickedMfcbutton8)
	ON_BN_CLICKED(IDC_MFCBUTTON9, &CalculatorDialogMFC::OnBnClickedMfcbutton9)
	ON_BN_CLICKED(IDC_MFCBUTTON_DIVIDE, &CalculatorDialogMFC::OnBnClickedMfcbuttonDivide)
	ON_BN_CLICKED(IDC_MFCBUTTON_MULTIPLY, &CalculatorDialogMFC::OnBnClickedMfcbuttonMultiply)
	ON_BN_CLICKED(IDC_MFCBUTTON_MINUS, &CalculatorDialogMFC::OnBnClickedMfcbuttonMinus)
	ON_BN_CLICKED(IDC_MFCBUTTON_PLUS, &CalculatorDialogMFC::OnBnClickedMfcbuttonPlus)
	ON_BN_CLICKED(IDC_MFCBUTTON_DECIMAL, &CalculatorDialogMFC::OnBnClickedMfcbuttonDecimal)
	ON_BN_CLICKED(IDC_MFCBUTTON_EQUALS, &CalculatorDialogMFC::OnBnClickedMfcbuttonEquals)
	ON_BN_CLICKED(IDC_MFCBUTTON_CLEAR, &CalculatorDialogMFC::OnBnClickedMfcbuttonClear)
END_MESSAGE_MAP()


// CalculatorDialogMFC message handlers


void CalculatorDialogMFC::OnBnClickedMfcbutton0()
{
	OnButtonDigitClicked(IDC_MFCBUTTON0);
}


void CalculatorDialogMFC::OnBnClickedMfcbutton1()
{
	OnButtonDigitClicked(IDC_MFCBUTTON1);
}


void CalculatorDialogMFC::OnBnClickedMfcbutton2()
{
	OnButtonDigitClicked(IDC_MFCBUTTON2);
}


void CalculatorDialogMFC::OnBnClickedMfcbutton3()
{
	OnButtonDigitClicked(IDC_MFCBUTTON3);
}


void CalculatorDialogMFC::OnBnClickedMfcbutton4()
{
	OnButtonDigitClicked(IDC_MFCBUTTON4);
}


void CalculatorDialogMFC::OnBnClickedMfcbutton5()
{
	OnButtonDigitClicked(IDC_MFCBUTTON5);
}


void CalculatorDialogMFC::OnBnClickedMfcbutton6()
{
	OnButtonDigitClicked(IDC_MFCBUTTON6);
}


void CalculatorDialogMFC::OnBnClickedMfcbutton7()
{
	OnButtonDigitClicked(IDC_MFCBUTTON7);
}


void CalculatorDialogMFC::OnBnClickedMfcbutton8()
{
	OnButtonDigitClicked(IDC_MFCBUTTON8);
}


void CalculatorDialogMFC::OnBnClickedMfcbutton9()
{
	OnButtonDigitClicked(IDC_MFCBUTTON9);
}


void CalculatorDialogMFC::OnBnClickedMfcbuttonDivide()
{
	OnButtonOperatorClicked(IDC_MFCBUTTON_DIVIDE);
}


void CalculatorDialogMFC::OnBnClickedMfcbuttonMultiply()
{
	OnButtonOperatorClicked(IDC_MFCBUTTON_MULTIPLY);
}


void CalculatorDialogMFC::OnBnClickedMfcbuttonMinus()
{
	OnButtonOperatorClicked(IDC_MFCBUTTON_MINUS);
}


void CalculatorDialogMFC::OnBnClickedMfcbuttonPlus()
{
	OnButtonOperatorClicked(IDC_MFCBUTTON_PLUS);
}


void CalculatorDialogMFC::OnBnClickedMfcbuttonDecimal()
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


void CalculatorDialogMFC::OnBnClickedMfcbuttonEquals()
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


void CalculatorDialogMFC::OnBnClickedMfcbuttonClear()
{
	SetDlgItemText(IDC_EDIT1, _T(""));
}
