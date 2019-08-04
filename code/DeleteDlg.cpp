// DeleteDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "MyDatabase.h"
#include "DeleteDlg.h"
#include "afxdialogex.h"
#include "MyDatabaseDlg.h"

// DeleteDlg 대화 상자

IMPLEMENT_DYNAMIC(DeleteDlg, CDialogEx)

DeleteDlg::DeleteDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DELETE, pParent)
{

}

DeleteDlg::~DeleteDlg()
{
}

void DeleteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO2, Senario1_Combo2);
	DDX_Control(pDX, IDC_COMBO1, Senario2_Combo1);
	DDX_Control(pDX, IDC_COMBO3, Senario3_Combo1);
	DDX_Control(pDX, IDC_COMBO4, Senario3_Combo2);
	DDX_Control(pDX, IDC_COMBO5, Senario4_Combo1);
}


BEGIN_MESSAGE_MAP(DeleteDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DeleteDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DeleteDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &DeleteDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &DeleteDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDCANCEL, &DeleteDlg::OnBnClickedCancel)
	ON_CBN_SELCHANGE(IDC_COMBO2, &DeleteDlg::OnCbnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO3, &DeleteDlg::OnCbnSelchangeCombo3)
END_MESSAGE_MAP()


// DeleteDlg 메시지 처리기


void DeleteDlg::OnBnClickedButton1()
{
	CString str = "";
	CMyDatabaseDlg *MyDlg = (CMyDatabaseDlg *)GetParent();
	Senario1_Combo2.GetLBText(Senario1_Combo2.GetCurSel(), str);
	MyDlg->SetTable(str);
	EndDialog(0);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void DeleteDlg::OnBnClickedButton2()
{
	CString str = "";
	CMyDatabaseDlg *MyDlg = (CMyDatabaseDlg *)GetParent();
	Senario2_Combo1.GetLBText(Senario2_Combo1.GetCurSel(), str);
	MyDlg->SetTable(str);
	EndDialog(1);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void DeleteDlg::OnBnClickedButton3()
{
	CString str = "";
	CMyDatabaseDlg *MyDlg = (CMyDatabaseDlg *)GetParent();
	Senario3_Combo1.GetLBText(Senario3_Combo1.GetCurSel(), str);
	MyDlg->SetStr1(str);
	Senario3_Combo2.GetLBText(Senario3_Combo2.GetCurSel(), str);
	MyDlg->SetStr2(str);
	EndDialog(3);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void DeleteDlg::OnBnClickedButton4()
{
	CString str = "";
	CMyDatabaseDlg *MyDlg = (CMyDatabaseDlg *)GetParent();
	Senario4_Combo1.GetLBText(Senario4_Combo1.GetCurSel(), str);
	MyDlg->SetTable(str);
	EndDialog(4);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void DeleteDlg::OnBnClickedCancel()
{

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.  
	CDialogEx::OnCancel();
}


BOOL DeleteDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	CMyDatabaseDlg *MyDlg = (CMyDatabaseDlg *)GetParent();
	MyDlg->DBConnect();
	static SQLCHAR query[100];
	SQLHSTMT hStmt;
	if (SQLAllocHandle(SQL_HANDLE_STMT, MyDlg->hDbc, &hStmt) == SQL_SUCCESS) {
		SQLCHAR empname[20];
		sprintf((char*)query, ("SELECT CLIENT_NUM FROM CLIENT"));
		SQLExecDirect(hStmt, query, SQL_NTS);
		SQLBindCol(hStmt, 1, SQL_C_CHAR, empname, 20, NULL);
		while (SQLFetch(hStmt) != SQL_NO_DATA) {
			Senario1_Combo2.AddString((LPCTSTR)empname);
		}

		SQLCloseCursor(hStmt);
		SQLFreeHandle(SQL_HANDLE_STMT, hStmt);

	}
	MyDlg->DBDisconnect();
	MyDlg->DBConnect();
	if (SQLAllocHandle(SQL_HANDLE_STMT, MyDlg->hDbc, &hStmt) == SQL_SUCCESS) {
		SQLCHAR empname[20];
		sprintf((char*)query, ("SELECT LAN_NUM FROM LANGUAGEDATA"));
		SQLExecDirect(hStmt, query, SQL_NTS);
		SQLBindCol(hStmt, 1, SQL_C_CHAR, empname, 20, NULL);
		while (SQLFetch(hStmt) != SQL_NO_DATA) {
			Senario2_Combo1.AddString((LPCTSTR)empname);
			Senario3_Combo1.AddString((LPCTSTR)empname);
		}
		SQLCloseCursor(hStmt);
		SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
	}
	MyDlg->DBDisconnect();
	MyDlg->DBConnect();
	if (SQLAllocHandle(SQL_HANDLE_STMT, MyDlg->hDbc, &hStmt) == SQL_SUCCESS) {
		SQLCHAR empname[20];
		sprintf((char*)query, ("SELECT PROJECT_NUM FROM PROJECT"));
		SQLExecDirect(hStmt, query, SQL_NTS);
		SQLBindCol(hStmt, 1, SQL_C_CHAR, empname, 20, NULL);
		while (SQLFetch(hStmt) != SQL_NO_DATA) {
			Senario3_Combo2.AddString((LPCTSTR)empname);
		}
		SQLCloseCursor(hStmt);
		SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
	}
	MyDlg->DBDisconnect();

	MyDlg->DBConnect();
	if (SQLAllocHandle(SQL_HANDLE_STMT, MyDlg->hDbc, &hStmt) == SQL_SUCCESS) {
		SQLCHAR empname[20];
		sprintf((char*)query, ("SELECT LAN_NUM FROM LANGUAGEDATA"));
		SQLExecDirect(hStmt, query, SQL_NTS);
		SQLBindCol(hStmt, 1, SQL_C_CHAR, empname, 20, NULL);
		while (SQLFetch(hStmt) != SQL_NO_DATA) {
			Senario4_Combo1.AddString((LPCTSTR)empname);
		}
		SQLCloseCursor(hStmt);
		SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
	}
	MyDlg->DBDisconnect();
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void DeleteDlg::OnCbnSelchangeCombo2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}




void DeleteDlg::OnCbnSelchangeCombo3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
