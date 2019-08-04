#include "stdafx.h"
#include "ODBC.h"





ODBC::ODBC()
{
}


ODBC::~ODBC()
{
}



bool DBConnect() {
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
	Ret = SQLConnect(hDbc, (SQLCHAR *)"", SQL_NTS, (SQLCHAR *)"", SQL_NTS, (SQLCHAR *)"", SQL_NTS);
	if ((Ret != SQL_SUCCESS) && (Ret != SQL_SUCCESS_WITH_INFO))
	{
		return false;
	}
	return true;
}

void DBDisconnect()
{
	SQLDisconnect(hDbc);// Disconnect from the SQL Server
	SQLFreeHandle(SQL_HANDLE_DBC, hDbc);// Free the Connection Handle
	SQLFreeHandle(SQL_HANDLE_ENV, hEnv);// Free the Environment Handle
}