// UpdateDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "MyDatabase.h"
#include "UpdateDlg.h"
#include "afxdialogex.h"
#include "MyDatabaseDlg.h"

// UpdateDlg 대화 상자

IMPLEMENT_DYNAMIC(UpdateDlg, CDialogEx)

UpdateDlg::UpdateDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_UPDATE, pParent)
{

}

UpdateDlg::~UpdateDlg()
{
}

void UpdateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, Senario1_Combo1);
	DDX_Control(pDX, IDC_COMBO4, Senario1_Combo2);
	DDX_Control(pDX, IDC_EDIT1, Senario1_Edit1);
	DDX_Control(pDX, IDC_COMBO2, Senario2_Combo1);
	DDX_Control(pDX, IDC_COMBO3, Senario2_Combo2);
	DDX_Control(pDX, IDC_COMBO5, Senario3Combo1);
	DDX_Control(pDX, IDC_EDIT2, Senario4Edit1);
	DDX_Control(pDX, IDC_COMBO7, Senario3_Combo1);
	DDX_Control(pDX, IDC_COMBO8, Senario4_Combo1);
}


BEGIN_MESSAGE_MAP(UpdateDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &UpdateDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &UpdateDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &UpdateDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &UpdateDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDCANCEL, &UpdateDlg::OnBnClickedCancel)
	ON_CBN_SELCHANGE(IDC_COMBO1, &UpdateDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// UpdateDlg 메시지 처리기


void UpdateDlg::OnBnClickedButton1()
{
	CString str = "";
	CMyDatabaseDlg *MyDlg = (CMyDatabaseDlg *)GetParent();
	Senario1_Combo1.GetLBText(Senario1_Combo1.GetCurSel(), str);
	MyDlg->SetStr1(str);
	Senario1_Combo2.GetLBText(Senario1_Combo2.GetCurSel(), str);
	MyDlg->SetStr2(str);
	Senario1_Edit1.GetWindowTextA(str);
	MyDlg->SetStr3(str);
	EndDialog(0);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void UpdateDlg::OnBnClickedButton2()
{
	CString str = "";
	CMyDatabaseDlg *MyDlg = (CMyDatabaseDlg *)GetParent();
	Senario2_Combo1.GetLBText(Senario2_Combo1.GetCurSel(), str);
	MyDlg->SetStr1(str);
	Senario2_Combo2.GetLBText(Senario2_Combo2.GetCurSel(), str);
	MyDlg->SetStr2(str);
	EndDialog(1);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void UpdateDlg::OnBnClickedButton3()
{
	CString str = "";
	CMyDatabaseDlg *MyDlg = (CMyDatabaseDlg *)GetParent();
	Senario3_Combo1.GetLBText(Senario3_Combo1.GetCurSel(), str);
	MyDlg->SetClient(str);
	Senario3Combo1.GetLBText(Senario3Combo1.GetCurSel(), str);
	MyDlg->SetStr1(str);
	EndDialog(3);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void UpdateDlg::OnBnClickedButton4()
{
	CString str = "";
	CMyDatabaseDlg *MyDlg = (CMyDatabaseDlg *)GetParent();
	Senario4Edit1.GetWindowTextA(str);
	MyDlg->SetStr1(str);
	Senario4_Combo1.GetLBText(Senario4_Combo1.GetCurSel(), str);
	MyDlg->SetAnalist(str);
	EndDialog(4);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void UpdateDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


void UpdateDlg::OnCbnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


BOOL UpdateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CMyDatabaseDlg *MyDlg = (CMyDatabaseDlg *)GetParent();
	MyDlg->DBConnect();
	static SQLCHAR query[100];
	SQLHSTMT hStmt;
	if (SQLAllocHandle(SQL_HANDLE_STMT, MyDlg->hDbc, &hStmt) == SQL_SUCCESS) {
		sprintf((char*)query, ("SELECT LAN_NUM FROM LANGUAGEDATA"));
		SQLExecDirect(hStmt, query, SQL_NTS);
		SQLCHAR empname[20];
		SQLBindCol(hStmt, 1, SQL_C_CHAR, empname, 20, NULL);
		int i = 0;
		while (SQLFetch(hStmt) != SQL_NO_DATA) {
			Senario1_Combo1.AddString((LPCTSTR)empname);
			Senario1_Combo2.AddString((LPCTSTR)empname);
			Senario2_Combo1.AddString((LPCTSTR)empname);
			Senario2_Combo2.AddString((LPCTSTR)empname);
		}
		SQLCloseCursor(hStmt);
		SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
	}
	MyDlg->DBDisconnect();

	MyDlg->DBConnect();
	if (SQLAllocHandle(SQL_HANDLE_STMT, MyDlg->hDbc, &hStmt) == SQL_SUCCESS) {
		sprintf((char*)query, ("SELECT CLIENT_NUM FROM CLIENT"));
		SQLExecDirect(hStmt, query, SQL_NTS);
		SQLCHAR empname[20];
		SQLBindCol(hStmt, 1, SQL_C_CHAR, empname, 20, NULL);
		int i = 0;
		while (SQLFetch(hStmt) != SQL_NO_DATA) {
			Senario3_Combo1.AddString((LPCTSTR)empname);
		}
		SQLCloseCursor(hStmt);
		SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
	}
	MyDlg->DBDisconnect();

	MyDlg->DBConnect();
	if (SQLAllocHandle(SQL_HANDLE_STMT, MyDlg->hDbc, &hStmt) == SQL_SUCCESS) {
		sprintf((char*)query, ("SELECT PROJECT_NUM FROM PROJECT"));
		SQLExecDirect(hStmt, query, SQL_NTS);
		SQLCHAR empname[20];
		SQLBindCol(hStmt, 1, SQL_C_CHAR, empname, 20, NULL);
		int i = 0;
		while (SQLFetch(hStmt) != SQL_NO_DATA) {
			Senario4_Combo1.AddString((LPCTSTR)empname);
		}
		SQLCloseCursor(hStmt);
		SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
	}
	MyDlg->DBDisconnect();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
