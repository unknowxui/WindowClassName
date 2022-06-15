#include <Windows.h>
#include <stdio.h>

#include "api.h"

char  hasArgs = 0;
DWORD argPid = 0;

BOOL CALLBACK enumWindowCallback( HWND hWnd, LPARAM lparam ) {
	char str[256];
	DWORD outPid = 0;
	int retBytes = GetClassName( hWnd, str, 256 );
	GetWindowThreadProcessId( hWnd, &outPid );
	if ( hasArgs ) {
		if ( argPid == outPid ) {
			printf( "Process id - %i windowName -  %s \n", outPid, str );
			return 0;
		}
	} else {
		printf( "Process id - %i windowName -  %s \n", outPid, str );
	}

	return 1;
}

void main( int argc, char* argv[] ) {
	if ( argc > 1 && argc < 3 ) {
		hasArgs = 1;
		argPid = atoi(argv[1]);
		EnumWindows( enumWindowCallback, NULL );
	} else {
		EnumWindows( enumWindowCallback, NULL );
	}

	system( "pause" );
}