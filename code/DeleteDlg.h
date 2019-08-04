#pragma once


// DeleteDlg 대화 상자

class DeleteDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DeleteDlg)

public:
	DeleteDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DeleteDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DELETE };
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
	virtual BOOL OnInitDialog();
	CComboBox Senario1_Combo1;
	CComboBox Senario1_Combo2;
	afx_msg void OnCbnSelchangeCombo2();
	CComboBox Senario2_Combo1;
	afx_msg void OnCbnSelchangeCombo3();
	CComboBox Senario3_Combo1;
	CComboBox Senario3_Combo2;
	CComboBox Senario4_Combo1;
};
