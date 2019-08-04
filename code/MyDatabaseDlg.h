
// MyDatabaseDlg.h: 헤더 파일
//

#pragma once


// CMyDatabaseDlg 대화 상자
class CMyDatabaseDlg : public CDialogEx
{
// 생성입니다.
public:
	CMyDatabaseDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYDATABASE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	SQLHENV hEnv = NULL;
	SQLHDBC hDbc = NULL;

	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox CtrlCombo;
	CListCtrl m_ListCtrl;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	bool DBConnect();
	void DBDisconnect();
	CString Table;
	void SetTable(CString str) { this->Table = str; }
	CString Column;
	void SetColumn(CString str) { this->Column  = str; }
	CString Analist;
	void SetAnalist(CString x) { this->Analist = x; }
	CString str1;
	void SetStr1(CString str) { this->str1 = str; }
	CString str2;
	void SetStr2(CString str) { this->str2 = str; }
	CString str3;
	void SetStr3(CString str) { this->str3 = str; }
	int projectnum = 20;
	CString Client;
	void SetClient(CString str) { this->Client = str; }
	
	CButton Select_Button;
	CButton Insert_Button;
	CButton Update_Button;
	CButton Delete_Button;
};
