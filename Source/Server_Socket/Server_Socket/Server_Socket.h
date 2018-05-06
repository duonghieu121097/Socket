#pragma once

#include "resource.h"
#include "afxsock.h"

void LoadFile(char* File, char** &temp, int& n);
void receive_str(char* str, CSocket *Client, int i);
void send_str(char* str, CSocket* Client, int i);
void send_len(char* str, CSocket* Client, int i);