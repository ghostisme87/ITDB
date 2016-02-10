#include "stdafx.h"
#include "Connector.h"

#define MAX 255

CConnector::CConnector()
{
}


CConnector::~CConnector()
{
}

bool CConnector::Connect(CString con_str)
{
	try
	{
		if (!m_cdb.OpenEx(con_str, 0))
		{
			return false;
		}
	}
	catch (CDBException *ex)
	{
		wchar_t message[MAX];
		ex->GetErrorMessage(message, MAX);
		AfxMessageBox(message, MB_ICONERROR | MB_OK);
		return false;
	}
	return true;
}

wchar_t ** CConnector::Request(CString req)
{
	wchar_t **ans = nullptr;
	m_rc = new CRecordset(&m_cdb);
	m_rc->Open(CRecordset::dynamic, req, CRecordset::none);
	ans = new wchar_t*[5];
	int i = 0;
	while (!m_rc->IsEOF())
	{
		CString buff;
		ans[i] = new wchar_t[MAX];
		m_rc->GetFieldValue(L"name", buff);
		StringCchCopy(ans[i], MAX, buff);
		++i;
		m_rc->MoveNext();
	}
	m_rc->Close();
	delete m_rc;
	return ans;
}
