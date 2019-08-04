#pragma once


// UpdateDlg 대화 상자

class UpdateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(UpdateDlg)

public:
	UpdateDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~UpdateDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UPDATE };
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
	CComboBox Senario1_Combo1;
	CComboBox Senario1_Combo2;
	CEdit Senario1_Edit1;
	virtual BOOL OnInitDialog();
	CComboBox Senario2_Combo1;
	CComboBox Senario2_Combo2;
	CComboBox Senario3Combo1;
	CEdit Senario4Edit1;
	CComboBox Senario3_Combo1;
	CComboBox Senario4_Combo1;
};
