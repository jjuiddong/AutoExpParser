// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include <stdio.h>
#include <tchar.h>

// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
#include <windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>




#ifndef SAFE_DELETE
#define SAFE_DELETE(p) {if (p) { delete p; p=NULL;} }
#endif
#ifndef SAFE_DELETEA
#define SAFE_DELETEA(p) {if (p) { delete[] p; p=NULL;} }
#endif
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p) {if (p) { p->Release(); p=NULL;} }
#endif

#define RET(exp)		{if((exp)) return; }			// exp�� true�̸� ����
#define RETV(exp,val)	{if((exp)) return val; }
#define ASSERT_RET(exp)		{assert(exp); RET(!(exp) ); }
#define ASSERT_RETV(exp,val)		{assert(exp); RETV(!(exp),val ); }
