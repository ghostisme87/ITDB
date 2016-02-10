#pragma once

class CConnector
{
protected:
	CDatabase m_cdb;
	CRecordset *m_rc;
public:
	CConnector();
	~CConnector();

	bool Connect(CString con_str);
	wchar_t ** Request(CString req);
};

