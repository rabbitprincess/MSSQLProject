#pragma once


// InsertDlg 대화 상자

class InsertDlg : public CDialogEx
{
	DECLARE_DYNAMIC(InsertDlg)

public:
	InsertDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~InsertDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INSERT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox Senario1_combo1;
	CEdit Senario1_edit1;
	CEdit Senario1_edit2;
	CComboBox Senario2_Combo1;
	CComboBox Senario2_Combo2;
	CEdit Senario2_Edit1;
	CEdit Senario2_Edit2;
	CEdit Senario2_Edit3;
	CEdit Senario1_Combo3;
	virtual BOOL OnInitDialog();
	CComboBox Senario3_Combo1;
	CComboBox Senario3_Combo2;
	CComboBox Senario4_Combo1;
	afx_msg void OnCbnSelchangeCombo3();
	CEdit Senario3_Edit1;
	CEdit Senario3_Edit2;
	CEdit Senario4_Edit1;
	CEdit Senario4_Edit2;
	CEdit Senario4_Edit3;
};
