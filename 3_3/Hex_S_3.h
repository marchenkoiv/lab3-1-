#ifndef _Hex_S_3_H_
#define _Hex_S_3_H_
#include <iostream>

namespace Prog3_3
{
	class Hex
	{
	private:
		static const int quota = 8;
		unsigned int SZ;
		char *ar;
	public:
		Hex() : SZ(8) { ar = new char[8]; for (int i = 0; i < SZ; i++) ar[i] = 0; }
		Hex(std::string a);
		Hex(char a[]);
		Hex(Hex &&);
		Hex(const Hex &);
		~Hex() { delete[] ar; }
		Hex &operator =(const Hex &);
		Hex &operator =(Hex &&);
		char getar(int i) const { return ar[i]; }
		Hex& operator << (int);
		Hex& operator >>(int);
		Hex& invert();
		friend  Hex operator +(const Hex& s, const Hex& s1);
		Hex& operator += (const Hex&);
		Hex& operator -=(const Hex&);
		bool multoftwo();
		bool operator ==(const Hex&);
		bool operator !=(const Hex&);
		bool operator >(const Hex&);
		bool operator <(const Hex&);
		bool operator >=(const Hex&);
		bool operator <=(const Hex&);
		friend int expansion(Hex&, Hex&);
		friend std::ostream & operator << (std::ostream&, const Hex &);
		friend std::istream & operator >> (std::istream&, Hex &);
	};
}
#endif
