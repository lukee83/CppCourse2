// Dll3.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

extern "C" {

	__declspec(dllexport) double dll_adder(double a, double b) {
		return a + b;
	}

}
