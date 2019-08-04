#pragma once


// SelectDlg 대화 상자

class SelectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectDlg)

public:
	SelectDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~SelectDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SELECT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox Senario1_Combo1;
	afx_msg void OnCbnSelchangeCombo2();
	CComboBox Senario1_Combo2;
	CComboBox Senario2_Combo2;
//	virtual HRESULT accDoDefaultAction(VARIANT varChild);
	virtual BOOL OnInitDialog();
	CComboBox Senario6_Combo1;
};
