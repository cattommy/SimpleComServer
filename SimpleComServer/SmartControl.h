// SmartControl.h : Declaration of the CSmartControl

#pragma once
#include "resource.h"       // main symbols


#include "SimpleComServer_i.h"
#include <string>
#include <vector>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CSmartControl

class ATL_NO_VTABLE CSmartControl :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSmartControl, &CLSID_SmartControl>,
	public IDispatchImpl<ISmartControl, &IID_ISmartControl, &LIBID_SimpleComServerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CSmartControl()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SMARTCONTROL)


BEGIN_COM_MAP(CSmartControl)
	COM_INTERFACE_ENTRY(ISmartControl)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	virtual HRESULT STDMETHODCALLTYPE GetServices(
		/* [out] */ BSTR *str
		)
	{
		SC_HANDLE hSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ENUMERATE_SERVICE);
		ENUM_SERVICE_STATUS_PROCESS Services[100] = { 0 };
		DWORD dwBytesNeeded = 0;
		DWORD dwServicesReturned = 0;
		DWORD dwResumeHandle = 0;
		BOOL bSuccess = FALSE;
		DWORD dwServicesCount = 0;
		std::wstring resstr;
		std::wstring del(L",");
		do
		{
			bSuccess = EnumServicesStatusEx(hSCManager, SC_ENUM_PROCESS_INFO,
				SERVICE_WIN32, SERVICE_STATE_ALL, LPBYTE(Services),
				sizeof(Services), &dwBytesNeeded, &dwServicesReturned,
				&dwResumeHandle, NULL);
			for (DWORD n = 0; n < dwServicesReturned; n++, dwServicesCount++) {
				std::wstring s(Services[n].lpDisplayName);
				resstr += s;
				resstr += del;
			}
		} while (!bSuccess && (GetLastError() == ERROR_MORE_DATA));
		*str = SysAllocStringLen(resstr.data(), resstr.size());
		CloseServiceHandle(hSCManager);

		return S_OK;
	}

	virtual HRESULT STDMETHODCALLTYPE GetServiceStatus(
		/* [in] */ BSTR *str,
		/* [out] */ DWORD *rstatus
		)
	{
		LPCWSTR result = T2W(*str);
		SC_HANDLE serviceDbHandle = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
		SC_HANDLE serviceHandle = OpenService(serviceDbHandle, result, SC_MANAGER_ALL_ACCESS);
		SERVICE_STATUS_PROCESS status;
		DWORD bytesNeeded;
		QueryServiceStatusEx(serviceHandle, SC_STATUS_PROCESS_INFO, (LPBYTE)&status, sizeof(SERVICE_STATUS_PROCESS), &bytesNeeded);
		*rstatus = status.dwServiceFlags;
		CloseServiceHandle(serviceHandle);
		return S_OK;
	}

	virtual HRESULT STDMETHODCALLTYPE StopMyService(
		/* [in] */ BSTR *str
		)
	{
		
		SC_HANDLE serviceDbHandle = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
		SC_HANDLE serviceHandle = OpenService(serviceDbHandle, *str, SC_MANAGER_ALL_ACCESS);

		SERVICE_STATUS_PROCESS status;
		DWORD bytesNeeded;
		QueryServiceStatusEx(serviceHandle, SC_STATUS_PROCESS_INFO, (LPBYTE)&status, sizeof(SERVICE_STATUS_PROCESS), &bytesNeeded);
		
		if (status.dwCurrentState == SERVICE_RUNNING)
		{
			BOOL b = ControlService(serviceHandle, SERVICE_CONTROL_STOP, (LPSERVICE_STATUS)&status);
			if (b)
			{
				//std::cout << "Service stopped." << std::endl;
				MessageBox(NULL, L"Service stopped.", L"COMServer", MB_OK | MB_SETFOREGROUND);
			}
			else { //std::cout << "Service failed to stop." << std::endl;
				MessageBox(NULL, L"Service failed to stop.", L"COMServer", MB_OK | MB_SETFOREGROUND);
			}

		}
		else {
			{ //std::cout << "Service is already stopped." << std::endl; 
				MessageBox(NULL, L"Service is already stopped.", L"COMServer", MB_OK | MB_SETFOREGROUND);
			}

		}

		CloseServiceHandle(serviceHandle);
		return S_OK;
	}

	virtual HRESULT STDMETHODCALLTYPE StartMyService(
		/* [in] */ BSTR *str
		)
	{
		SC_HANDLE serviceDbHandle = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
		SC_HANDLE serviceHandle = OpenService(serviceDbHandle, *str, SC_MANAGER_ALL_ACCESS);

		SERVICE_STATUS_PROCESS status;
		DWORD bytesNeeded;
		QueryServiceStatusEx(serviceHandle, SC_STATUS_PROCESS_INFO, (LPBYTE)&status, sizeof(SERVICE_STATUS_PROCESS), &bytesNeeded);

		if (status.dwCurrentState == SERVICE_STOPPED)
		{
			BOOL b = StartService(serviceHandle, NULL, NULL);

			if (b)
			{
				//std::cout << "Service is started." << std::endl;
				MessageBox(NULL, L"Service is started.", L"COMServer", MB_OK | MB_SETFOREGROUND);
			}
			else { //std::cout << "Service failed to start." << std::endl; 
				MessageBox(NULL, L"Service failed to start.", L"COMServer", MB_OK | MB_SETFOREGROUND);
			}

			return b;
		}
		else {
			{// std::cout << "Service is already running." << std::endl;
				MessageBox(NULL, L"Service is already running.", L"COMServer", MB_OK | MB_SETFOREGROUND);
			}

			return true;
		}

		CloseServiceHandle(serviceHandle);

		return S_OK;
	}

	STDMETHOD(call)(BSTR c);
};

OBJECT_ENTRY_AUTO(__uuidof(SmartControl), CSmartControl)
