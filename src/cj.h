﻿#pragma once


#ifdef __linux__
#define OS_LINUX
#define cfg_WebApp
#else
#define OS_WINDOWS
#define cfg_WebApp
#endif

//#define M_PI 3.14159


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#ifdef OS_LINUX
#include <sys/io.h>
#endif

#ifdef OS_WINDOWS
#include <io.h>
#endif

#include <iostream>
#include <fstream>
#include <map>
#include <mutex>

#ifdef OS_LINUX
#include <sys/resource.h>
#endif

#ifdef OS_LINUX
#include <dirent.h>
#endif

#ifdef WIN32
#define _WIN32_WINNT 0x0501
#include <stdio.h>
#endif

#ifdef OS_WINDOWS
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#endif

#ifdef OS_LINUX
#include <uuid/uuid.h>
//	#include <gd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#endif

#include <string>
#include <thread>

using namespace std;

#ifdef OS_WINDOWS
#include <codecvt>

typedef std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> Convert16;
typedef std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> Convert32;

#include <iomanip>
#include <ctime>
#endif

#ifdef OS_LINUX
#include <uchar.h>
typedef basic_string<char32_t> u32string;
#include <boost/locale.hpp>
#endif

#include "types.h"
#include "object.h"
#include "stream.h"
#include "logger.h"
#include "socket.h"

#include "application.h"


