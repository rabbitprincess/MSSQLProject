
// MyDatabaseDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "MyDatabase.h"
#include "MyDatabaseDlg.h"
#include "afxdialogex.h"
#include "SelectDlg.h"
#include "InsertDlg.h"
#include "DeleteDlg.h"
#include "UpdateDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMyDatabaseDlg 대화 상자



CMyDatabaseDlg::CMyDatabaseDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYDATABASE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDatabaseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, CtrlCombo);
	DDX_Control(pDX, IDC_LIST2, m_ListCtrl);
	DDX_Control(pDX, IDC_BUTTON2, Select_Button);
	DDX_Control(pDX, IDC_BUTTON4, Insert_Button);
	DDX_Control(pDX, IDC_BUTTON5, Update_Button);
	DDX_Control(pDX, IDC_BUTTON6, Delete_Button);
}

BEGIN_MESSAGE_MAP(CMyDatabaseDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CMyDatabaseDlg::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDOK, &CMyDatabaseDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyDatabaseDlg::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMyDatabaseDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMyDatabaseDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMyDatabaseDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMyDatabaseDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMyDatabaseDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CMyDatabaseDlg 메시지 처리기

BOOL CMyDatabaseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.



	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMyDatabaseDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMyDatabaseDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMyDatabaseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMyDatabaseDlg::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{

	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	*pResult = 0;
}


void CMyDatabaseDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


void CMyDatabaseDlg::OnBnClickedButton1()
{
	if(DBConnect() == true)
	{
		MessageBox(TEXT("연결되었습니다"));
		DBConnect();
		static SQLCHAR query[100];
		SQLHSTMT hStmt;
		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query,("SELECT TABLE_NAME FROM INFORMATION_SCHEMA.TABLES"));
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLCHAR empname[20];
			SQLBindCol(hStmt, 1, SQL_C_CHAR, empname, 20, NULL);
			int i = 0;
			while (SQLFetch(hStmt) != SQL_NO_DATA) {
				CtrlCombo.AddString((LPCTSTR)empname);
//				MessageBox(Table[i]);
			}
			projectnum = 20;
			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}
		DBDisconnect();
		Select_Button.EnableWindow(TRUE);
		Update_Button.EnableWindow(TRUE);
		Insert_Button.EnableWindow(TRUE);
		Delete_Button.EnableWindow(TRUE);
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMyDatabaseDlg::OnCbnSelchangeCombo1()
{

	CString temp;
	this->CtrlCombo.GetLBText(this->CtrlCombo.GetCurSel(), temp);

	m_ListCtrl.DeleteAllItems();
	for (int i = 0; i < 10; i++) m_ListCtrl.DeleteColumn(0);
	DBConnect();
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

	if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) 
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
			m_ListCtrl.InsertColumn(i, (char*)(ColumnName[i]), LVCFMT_CENTER, 24 + 10 * ColumnNameLen[i]);
		}
		SQLCHAR name[10][200];
		int j = 0;
		int i;
		for (i = 1; i <= numCols; i++) {
			SQLBindCol(hStmt, i, SQL_C_CHAR, name[i], 200, NULL);
		}
		while (SQLFetch(hStmt) != SQL_NO_DATA) {
			m_ListCtrl.InsertItem(j, (char*)name[1]);
			for (i = 1; i <= numCols; i++) {
				m_ListCtrl.SetItemText(j, i, (char*)name[i+1]);
			}
			j++;
		}
		SQLCloseCursor(hStmt);
		SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
	}
	DBDisconnect();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMyDatabaseDlg::OnBnClickedButton2()
{
	SelectDlg m_SelectDlg;
	INT_PTR x = m_SelectDlg.DoModal();
	if (x != IDCANCEL) {
		DBConnect();
		static SQLCHAR query[100];
		SQLHSTMT hStmt;
		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			{
				m_ListCtrl.DeleteAllItems();
				DBConnect();
				static SQLCHAR query[100];
				SQLHSTMT hStmt;
				SQLRETURN retcode;

				SQLCHAR		ColumnName[30][30];
				SQLSMALLINT	ColumnNameLen[30];
				SQLSMALLINT ColumnDataType[30];
				SQLULEN		ColumnDataSize[30];
				SQLSMALLINT	ColumnDataDigits[30];
				SQLSMALLINT	ColumnDataNullable[30];

				SQLSMALLINT numCols = -1;

				if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
					if (x == 0)
					{
						m_ListCtrl.DeleteAllItems();
						for (int i = 0; i < 10; i++) m_ListCtrl.DeleteColumn(0);
						sprintf((char*)query, "SELECT * FROM %s", Table);
						retcode = SQLExecDirect(hStmt, query, SQL_NTS);
						SQLNumResultCols(hStmt, &numCols);
						if (retcode == SQL_ERROR || retcode == SQL_NO_DATA_FOUND) {
							MessageBox(_T("Query Execute Error"));
						}
						else{
							for (int i = 1; i <= numCols; i++)
							{
								SQLDescribeCol(hStmt, i, ColumnName[i], 30, &ColumnNameLen[i], &ColumnDataType[i], &ColumnDataSize[i], &ColumnDataDigits[i], &ColumnDataNullable[i]);
								m_ListCtrl.InsertColumn(i, (char*)(ColumnName[i]), LVCFMT_CENTER, 24 + 10 * ColumnNameLen[i]);
							}
							SQLCHAR name[10][200];
							int j = 0;
							int i;
							for (i = 1; i <= numCols; i++) {
								SQLBindCol(hStmt, i, SQL_C_CHAR, name[i], 200, NULL);
							}
							while (SQLFetch(hStmt) != SQL_NO_DATA) {
								m_ListCtrl.InsertItem(j, (char*)name[1]);
								for (i = 1; i <= numCols; i++) {
									m_ListCtrl.SetItemText(j, i, (char*)name[i + 1]);
								}
								j++;
							}
						}
						SQLCloseCursor(hStmt);
						SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
					}
					if (x == 1)
					{
						m_ListCtrl.DeleteAllItems();
						for(int i=0;i<20;i++) m_ListCtrl.DeleteColumn(0);
						sprintf((char*)query, "SELECT %s FROM %s", Column,Table);
						retcode = SQLExecDirect(hStmt, query, SQL_NTS);
						SQLNumResultCols(hStmt, &numCols);
						if (retcode == SQL_ERROR || retcode == SQL_NO_DATA_FOUND) {
							MessageBox(_T("Query Execute Error"));
						}
						else {
							for (int i = 1; i <= numCols; i++)
							{
								SQLDescribeCol(hStmt, i, ColumnName[i], 30, &ColumnNameLen[i], &ColumnDataType[i], &ColumnDataSize[i], &ColumnDataDigits[i], &ColumnDataNullable[i]);
								m_ListCtrl.InsertColumn(i, (char*)(ColumnName[i]), LVCFMT_CENTER, 24 + 10 * ColumnNameLen[i]);
							}
							SQLCHAR name[10][200];
							int j = 0;
							int i;
							for (i = 1; i <= numCols; i++) {
								SQLBindCol(hStmt, i, SQL_C_CHAR, name[i], 200, NULL);
							}
							while (SQLFetch(hStmt) != SQL_NO_DATA) {
								m_ListCtrl.InsertItem(j, (char*)name[1]);
								for (i = 1; i <= numCols; i++) {
									m_ListCtrl.SetItemText(j, i, (char*)name[i + 1]);
								}
								j++;
							}
						}
						SQLCloseCursor(hStmt);
						SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
					}
					if (x == 3)
					{
						m_ListCtrl.DeleteAllItems();
						for (int i = 0; i < 20; i++) m_ListCtrl.DeleteColumn(0);
						sprintf((char*)query, "SELECT * FROM DATAANALIST AS D, PROJECT AS P WHERE D.ANALIST_NUM = P.ANALIST_NO");
						retcode = SQLExecDirect(hStmt, query, SQL_NTS);
						SQLNumResultCols(hStmt, &numCols);
						if (retcode == SQL_ERROR || retcode == SQL_NO_DATA_FOUND) {
							MessageBox(_T("Query Execute Error"));
						}
						else {
							for (int i = 1; i <= numCols; i++)
							{
								SQLDescribeCol(hStmt, i, ColumnName[i], 30, &ColumnNameLen[i], &ColumnDataType[i], &ColumnDataSize[i], &ColumnDataDigits[i], &ColumnDataNullable[i]);
								m_ListCtrl.InsertColumn(i, (char*)(ColumnName[i]), LVCFMT_CENTER, 24 + 10 * ColumnNameLen[i]);
							}
							SQLCHAR name[10][200];
							int j = 0;
							int i;
							for (i = 1; i <= numCols; i++) {
								SQLBindCol(hStmt, i, SQL_C_CHAR, name[i], 200, NULL);
							}
							while (SQLFetch(hStmt) != SQL_NO_DATA) {
								m_ListCtrl.InsertItem(j, (char*)name[1]);
								for (i = 1; i <= numCols; i++) {
									m_ListCtrl.SetItemText(j, i, (char*)name[i + 1]);
								}
								j++;
							}
						}
						SQLCloseCursor(hStmt);
						SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
					}
					if (x == 4)
					{
						m_ListCtrl.DeleteAllItems();
						for (int i = 0; i < 20; i++) m_ListCtrl.DeleteColumn(0);
						sprintf((char*)query, " SELECT * FROM LANGUAGEDATA AS L, DATAMINER AS M, DATAMANAGER AS R WHERE L.MANAGER_NO = R.MANAGER_NUM AND L.MINER_NO = M.MIN_NUM");
						retcode = SQLExecDirect(hStmt, query, SQL_NTS);
						SQLNumResultCols(hStmt, &numCols);
						if (retcode == SQL_ERROR || retcode == SQL_NO_DATA_FOUND) {
							MessageBox(_T("Query Execute Error"));
						}
						else {
							for (int i = 1; i <= numCols; i++)
							{
								SQLDescribeCol(hStmt, i, ColumnName[i], 30, &ColumnNameLen[i], &ColumnDataType[i], &ColumnDataSize[i], &ColumnDataDigits[i], &ColumnDataNullable[i]);
								m_ListCtrl.InsertColumn(i, (char*)(ColumnName[i]), LVCFMT_CENTER, 24 + 10 * ColumnNameLen[i]);
							}
							SQLCHAR name[10][200];
							int j = 0;
							int i;
							for (i = 1; i <= numCols; i++) {
								SQLBindCol(hStmt, i, SQL_C_CHAR, name[i], 200, NULL);
							}
							while (SQLFetch(hStmt) != SQL_NO_DATA) {
								m_ListCtrl.InsertItem(j, (char*)name[1]);
								for (i = 1; i <= numCols; i++) {
									m_ListCtrl.SetItemText(j, i, (char*)name[i + 1]);
								}
								j++;
							}
						}
						SQLCloseCursor(hStmt);
						SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
					}
					if (x == 5)
					{
						m_ListCtrl.DeleteAllItems();
						for (int i = 0; i < 20; i++) m_ListCtrl.DeleteColumn(0);
						sprintf((char*)query, "SELECT * FROM DATAANALIST AS A, CLIENT AS C, OFFER AS O, REQUEST AS R WHERE R.CLIENT_NO = C.CLIENT_NUM AND R.ANALIST_NO = A.ANALIST_NUM AND O.ANALIST_NO = A.ANALIST_NUM AND O.CLIENT_NO = C.CLIENT_NUM;");
						retcode = SQLExecDirect(hStmt, query, SQL_NTS);
						SQLNumResultCols(hStmt, &numCols);
						if (retcode == SQL_ERROR || retcode == SQL_NO_DATA_FOUND) {
							MessageBox(_T("Query Execute Error"));
						}
						else {
							for (int i = 1; i <= numCols; i++)
							{
								SQLDescribeCol(hStmt, i, ColumnName[i], 30, &ColumnNameLen[i], &ColumnDataType[i], &ColumnDataSize[i], &ColumnDataDigits[i], &ColumnDataNullable[i]);
								m_ListCtrl.InsertColumn(i, (char*)(ColumnName[i]), LVCFMT_CENTER, 24 + 10 * ColumnNameLen[i]);
							}
							SQLCHAR name[10][200];
							int j = 0;
							int i;
							for (i = 1; i <= numCols; i++) {
								SQLBindCol(hStmt, i, SQL_C_CHAR, name[i], 200, NULL);
							}
							while (SQLFetch(hStmt) != SQL_NO_DATA) {
								m_ListCtrl.InsertItem(j, (char*)name[1]);
								for (i = 1; i <= numCols; i++) {
									m_ListCtrl.SetItemText(j, i, (char*)name[i + 1]);
								}
								j++;
							}
						}
						SQLCloseCursor(hStmt);
						SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
					}
					if (x == 6)
					{
						m_ListCtrl.DeleteAllItems();
						for (int i = 0; i < 20; i++) m_ListCtrl.DeleteColumn(0);
						sprintf((char*)query, "SELECT * FROM LANGUAGEDATA WHERE MANAGER_NO = %s", Table);
						retcode = SQLExecDirect(hStmt, query, SQL_NTS);
						SQLNumResultCols(hStmt, &numCols);
						if (retcode == SQL_ERROR || retcode == SQL_NO_DATA_FOUND) {
							MessageBox(_T("Query Execute Error"));
						}
						else {
							for (int i = 1; i <= numCols; i++)
							{
								SQLDescribeCol(hStmt, i, ColumnName[i], 30, &ColumnNameLen[i], &ColumnDataType[i], &ColumnDataSize[i], &ColumnDataDigits[i], &ColumnDataNullable[i]);
								m_ListCtrl.InsertColumn(i, (char*)(ColumnName[i]), LVCFMT_CENTER, 24 + 10 * ColumnNameLen[i]);
							}
							SQLCHAR name[10][200];
							int j = 0;
							int i;
							for (i = 1; i <= numCols; i++) {
								SQLBindCol(hStmt, i, SQL_C_CHAR, name[i], 200, NULL);
							}
							while (SQLFetch(hStmt) != SQL_NO_DATA) {
								m_ListCtrl.InsertItem(j, (char*)name[1]);
								for (i = 1; i <= numCols; i++) {
									m_ListCtrl.SetItemText(j, i, (char*)name[i + 1]);
								}
								j++;
							}
						}
						SQLCloseCursor(hStmt);
						SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
					}
					DBDisconnect();
				}
				else MessageBox(TEXT("FAIL to Connect"));
			}
		}
	}
}

