// InsertDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "MyDatabase.h"
#include "InsertDlg.h"
#include "afxdialogex.h"
#include "MyDatabaseDlg.h"

// InsertDlg 대화 상자

IMPLEMENT_DYNAMIC(InsertDlg, CDialogEx)

InsertDlg::InsertDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INSERT, pParent)
{

}

InsertDlg::~InsertDlg()
{
}

void InsertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, Senario1_combo1);
	DDX_Control(pDX, IDC_EDIT1, Senario1_edit1);
	DDX_Control(pDX, IDC_EDIT2, Senario1_edit2);
	DDX_Control(pDX, IDC_COMBO4, Senario2_Combo1);
	DDX_Control(pDX, IDC_COMBO5, Senario2_Combo2);
	DDX_Control(pDX, IDC_EDIT3, Senario2_Edit1);
	DDX_Control(pDX, IDC_EDIT4, Senario2_Edit2);
	DDX_Control(pDX, IDC_EDIT5, Senario2_Edit3);
	DDX_Control(pDX, IDC_EDIT8, Senario1_Combo3);
	DDX_Control(pDX, IDC_COMBO2, Senario3_Combo1);
	DDX_Control(pDX, IDC_COMBO3, Senario3_Combo2);
	DDX_Control(pDX, IDC_COMBO6, Senario4_Combo1);
	DDX_Control(pDX, IDC_EDIT6, Senario3_Edit1);
	DDX_Control(pDX, IDC_EDIT7, Senario3_Edit2);
	DDX_Control(pDX, IDC_EDIT9, Senario4_Edit1);
	DDX_Control(pDX, IDC_EDIT10, Senario4_Edit2);
	DDX_Control(pDX, IDC_EDIT11, Senario4_Edit3);
}


BEGIN_MESSAGE_MAP(InsertDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &InsertDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &InsertDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &InsertDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &InsertDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDCANCEL, &InsertDlg::OnBnClickedCancel)
	ON_CBN_SELCHANGE(IDC_COMBO1, &InsertDlg::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO3, &InsertDlg::OnCbnSelchangeCombo3)
END_MESSAGE_MAP()


// InsertDlg 메시지 처리기


void InsertDlg::OnBnClickedButton1()
{
	CString str = "";
	CMyDatabaseDlg *MyDlg = (CMyDatabaseDlg *)GetParent();
	Senario1_combo1.GetLBText(Senario1_combo1.GetCurSel(), str);
	MyDlg->SetAnalist(str);
	Senario1_edit1.GetWindowTextA(str);
	MyDlg->SetStr1(str);
	Senario1_edit2.GetWindowTextA(str);
	MyDlg->SetStr2(str);
	Senario1_Combo3.GetWindowTextA(str);
	MyDlg->SetStr3(str);
	EndDialog(0);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void InsertDlg::OnBnClickedButton2()
{
	CString str = "";
	CMyDatabaseDlg *MyDlg = (CMyDatabaseDlg *)GetParent();
	Senario2_Combo1.GetLBText(Senario2_Combo1.GetCurSel(), str);
	MyDlg->SetAnalist(str);
	Senario2_Combo2.GetLBText(Senario2_Combo2.GetCurSel(), str);
	MyDlg->SetClient(str);
	Senario2_Edit1.GetWindowTextA(str);
	MyDlg->SetStr1(str);
	Senario2_Edit2.GetWindowTextA(str);
	MyDlg->SetStr2(str);
	Senario2_Edit3.GetWindowTextA(str);
	MyDlg->SetStr3(str);
	EndDialog(1);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void InsertDlg::OnBnClickedButton3()
{
	CString str = "";
	CMyDatabaseDlg *MyDlg = (CMyDatabaseDlg *)GetParent();
	Senario3_Combo1.GetLBText(Senario3_Combo1.GetCurSel(), str);
	MyDlg->SetAnalist(str);
	Senario3_Combo2.GetLBText(Senario3_Combo1.GetCurSel(), str);
	MyDlg->SetClient(str);
	Senario3_Edit1.GetWindowTextA(str);
	MyDlg->SetStr1(str);
	Senario3_Edit2.GetWindowTextA(str);
	MyDlg->SetStr2(str);
	EndDialog(3);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void InsertDlg::OnBnClickedButton4()
{
	CString str = "";
	CMyDatabaseDlg *MyDlg = (CMyDatabaseDlg *)GetParent();
	Senario4_Edit1.GetWindowTextA(str);
	MyDlg->SetStr1(str);
	Senario4_Edit2.GetWindowTextA(str);
	MyDlg->SetStr2(str);
	Senario4_Edit3.GetWindowTextA(str);
	MyDlg->SetStr3(str);
	Senario4_Combo1.GetLBText(Senario4_Combo1.GetCurSel(), str);
	MyDlg->SetAnalist(str);
	EndDialog(4);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void InsertDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


void InsertDlg::OnCbnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


BOOL InsertDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	CMyDatabaseDlg *MyDlg = (CMyDatabaseDlg *)GetParent();
	MyDlg->DBConnect();
	static SQLCHAR query[100];
	SQLHSTMT hStmt;
	if (SQLAllocHandle(SQL_HANDLE_STMT, MyDlg->hDbc, &hStmt) == SQL_SUCCESS) {
		SQLCHAR empname[20];
		sprintf((char*)query, ("SELECT ANALIST_NUM FROM DATAANALIST"));
		SQLExecDirect(hStmt, query, SQL_NTS);
		SQLBindCol(hStmt, 1, SQL_C_CHAR, empname, 20, NULL);
		while (SQLFetch(hStmt) != SQL_NO_DATA) {
			Senario1_combo1.AddString((LPCTSTR)empname);
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
		sprintf((char*)query, ("SELECT CLIENT_NUM FROM CLIENT"));
		SQLExecDirect(hStmt, query, SQL_NTS);
		SQLBindCol(hStmt, 1, SQL_C_CHAR, empname, 20, NULL);
		while (SQLFetch(hStmt) != SQL_NO_DATA) {
			Senario2_Combo2.AddString((LPCTSTR)empname);
			Senario3_Combo2.AddString((LPCTSTR)empname);
		}
		SQLCloseCursor(hStmt);
		SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
	}
	MyDlg->DBDisconnect();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void InsertDlg::OnCbnSelchangeCombo3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
