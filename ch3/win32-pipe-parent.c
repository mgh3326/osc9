/**
* Simple program demonstrating Win32 anonymous pipes.
*
* Figures 3.27 & 3.28
*
* @author Silberschatz, Gagne and Galvin.
* Operating System Concepts  - Ninth Edition
* Copyright John Wiley & Sons - 2013
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <tchar.h>//추가
#define BUFFER_SIZE 25

int main(VOID)
{
	HANDLE read_handle, write_handle;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	char message[BUFFER_SIZE] = "Greetings";
	DWORD written;

	/* set up security attributes so that pipe handles are inherited */
	SECURITY_ATTRIBUTES sa = { sizeof(SECURITY_ATTRIBUTES), NULL,TRUE };

	/* allocate memory */
	ZeroMemory(&pi, sizeof(pi));

	/* create the pipe */
	if (!CreatePipe(&read_handle, &write_handle, &sa, 0)) {
		fprintf(stderr, "Create Pipe Failed\n");
		return 1;
	}

	/* establish the START_INFO structure for the child process */
	GetStartupInfo(&si);
	si.hStdError = GetStdHandle(STD_ERROR_HANDLE);
	si.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	/* redirect the standard input to the read end of the pipe */
	si.hStdInput = read_handle;
	si.dwFlags = STARTF_USESTDHANDLES;

	/* we do not want the child to inherit the write end of the pipe */
	SetHandleInformation(write_handle, HANDLE_FLAG_INHERIT, 0);
	TCHAR command[] = _T(".\\child.exe"); // 이렇게 수정 해야되네
	/* create the child process */
	if (!CreateProcess(NULL,
		command,
		NULL,
		NULL,
		TRUE, /* inherit handles */
		0,
		NULL,
		NULL,
		&si,
		&pi))
	{
		fprintf(stderr, "Process Creation Failed\n");
		return -1;
	}

	/* close the unused end of the pipe */
	CloseHandle(read_handle);

	/* the parent now wants to write to the pipe */
	if (!WriteFile(write_handle, message, BUFFER_SIZE, &written, NULL))
		fprintf(stderr, "Error writing to pipe\n");

	/* close the write end of the pipe */
	CloseHandle(write_handle);

	/* wait for the child to exit */
	WaitForSingleObject(pi.hProcess, INFINITE);

	/* close all handles */
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}