void CMyDatabaseDlg::OnBnClickedButton4()
{
	InsertDlg m_InsertDlg;
	INT_PTR x = m_InsertDlg.DoModal();
	if (x != IDCANCEL) {
		DBConnect();
		static SQLCHAR query[100];
		SQLHSTMT hStmt;
		SQLRETURN retcode;
		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			{
				DBConnect();
				static SQLCHAR query[100];
				SQLHSTMT hStmt;
				if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
					if (x == 0)
					{
						m_ListCtrl.DeleteAllItems();
						for (int i = 0; i < 10; i++) m_ListCtrl.DeleteColumn(0);

						sprintf((char*)query, "INSERT INTO PROJECT VALUES(%s,%s,'%s',%s)",Analist,str3,str1,str2);
						SQLExecDirect(hStmt, query, SQL_NTS);
						SQLCloseCursor(hStmt);
						SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
						MessageBox(TEXT("성공적으로 추가되었습니다."));
					}
					if (x == 1)
					{
						m_ListCtrl.DeleteAllItems();
						for (int i = 0; i < 10; i++) m_ListCtrl.DeleteColumn(0);
						sprintf((char*)query, "INSERT INTO REQUEST VALUES(%s,%s,%s,%s,'%s')", Analist, Client, str1, str2,str3);
						retcode = SQLExecDirect(hStmt, query, SQL_NTS);
						SQLCloseCursor(hStmt);
						SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
						if (retcode == SQL_ERROR) MessageBox(TEXT("이미 존재하는 대상을 추가하였습니다. 다시 시도하세요."));
						else MessageBox(TEXT("성공적으로 추가되었습니다."));
					}
					if (x == 3)
					{
						m_ListCtrl.DeleteAllItems();
						for (int i = 0; i < 10; i++) m_ListCtrl.DeleteColumn(0);
						sprintf((char*)query, "INSERT INTO OFFER VALUES(%s,%s,'%s','%s')", Analist, Client, str1, str2);
						retcode = SQLExecDirect(hStmt, query, SQL_NTS);
						SQLCloseCursor(hStmt);
						SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
						if (retcode == SQL_ERROR) MessageBox(TEXT("이미 존재하는 대상을 추가하였습니다. 다시 시도하세요."));
						else MessageBox(TEXT("성공적으로 추가되었습니다."));
					}
					if (x == 4)
					{
						m_ListCtrl.DeleteAllItems();
						for (int i = 0; i < 10; i++) m_ListCtrl.DeleteColumn(0);
						m_ListCtrl.DeleteAllItems();
						for (int i = 0; i < 10; i++) m_ListCtrl.DeleteColumn(0);
						sprintf((char*)query, "INSERT INTO CLIENT VALUES(%s,'%s','%s','%s')", str1, str2, str3, Analist);
						retcode = SQLExecDirect(hStmt, query, SQL_NTS);
						SQLCloseCursor(hStmt);
						SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
						if (retcode == SQL_ERROR) MessageBox(TEXT("올바르지 않은 대상을 추가하였습니다."));
						else MessageBox(TEXT("성공적으로 추가되었습니다."));
					}
					DBDisconnect();
				}
				else MessageBox(TEXT("FAIL to Connect"));
			}
		}
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMyDatabaseDlg::OnBnClickedButton5()
{
	UpdateDlg m_UpdateDlg;
	INT_PTR x = m_UpdateDlg.DoModal();
	if (x != IDCANCEL) {
		DBConnect();
		static SQLCHAR query[100];
		SQLHSTMT hStmt;
		SQLRETURN retcode;
		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			{
				DBConnect();
				static SQLCHAR query[100];
				SQLHSTMT hStmt;
				if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
					if (x == 0)
					{
						m_ListCtrl.DeleteAllItems();
						for (int i = 0; i < 10; i++) m_ListCtrl.DeleteColumn(0);

						if (_ttoi(str1) == _ttoi(str2)) {
							MessageBox("같은 문장의 관련율은 100%에서 변경할 수 없습니다.");
						}
						else {
							if (_ttoi(str1) < _ttoi(str2)) {
								CString tmp = str2;
								str2 = str1;
								str1 = tmp;
							}
							sprintf((char*)query, "UPDATE SIMILARITY SET LAN1 = %s, LAN2 = %s, RELATION_RATE = %s WHERE LAN1 = %s AND LAN2 = %s", str1, str2, str3, str1, str2);
							SQLExecDirect(hStmt, query, SQL_NTS);
							SQLCloseCursor(hStmt);
							SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
							MessageBox(TEXT("성공적으로 변경되었습니다"));
						}
					}
					if (x == 1)
					{
						m_ListCtrl.DeleteAllItems();
						for (int i = 0; i < 10; i++) m_ListCtrl.DeleteColumn(0);
						sprintf((char*)query, "UPDATE LANGUAGEDATA SET MANAGER_NO = %s WHERE LAN_NUM = %s", str2, str1);
						SQLExecDirect(hStmt, query, SQL_NTS);
						SQLCloseCursor(hStmt);
						SQLFreeHandle(SQL_HANDLE_STMT, hStmt);		
						MessageBox(TEXT("성공적으로 변경되었습니다."));
					}
					if (x == 3)
					{
						m_ListCtrl.DeleteAllItems();
						for (int i = 0; i < 10; i++) m_ListCtrl.DeleteColumn(0);
						sprintf((char*)query, "UPDATE CLIENT SET RATE = '%s' WHERE CLIENT_NUM = %s;", str1, Client);
						retcode = SQLExecDirect(hStmt, query, SQL_NTS);
						SQLCloseCursor(hStmt);
						SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
						if (retcode == SQL_ERROR || retcode == SQL_NO_DATA_FOUND) MessageBox(TEXT("올바르지 않은 대상을 추가하였습니다."));
						else MessageBox(TEXT("성공적으로 추가되었습니다."));
					}
					if (x == 4)
					{
						m_ListCtrl.DeleteAllItems();
						for (int i = 0; i < 10; i++) m_ListCtrl.DeleteColumn(0);
						
						retcode = sprintf((char*)query, "UPDATE PROJECT SET BUDGET = %s WHERE PROJECT_NUM = %s",str1,Analist);
						SQLExecDirect(hStmt, query, SQL_NTS);
						SQLCloseCursor(hStmt);
						SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
						MessageBox(TEXT("성공적으로 변경되었습니다."));
					}
					DBDisconnect();
				}
				else MessageBox(TEXT("FAIL to Connect"));
			}
		}
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMyDatabaseDlg::OnBnClickedButton6()
{
	DeleteDlg m_DeleteDlg;
	INT_PTR x = m_DeleteDlg.DoModal();
	if (x != IDCANCEL) {
		DBConnect();
		static SQLCHAR query[100];
		SQLHSTMT hStmt;
		SQLRETURN retcode;
		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			{
				if (x == 0)
				{
					m_ListCtrl.DeleteAllItems();
					for (int i = 0; i < 10; i++) m_ListCtrl.DeleteColumn(0);
					sprintf((char*)query, "DELETE FROM OFFER WHERE CLIENT_NO = %s\nDELETE FROM REQUEST WHERE CLIENT_NO = %s", Table, Table);
					retcode = SQLExecDirect(hStmt, query, SQL_NTS);
//					sprintf((char*)query, "", Table);
//					retcode = SQLExecDirect(hStmt, query, SQL_NTS);
					SQLCloseCursor(hStmt);
					SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
					retcode = SQLExecDirect(hStmt, query, SQL_NTS);
					if (retcode == SQL_ERROR || retcode == SQL_NO_DATA_FOUND) {
						MessageBox(_T("삭제할 대상이 존재하지 않습니다."));
					}
					else MessageBox(TEXT("삭제가 완료되었습니다."));
				}
				if (x == 1)
				{
					m_ListCtrl.DeleteAllItems();
					for (int i = 0; i < 10; i++) m_ListCtrl.DeleteColumn(0);
					sprintf((char*)query, "DELETE FROM DATAUSES WHERE PROJECT_NO = %s", Table);
					SQLExecDirect(hStmt, query, SQL_NTS);
					sprintf((char*)query, "DELETE FROM PROJECT WHERE PROJECT_NUM = %s", Table);
					retcode = SQLExecDirect(hStmt, query, SQL_NTS);
					SQLCloseCursor(hStmt);
					SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
					if (retcode == SQL_ERROR || retcode == SQL_NO_DATA_FOUND) {
						MessageBox(_T("삭제할 대상이 존재하지 않습니다."));
					}
					else MessageBox(TEXT("삭제가 완료되었습니다."));
				}
				if (x == 3)
				{
					m_ListCtrl.DeleteAllItems();
					for (int i = 0; i < 10; i++) m_ListCtrl.DeleteColumn(0);
					sprintf((char*)query, "DELETE FROM DATAUSES WHERE PROJECT_NO = %s AND LANGUAGE_NO = %s", str1,str2);
					retcode = SQLExecDirect(hStmt, query, SQL_NTS);
					SQLCloseCursor(hStmt);
					SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
					if (retcode == SQL_ERROR || retcode == SQL_NO_DATA_FOUND) {
						MessageBox(_T("삭제할 대상이 존재하지 않습니다."));
					}
					else MessageBox(TEXT("삭제가 완료되었습니다."));
				}
				if (x == 4)
				{
					m_ListCtrl.DeleteAllItems();
					for (int i = 0; i < 10; i++) m_ListCtrl.DeleteColumn(0);
					m_ListCtrl.DeleteAllItems();
					for (int i = 0; i < 10; i++) m_ListCtrl.DeleteColumn(0);
					sprintf((char*)query, "CREATE TABLE TMP(NUM INTEGER NOT NULL);\nINSERT TMP SELECT CLIENT_NO FROM REQUEST WHERE ANALIST_NO = %s;\nDELETE FROM REQUEST WHERE ANALIST_NO = %s;\nDELETE FROM OFFER WHERE ANALIST_NO = 5;\nDELETE FROM CLIENT WHERE CLIENT_NUM IN(SELECT NUM FROM TMP);\nDROP TABLE TMP; ", Table, Table);
					retcode = SQLExecDirect(hStmt, query, SQL_NTS);
					SQLCloseCursor(hStmt);
					SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
					if (retcode == SQL_ERROR || retcode == SQL_NO_DATA_FOUND) {
						MessageBox(_T("삭제할 대상이 존재하지 않습니다."));
					}
					else MessageBox(TEXT("삭제가 완료되었습니다."));
				}
				DBDisconnect();
			}
		}
		else MessageBox(TEXT("FAIL to Connect"));
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

bool CMyDatabaseDlg::DBConnect()
{
	SQLRETURN Ret;
	// Allocate the Environment Handle (hEnv)
	if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv) != SQL_SUCCESS)
	{
		return false;
	}
	// Set attributes of the Environment Handle (hEnv)
	if (SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER) != SQL_SUCCESS)
	{
		return false;
	}
	// Allocate the Connection Handle (hDbc)
	if (SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc) != SQL_SUCCESS)
	{
		return false;
	}
	// Connect to the SQL Sever with ODBC name, ID, and PW
	Ret = SQLConnect(hDbc, (SQLCHAR *)"DB01_Server", SQL_NTS, (SQLCHAR *)"sa", SQL_NTS, (SQLCHAR *)"1234", SQL_NTS);
	if ((Ret != SQL_SUCCESS) && (Ret != SQL_SUCCESS_WITH_INFO))
	{
		MessageBox(_T("연결 불가. 서버 이름 또는 아이디와 비밀번호를 확인하세요."));
		return false;
	}
	return true;
}

void CMyDatabaseDlg::DBDisconnect()
{
	SQLDisconnect(hDbc);// Disconnect from the SQL Server
	SQLFreeHandle(SQL_HANDLE_DBC, hDbc);// Free the Connection Handle
	SQLFreeHandle(SQL_HANDLE_ENV, hEnv);// Free the Environment Handle
}


