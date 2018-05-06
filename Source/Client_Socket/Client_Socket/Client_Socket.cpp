// Client_Socket.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Client_Socket.h"
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
			CSocket client;
			AfxSocketInit(NULL);
			client.Create();
			char name[100];


			if (client.Connect(_T("127.0.0.1"), 1234))
			{
				cout << "============ CHAO MUNG BAN DEN VOI CHIEC NON KY DIEU ============\n";
				char user[100];
				do
				{
					printf("Nhap Username: ");
					gets(name);
					int len = strlen(name);
					name[len] = 0;
					client.Send(name, len + 1, 0);

					client.Receive(user, 100, 0);
					cout << "Sever: " << user << endl;
				} while (strcmp(user, "Username bi trung!") == 0);
				printf("Da ket noi den server!\n");

				client.Close();
			}
			else
				printf("Khong the ket noi den server!");
			getch();
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
