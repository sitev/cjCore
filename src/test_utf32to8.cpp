#include <string>
#include <vector>
#include <iostream>


using namespace std;


int main(int argc, _TCHAR* argv[])
{
	vector<int> u32 = { 1055, 1088, 1080, 1074, 1077, 1090, 44, 32, 1084, 1080, 1088, 33 };
	string s = "";
	for (auto i = 0; i < u32.size(); i++) {

		int v = u32[i];
		cout << v << " " << endl;

		if (v <= 0x7f) {
			s += (char)(v & 0x7f);
		}
		else if (v <= 0x7ff) {
			int a = 0x80 + (v & 0x3f);
			int b = 0xc0 + ((v & 0x7c0) >> 6);
			s += (char)b;
			s += (char)a;
		}
		else if (v <= 0xffff) {
			int a = 0x80 + (v & 0x3f);
			int b = 0x80 + ((v & 0x0fc0) >> 6);
			int c = 0xe0 + ((v & 0xf000) >> 12);
			s += (char)c;
			s += (char)b;
			s += (char)a;
		}
		else if (v <= 0x1fffff) {
			int a = 0x80 + (v & 0x3f);
			int b = 0x80 + ((v & 0x0fc0) >> 6);
			int c = 0x80 + ((v & 0x3f000) >> 12);
			int d = 0xf0 + ((v & 0x1c0000) >> 18);
			s += (char)d;
			s += (char)c;
			s += (char)b;
			s += (char)a;
		}
		else if (v <= 0x03ffffff) {
			int a = 0x80 + (v & 0x3f);
			int b = 0x80 + ((v & 0x0fc0) >> 6);
			int c = 0x80 + ((v & 0x3f000) >> 12);
			int d = 0x80 + ((v & 0xfc0000) >> 18);
			int e = 0xf8 + (v >> 24);
			s += (char)e;
			s += (char)d;
			s += (char)c;
			s += (char)b;
			s += (char)a;
		}
		else {
			int a = 0x80 + (v & 0x3f);
			int b = 0x80 + ((v & 0x0fc0) >> 6);
			int c = 0x80 + ((v & 0x3f000) >> 12);
			int d = 0x80 + ((v & 0xfc0000) >> 18);
			int e = 0x80 + ((v & 0x3f000000) >> 24);
			int f = 0xfc + (v >> 30);
			s += (char)f;
			s += (char)e;
			s += (char)d;
			s += (char)c;
			s += (char)b;
			s += (char)a;
		}
	}
	cout << s << endl;

	vector<int> u32a;
	int i = 0;
	int len = s.length();
	while (i < len) {
		unsigned char a = s[i];
		if (a <= 0x7f) {
			u32a.push_back(a);
		}
		else {
			i++;
			unsigned char b = s[i];
			int v = ((a & 0x1f) << 6) + (b & 0x3f);
			u32a.push_back(v);
		}
		i++;
	}

	return 0;
}

