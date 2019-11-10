#include "Hex_S_3.h"
#include <string>


namespace Prog3_3
{
	Hex::Hex(char a[])
	{
		SZ = 8;
		while (sizeof(a) >= SZ)
		{
			SZ += quota;

		}
		ar = new char[SZ];
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
		SZ = 8;
		while (a.length() >= SZ)
		{
			SZ += quota;
		}
		ar = new char[SZ];
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

	Hex::Hex(const Hex &st) : SZ(st.SZ)
	{
		ar = new char[SZ];
		for (int i = 0; i < SZ; ++i)
			ar[i] = st.ar[i];
	}

	Hex::Hex(Hex &&st) : SZ(st.SZ), ar(st.ar)
	{
		st.ar = nullptr;
	}

	Hex & Hex::operator =(const Hex &st)
	{
		if (this != &st)
		{
			SZ = st.SZ;
			delete[] ar;
			ar = new char[SZ];
			for (int i = 0; i < SZ; ++i)
				ar[i] = st.ar[i];
		}
		return *this;
	}

	Hex & Hex::operator =(Hex &&st)
	{
		int tmp = SZ;
		SZ = st.SZ;
		st.SZ = tmp;
		char *ptr = ar;
		ar = st.ar;
		st.ar = ptr;
		return *this;
	}

	std::ostream & operator << (std::ostream &s, const Hex &st)
	{
		char k;
		int t = 0;
		if (st.ar[0] > 7)
		{
			t = 1;
			s << "-";
			st.ar[0] -= 8;
			while (st.ar[t] == 0 && t < st.SZ - 1)
				t++;
			if (st.ar[0] != 0)
				k = st.ar[0] + '0';
			st.ar[0] += 8;
		}
		else
		{
			s << "+";
			while (st.ar[t] == 0 && t < st.SZ - 1)
				t++;
		}
		for (int i = t; i < st.SZ; i++)
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
		int t = 0, m;
		while (ar[t] == 0)
			t++;
		m = k - t;
		if (m > 0)
		{
			SZ += (quota*(m / quota + 1));
			char *old = ar;
			ar = new char[SZ];
			for (int i = 0; i < SZ - (quota*(m / quota + 1)); ++i)
				ar[i + (quota*(m / quota + 1))] = old[i];
			delete[] old;
			for (int i = 0; i < (quota*(m / quota + 1)); ++i)
				ar[i] = 0;
		}
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

	Hex& Hex:: operator +=(const Hex& p)
	{
		int c = 0;
		Hex s = p;
		expansion(*this, s);
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
		if (c == 1 && ar[0] < 8 && s.ar[0] < 8)
		{
			SZ += quota;
			char *old = ar;
			ar = new char[SZ];
			for (int i = 0; i < SZ - quota; ++i)
				ar[i + quota] = old[i];
			delete[] old;
			for (int i = 0; i < quota; ++i)
				ar[i] = 0;
			ar[0] = 1;
		}
		if (ar[0] >= 8)
			(*this).invert();
		return *this;
	}

	Hex operator +(const Hex& p, const Hex& k)
	{
		int c = 0;
		Hex a = k, s = p, s1 = k;
		expansion(a, s);
		if (s1.ar[0] >= 8)
			(a).invert();
		if (s.ar[0] >= 8)
			s.invert();
		for (int i = s1.SZ - 1; i >= 0; i--)
		{
			s1.ar[i] = s1.ar[i] + s.ar[i] + c;
			if (s1.ar[i] > 15)
			{
				c = 1;
				s1.ar[i] -= 16;
			}
			else
				c = 0;
		}
		if (c == 1 && s1.ar[0] < 8 && s.ar[0] < 8)
		{
			s1.SZ += s1.quota;
			char *old = s1.ar;
			s1.ar = new char[s1.SZ];
			for (int i = 0; i < s1.SZ - s1.quota; ++i)
				s1.ar[i + s1.quota] = old[i];
			delete[] old;
			for (int i = 0; i < s1.quota; ++i)
				s1.ar[i] = 0;
			s1.ar[0] = 1;
		}
		if (s1.ar[0] >= 8)
			(a).invert();
		return a;
	}

	Hex& Hex:: operator -=(const Hex& s)
	{
		int c = 0;
		Hex t = *this;
		if (s.ar[0] >= 8)
			s.ar[0] -= 8;
		else
			s.ar[0] += 8;
		t += s;
		return t;
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

	bool Hex::operator ==(const Hex& op)
	{
		int t;
		if (SZ < op.SZ)
			t = SZ;
		else
			t = op.SZ;
		for (int i = SZ - 1; i > 0; i--)
		{
			if (ar[i] != op.ar[i])
				return 0;
		}
		return 1;
	}

	bool Hex::operator !=(const Hex& op)
	{
		bool j = !((*this) == (op));
		return j;
	}

	bool Hex::operator >(const Hex& k)
	{
		Hex op = k;
		expansion(*this, op);
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

	bool Hex::operator <(const Hex& k)
	{
		Hex op = k;
		expansion(*this, op);
		if (ar[0] >= 8 && op.ar[0] < 8)
			return 1;
		if (ar[0] < 8 && op.ar[0] >= 8)
			return 0;
		for (int i = 0; i < SZ; i++)
		{
			if (ar[i] > op.ar[i])
				return 0;
		}
		if (((*this) == op) == true)
			return 0;
		return 1;
	}
	bool Hex::operator >=(const Hex& k)
	{
		Hex op = k;
		expansion(*this, op);
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

	bool Hex::operator <=(const Hex& k)
	{
		Hex op = k;
		expansion(*this, op);
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

	int expansion(Hex& a, Hex& b)
	{
		if (a.SZ > b.SZ)
		{
			int t = b.SZ, k = a.SZ - b.SZ, c = 0;
			if (b.ar[0] >= 8)
			{
				b.ar[0] -= 8;
				c++;
			}
			b.SZ = a.SZ;
			char *old = b.ar;
			b.ar = new char[b.SZ];
			for (int i = 0; i < t; ++i)
				b.ar[i + k] = old[i];
			delete[] old;
			for (int i = 0; i < k; ++i)
				b.ar[i] = 0;
			if (c == 1);
			b.ar[0] = 1;
		}
		if (a.SZ < b.SZ)
		{
			int t = a.SZ, k = b.SZ - a.SZ, c = 0;
			if (a.ar[0] >= 8)
			{
				a.ar[0] -= 8;
				c++;
			}
			a.SZ = b.SZ;
			char *old = a.ar;
			a.ar = new char[a.SZ];
			for (int i = 0; i < t; ++i)
				a.ar[i + k] = old[i];
			delete[] old;
			for (int i = 0; i < k; ++i)
				a.ar[i] = 0;
			a.ar[0] = 1;
		}
		return 0;
	}
}