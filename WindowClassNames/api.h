#pragma once
#include <Windows.h>
#include <TlHelp32.h>

#include "status.h"

DWORD get_process_id(const char* pName) {
	HANDLE snapHandle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	if ( snapHandle == INVALID_HANDLE_VALUE ) {
		return STATUS_ERROR_VAR_VALUE;
	}

	PROCESSENTRY32 pEntry = { 0 };
	pEntry.dwSize = sizeof( pEntry );

	if ( Process32First( snapHandle, &pEntry ) ) {
		if ( !strcmp(pEntry.szExeFile,pName) ) {
			return pEntry.th32ProcessID;
		}
	}

	while ( Process32Next( snapHandle, &pEntry ) ) {
		if ( !strcmp( pEntry.szExeFile, pName ) ) {
			return pEntry.th32ProcessID;
		}
	}

	return STATUS_NOT_FOUND;
}

