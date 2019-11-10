#ifndef _Hex_S_2_H_
#define _Hex_S_2_H_
#include <iostream>

namespace Prog3_2
{
	class Hex
	{
	private:
		static const int SZ = 8;
		char ar[SZ];
	public:
		Hex() : ar{ 0 } {}
		Hex(std::string a);
		Hex(char a[]);
		char getar(int i) const { return ar[i]; }
		Hex& operator << (int);
		Hex& operator >>(int);
		Hex& invert();
		Hex& operator += (Hex);
		Hex& operator -=(Hex);
		bool multoftwo();
		bool operator ==(Hex);
		bool operator !=(Hex);
		bool operator >(Hex);
		bool operator <(Hex);
		bool operator >=(Hex);
		bool operator <=(Hex);
		friend std::ostream & operator << (std::ostream&, const Hex &);
		friend std::istream & operator >> (std::istream&, Hex &);
	};
}
#endif
