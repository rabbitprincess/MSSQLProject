// SelectDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "MyDatabase.h"
#include "SelectDlg.h"
#include "afxdialogex.h"
#include "MyDatabaseDlg.h"

IMPLEMENT_DYNAMIC(SelectDlg, CDialogEx)

SelectDlg::SelectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SELECT, pParent)
{
}

SelectDlg::~SelectDlg()
{
}

void SelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, Senario1_Combo1);
	DDX_Control(pDX, IDC_COMBO2, Senario1_Combo2);
	DDX_Control(pDX, IDC_COMBO3, Senario2_Combo2);
	DDX_Control(pDX, IDC_COMBO4, Senario6_Combo1);
}


BEGIN_MESSAGE_MAP(SelectDlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &SelectDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON3, &SelectDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &SelectDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &SelectDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON7, &SelectDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON4, &SelectDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &SelectDlg::OnBnClickedButton5)
	ON_CBN_SELCHANGE(IDC_COMBO1, &SelectDlg::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &SelectDlg::OnCbnSelchangeCombo2)
END_MESSAGE_MAP()


// SelectDlg 메시지 처리기


void SelectDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	CDialogEx::OnCancel();
}



void SelectDlg::OnBnClickedButton1()
{
	CString str = "";
	CMyDatabaseDlg *MyDlg = (CMyDatabaseDlg *)GetParent();
	Senario1_Combo1.GetLBText(Senario1_Combo1.GetCurSel(), str);
	MyDlg->SetTable(str);
	EndDialog(0);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void SelectDlg::OnBnClickedButton2()
{
	CString str = "";
	CMyDatabaseDlg *MyDlg = (CMyDatabaseDlg *)GetParent();
	Senario1_Combo2.GetLBText(Senario1_Combo2.GetCurSel(), str);
	MyDlg->SetTable(str);
	Senario2_Combo2.GetLBText(Senario2_Combo2.GetCurSel(), str);
	MyDlg->SetColumn(str);

	EndDialog(1);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void SelectDlg::OnBnClickedButton3()
{
	EndDialog(3);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void SelectDlg::OnBnClickedButton7()
{
	EndDialog(4);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void SelectDlg::OnBnClickedButton4()
{
	EndDialog(5);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void SelectDlg::OnBnClickedButton5()
{
	CString str = "";
	CMyDatabaseDlg *MyDlg = (CMyDatabaseDlg *)GetParent();
	Senario6_Combo1.GetLBText(Senario6_Combo1.GetCurSel(), str);
	MyDlg->SetTable(str);
	EndDialog(6);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void SelectDlg::OnCbnSelchangeCombo1()
{

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void SelectDlg::OnCbnSelchangeCombo2()
{
	CString temp = "";
	Senario1_Combo2.GetLBText(Senario1_Combo2.GetCurSel(), temp);
	CMyDatabaseDlg *MyDlg = (CMyDatabaseDlg *)GetParent();
	MyDlg->DBConnect();
	static SQLCHAR query[200];
	SQLHSTMT hStmt;
	SQLRETURN retcode;

	SQLCHAR		ColumnName[30][30];
	SQLSMALLINT	ColumnNameLen[30];
	SQLSMALLINT ColumnDataType[30];
	SQLULEN		ColumnDataSize[30];
	SQLSMALLINT	ColumnDataDigits[30];
	SQLSMALLINT	ColumnDataNullable[30];

	SQLSMALLINT numCols = -1;

	if (SQLAllocHandle(SQL_HANDLE_STMT, MyDlg->hDbc, &hStmt) == SQL_SUCCESS)
	{
		sprintf((char*)query, "SELECT * FROM %s", temp);
		retcode = SQLExecDirect(hStmt, query, SQL_NTS);
		SQLNumResultCols(hStmt, &numCols);
		if (retcode == SQL_ERROR || retcode == SQL_NO_DATA_FOUND) {
			MessageBox(_T("Query Execute Error"));
		}
		for (int i = 1; i <= numCols; i++)
		{
			SQLDescribeCol(hStmt, i, ColumnName[i], 30, &ColumnNameLen[i], &ColumnDataType[i], &ColumnDataSize[i], &ColumnDataDigits[i], &ColumnDataNullable[i]);
			Senario2_Combo2.AddString((char*)(ColumnName[i]));
		}
		SQLCloseCursor(hStmt);
		SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
	}
	MyDlg->DBDisconnect();

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}




BOOL SelectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CMyDatabaseDlg *MyDlg = (CMyDatabaseDlg *)GetParent();
	MyDlg->DBConnect();
	static SQLCHAR query[100];
	SQLHSTMT hStmt;
	if (SQLAllocHandle(SQL_HANDLE_STMT, MyDlg->hDbc, &hStmt) == SQL_SUCCESS) {
		sprintf((char*)query, ("SELECT TABLE_NAME FROM INFORMATION_SCHEMA.TABLES"));
		SQLExecDirect(hStmt, query, SQL_NTS);
		SQLCHAR empname[20];
		SQLBindCol(hStmt, 1, SQL_C_CHAR, empname, 20, NULL);
		int i = 0;
		while (SQLFetch(hStmt) != SQL_NO_DATA) {
			Senario1_Combo1.AddString((LPCTSTR)empname);
			Senario1_Combo2.AddString((LPCTSTR)empname);

		}
		SQLCloseCursor(hStmt);
		SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
	}
	MyDlg->DBDisconnect();

	MyDlg->DBConnect();
	if (SQLAllocHandle(SQL_HANDLE_STMT, MyDlg->hDbc, &hStmt) == SQL_SUCCESS) {
		SQLCHAR empname[20];
		sprintf((char*)query, ("SELECT MANAGER_NUM FROM DATAMANAGER"));
		SQLExecDirect(hStmt, query, SQL_NTS);
		SQLBindCol(hStmt, 1, SQL_C_CHAR, empname, 20, NULL);
		while (SQLFetch(hStmt) != SQL_NO_DATA) {
			Senario6_Combo1.AddString((LPCTSTR)empname);
		}
		SQLCloseCursor(hStmt);
		SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
	}
	MyDlg->DBDisconnect();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
