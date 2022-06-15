#pragma once
#define STATUS_ERROR_VAR_VALUE 1
#define STATUS_NOT_FOUND       2

__forceinline char status(int vVal) {
	switch ( vVal ) {
		case STATUS_ERROR_VAR_VALUE:
			return 0;
		case STATUS_NOT_FOUND:
			return 0;
	}
	return 1;
}