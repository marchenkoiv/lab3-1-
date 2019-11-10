#ifndef _Hex_S_1_H_
#define _Hex_S_1_H_
#include <iostream>

namespace Prog3_1
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
		Hex& shiftleft(int);
		Hex& shiftright(int);
		Hex& invert();
		Hex& add(Hex);
		Hex& sub(Hex);
		bool multoftwo();
		bool equal(Hex);
		bool notequal(Hex);
		bool greater(Hex);
		bool less(Hex);
		std::ostream & print(std::ostream&) const;
		std::istream & input(std::istream&);
	};
}
#endif
