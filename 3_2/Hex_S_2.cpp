#include "Hex_S_2.h"
#include <string>


namespace Prog3_2
{
	Hex::Hex(char a[])
	{
		for (int i = 0; i < SZ; i++)
		{
			if (a[i] >= '0' && a[i] <= '9')
				ar[i] = a[i] - '0';
			else
				if (a[i] >= 'a' && a[i] <= 'f')
					ar[i] = a[i] - 'a' + 10;
				else
					throw std::exception("invalid number");
		}
	}

	Hex::Hex(std::string a)
	{
		if (a.length() > SZ)
			throw std::exception("too long number");
		for (int i = 0; i < SZ; i++)
			ar[i] = 0;
		int c = 0;

		if (a[0] == '-')
		{
			c++;
			ar[0] = 8;
		}
		int k = SZ - a.length();
		for (int i = a.length() - 1; i >= c; i--)
		{
			if (a[i] >= '0' && a[i] <= '9')
				ar[k + i] = a[i] - '0';
			else
				if (a[i] >= 'a' && a[i] <= 'f')
					ar[k + i] = a[i] - 'a' + 10;
				else
					throw std::exception("invalid number");
		}
	}

	std::ostream & operator << (std::ostream &s, const Hex &st)
	{
		char k;
		for (int i = 0; i < st.SZ; i++)
		{
			if (st.ar[i] > 9)
				k = st.ar[i] + 'a' - 10;
			else
				k = st.ar[i] + '0';
			s << k;
		}
		s << std::endl;
		return s;
	}

	std::istream & operator >>(std::istream &s, Hex &st)
	{
		std::string val;
		std::cin >> val;
		if (std::cin.eof())
			throw std::exception("eof");
		try
		{
			st = val;
		}
		catch (const std::exception &ex)
		{
			std::cout << ex.what() << std::endl;
		}
		return s;
	}

	bool Hex::multoftwo()
	{
		bool j = ar[SZ - 1] % 2;
		return j;
	}

	Hex& Hex::operator <<(int k)
	{
		if (k < 0)
		{
			*this >> (-k);
			return *this;
		}
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < SZ - 1; j++)
			{
				ar[j] = ar[j + 1];
			}
			ar[SZ - 1] = 0;
		}
		return *this;
	}

	Hex& Hex:: operator >>(int k)
	{
		if (k < 0)
		{
			*this << (-k);
			return *this;
		}
		for (int i = 0; i < k; i++)
		{
			for (int j = SZ - 2; j >= 0; j--)
			{
				ar[j + 1] = ar[j];
			}
			ar[i] = 0;
		}
		return *this;
	}
	Hex& Hex:: operator +=(Hex s)
	{
		int c = 0;
		if (ar[0] >= 8)
			(*this).invert();
		if (s.ar[0] >= 8)
			s.invert();
		for (int i = SZ - 1; i >= 0; i--)
		{
			ar[i] = ar[i] + s.ar[i] + c;
			if (ar[i] > 15)
			{
				c = 1;
				ar[i] -= 16;
			}
			else
				c = 0;
		}
		if (ar[0] >= 8)
			(*this).invert();
		return *this;
	}

	Hex& Hex:: operator -=(Hex s)
	{
		int c = 0;
		if (s.ar[0] >= 8)
			s.ar[0] -= 8;
		else
			s.ar[0] += 8;
		(*this) += (s);
		return *this;
	}

	Hex& Hex::invert()
	{
		int c = 0;
		if (ar[0] < 8)
			return *this;
		ar[0] = 15 - ar[0] + 8;
		for (int i = 1; i < SZ; i++)
		{
			ar[i] = 15 - ar[i];
		}
		for (int i = SZ - 1; i >= 0 && c == 0; i--)
		{
			ar[i]++;
			if (ar[i] < 16)
				c++;
		}
		return *this;
	}

	bool Hex::operator ==(Hex op)
	{
		for (int i = 0; i < SZ; i++)
		{
			if (ar[i] != op.ar[i])
				return 0;
		}
		return 1;
	}

	bool Hex::operator !=(Hex op)
	{
		bool j = !((*this) == (op));
		return j;
	}

	bool Hex::operator >(Hex op)
	{
		if (ar[0] >= 8 && op.ar[0] < 8)
			return 0;
		if (ar[0] < 8 && op.ar[0] >= 8)
			return 1;
		for (int i = 0; i < SZ; i++)
		{
			if (ar[i] < op.ar[i])
				return 0;
		}
		if (((*this) == (op)) == true)
			return 0;
		return 1;
	}

	bool Hex::operator <(Hex op)
	{
		if (ar[0] >= 8 && op.ar[0] < 8)
			return 1;
		if (ar[0] < 8 && op.ar[0] >= 8)
			return 0;
		for (int i = 0; i < SZ; i++)
		{
			if (ar[i] > op.ar[i])
				return 0;
		}
		if (((*this) == (op)) == true)
			return 0;
		return 1;
	}
	bool Hex::operator >=(Hex op)
	{
		if (ar[0] >= 8 && op.ar[0] < 8)
			return 0;
		if (ar[0] < 8 && op.ar[0] >= 8)
			return 1;
		for (int i = 0; i < SZ; i++)
		{
			if (ar[i] < op.ar[i])

				return 0;
		}
		return 1;
	}

	bool Hex::operator <=(Hex op)
	{
		if (ar[0] >= 8 && op.ar[0] < 8)
			return 1;
		if (ar[0] < 8 && op.ar[0] >= 8)
			return 0;
		for (int i = 0; i < SZ; i++)
		{
			if (ar[i] > op.ar[i])

				return 0;
		}
		return 1;
	}
}