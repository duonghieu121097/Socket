// Server_Socket.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Server_Socket.h"
#include <string>
#include "afxsock.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// initialize MFC and print and error on failure
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: change error code to suit your needs
			_tprintf(_T("Fatal Error: MFC initialization failed\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: code your application's behavior here.
			// TODO: code your application's behavior here.
			//Khai bao cac bien socket
			CSocket server;
			CSocket ArrClient[10];


			//Khoi tao 
			AfxSocketInit(NULL);
			server.Create(1234);
			server.Listen(10);

			printf("\nDang lang nghe ket noi tu client...");

			//Chap nhan ket noi
			char** name_Client;
			name_Client = new char*[8];
			for (int i = 0; i < 8; i++)
			{
				server.Accept(ArrClient[i]);
				char name[100];
				int temp = 0;

				ArrClient[i].Receive(name, 100, 0);
				for (int j = 0; j < i; j++)
				{
				if (!strcmp(name_Client[j], name))
					temp++;
				}
				if (temp != 0)
				{
					int len = strlen("Username bi trung!");
					ArrClient[i].Send("Username bi trung!", len + 1, 0);
				}
	
				int len = strlen("Username hop le!");
				ArrClient[i].Send("Username hop le!", len + 1, 0);
				name_Client[i] = new char[100];
				strcpy(name_Client[i], name);
				printf("\n %s vua ket noi", name);
			 }
			//Dong tat ca client
			for (int j = 0; j < 10; j++)
				ArrClient[j].Close();
			//Dong server
			server.Close();
		}
	}
	else
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: GetModuleHandle failed\n"));
		nRetCode = 1;
	}

	return nRetCode;
}

