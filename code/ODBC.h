#pragma once
#include<stdio.h>
#include<Windows.h>
#include<sql.h>
#include<sqlext.h>

bool DBConnect();
void DBDisconnect();
SQLHENV hEnv = NULL;
SQLHDBC hDbc = NULL;

class ODBC
{
public:


	ODBC();
	~ODBC();
};

