/**
* This program creates a separate process using the CreateProcess() system call.
*
* Figure 3.12
*
* @author Gagne, Galvin, Silberschatz
* Operating System Concepts  - Eighth Edition
* Copyright John Wiley & Sons - 2008.
*/

#include <windows.h>
#include <stdio.h>
#include <tchar.h>//추가
int main(VOID)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	TCHAR Command[] = _T("C:\\WINDOWS\\system32\\mspaint.exe"); // 이렇게 수정 해야되네

	// Start the child process.
	if (!CreateProcess(NULL,   // No module name (use command line).
		Command, // Command line.
		NULL,             // Process handle not inheritable.
		NULL,             // Thread handle not inheritable.
		FALSE,            // Set handle inheritance to FALSE.
		0,                // No creation flags.
		NULL,             // Use parent's environment block.
		NULL,             // Use parent's starting directory.
		&si,              // Pointer to STARTUPINFO structure.
		&pi)             // Pointer to PROCESS_INFORMATION structure.
		)
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
		return -1;
	}

	// Wait until child process exits.
	WaitForSingleObject(pi.hProcess, INFINITE);

	// Close process and thread handles.
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}

