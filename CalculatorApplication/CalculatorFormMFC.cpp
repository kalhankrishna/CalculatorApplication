// CalculatorFormMFC.cpp : implementation file
//

#include "pch.h"
#include <Windows.h>
#include "CalculatorApplication.h"
#include "CalculatorFormMFC.h"
#include <iostream>
#include <afxwin.h>


// CalculatorFormMFC

IMPLEMENT_DYNCREATE(CalculatorFormMFC, CFormView)

typedef double (*EvaluateExpressionFunc)(const std::string&);

CalculatorFormMFC::CalculatorFormMFC()
	: CFormView(IDD_CalculatorFormMFC), hDll(nullptr)
{
	// Load the DLL
	hDll = LoadLibrary(_T("MathFunctions.dll"));
	if (hDll == nullptr) {
		MessageBox(_T("Error: Could not load the DLL!"), _T("Error"), MB_ICONERROR);
	}
}

CalculatorFormMFC::~CalculatorFormMFC()
{
	if (hDll != nullptr) {
		FreeLibrary(hDll);
	}
}

void CalculatorFormMFC::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

void CalculatorFormMFC::OnButtonDigitClicked(UINT nID) {
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

void CalculatorFormMFC::OnButtonOperatorClicked(UINT nID)
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

BEGIN_MESSAGE_MAP(CalculatorFormMFC, CFormView)
	ON_BN_CLICKED(IDC_MFCBUTTON0, &CalculatorFormMFC::OnBnClickedMfcbutton0)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &CalculatorFormMFC::OnBnClickedMfcbutton1)
	ON_BN_CLICKED(IDC_MFCBUTTON2, &CalculatorFormMFC::OnBnClickedMfcbutton2)
	ON_BN_CLICKED(IDC_MFCBUTTON3, &CalculatorFormMFC::OnBnClickedMfcbutton3)
	ON_BN_CLICKED(IDC_MFCBUTTON4, &CalculatorFormMFC::OnBnClickedMfcbutton4)
	ON_BN_CLICKED(IDC_MFCBUTTON5, &CalculatorFormMFC::OnBnClickedMfcbutton5)
	ON_BN_CLICKED(IDC_MFCBUTTON6, &CalculatorFormMFC::OnBnClickedMfcbutton6)
	ON_BN_CLICKED(IDC_MFCBUTTON7, &CalculatorFormMFC::OnBnClickedMfcbutton7)
	ON_BN_CLICKED(IDC_MFCBUTTON8, &CalculatorFormMFC::OnBnClickedMfcbutton8)
	ON_BN_CLICKED(IDC_MFCBUTTON9, &CalculatorFormMFC::OnBnClickedMfcbutton9)
	ON_BN_CLICKED(IDC_MFCBUTTON_DIVIDE, &CalculatorFormMFC::OnBnClickedMfcbuttonDivide)
	ON_BN_CLICKED(IDC_MFCBUTTON_MULTIPLY, &CalculatorFormMFC::OnBnClickedMfcbuttonMultiply)
	ON_BN_CLICKED(IDC_MFCBUTTON_MINUS, &CalculatorFormMFC::OnBnClickedMfcbuttonMinus)
	ON_BN_CLICKED(IDC_MFCBUTTON_PLUS, &CalculatorFormMFC::OnBnClickedMfcbuttonPlus)
	ON_BN_CLICKED(IDC_MFCBUTTON_DECIMAL, &CalculatorFormMFC::OnBnClickedMfcbuttonDecimal)
	ON_BN_CLICKED(IDC_MFCBUTTON_EQUALS, &CalculatorFormMFC::OnBnClickedMfcbuttonEquals)
	ON_BN_CLICKED(IDC_MFCBUTTON_CLEAR, &CalculatorFormMFC::OnBnClickedMfcbuttonClear)
END_MESSAGE_MAP()


// CalculatorFormMFC diagnostics

#ifdef _DEBUG
void CalculatorFormMFC::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CalculatorFormMFC::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CalculatorFormMFC message handlers


void CalculatorFormMFC::OnBnClickedMfcbutton0()
{
	OnButtonDigitClicked(IDC_MFCBUTTON0);
}


void CalculatorFormMFC::OnBnClickedMfcbutton1()
{
	OnButtonDigitClicked(IDC_MFCBUTTON1);
}


void CalculatorFormMFC::OnBnClickedMfcbutton2()
{
	OnButtonDigitClicked(IDC_MFCBUTTON2);
}


void CalculatorFormMFC::OnBnClickedMfcbutton3()
{
	OnButtonDigitClicked(IDC_MFCBUTTON3);
}


void CalculatorFormMFC::OnBnClickedMfcbutton4()
{
	OnButtonDigitClicked(IDC_MFCBUTTON4);
}


void CalculatorFormMFC::OnBnClickedMfcbutton5()
{
	OnButtonDigitClicked(IDC_MFCBUTTON5);
}


void CalculatorFormMFC::OnBnClickedMfcbutton6()
{
	OnButtonDigitClicked(IDC_MFCBUTTON6);
}


void CalculatorFormMFC::OnBnClickedMfcbutton7()
{
	OnButtonDigitClicked(IDC_MFCBUTTON7);
}


void CalculatorFormMFC::OnBnClickedMfcbutton8()
{
	OnButtonDigitClicked(IDC_MFCBUTTON8);
}


void CalculatorFormMFC::OnBnClickedMfcbutton9()
{
	OnButtonDigitClicked(IDC_MFCBUTTON9);
}


void CalculatorFormMFC::OnBnClickedMfcbuttonDivide()
{
	OnButtonOperatorClicked(IDC_MFCBUTTON_DIVIDE);
}


void CalculatorFormMFC::OnBnClickedMfcbuttonMultiply()
{
	OnButtonOperatorClicked(IDC_MFCBUTTON_MULTIPLY);
}


void CalculatorFormMFC::OnBnClickedMfcbuttonMinus()
{
	OnButtonOperatorClicked(IDC_MFCBUTTON_MINUS);
}


void CalculatorFormMFC::OnBnClickedMfcbuttonPlus()
{
	OnButtonOperatorClicked(IDC_MFCBUTTON_PLUS);
}


void CalculatorFormMFC::OnBnClickedMfcbuttonDecimal()
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


void CalculatorFormMFC::OnBnClickedMfcbuttonEquals()
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


void CalculatorFormMFC::OnBnClickedMfcbuttonClear()
{
	SetDlgItemText(IDC_EDIT1, _T(""));
}
