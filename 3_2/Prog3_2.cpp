#include "Hex_S_2.h"

using namespace Prog3_2;


int main()
{
	int b = 1;
	int k;
	Hex st, sum;
	bool n;
	do
	{
		switch (b)
		{
		case 1:
			std::cout << "Enter new hex number:  ";
			try
			{
				std::cin >> st;
			}
			catch (const std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			std::cout << "Your new hex number:  ";
			std::cout << st;
			break;
		case 2:
			std::cout << "Enter the second summand:  ";
			try
			{
				std::cin >> sum;
			}
			catch (const std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			std::cout << "Your the second summand:  ";
			std::cout << sum;
			st += (sum);
			std::cout << "Your result:  ";
			std::cout << st;
			break;
		case 3:
			std::cout << "Enter subtrahned:  ";
			try
			{
				std::cin >> sum;;
			}
			catch (const std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			std::cout << "Your subtrahned:  ";
			std::cout << sum;
			st -= (sum);
			std::cout << "Your result:  ";
			std::cout << st;
			break;
		case 4:
			std::cout << "Enter the shift amount:  ";
			std::cin >> k;
			while (!std::cin.good())
			{
				if (std::cin.eof())
					return 0;
				std::cout << "You are wrong! You probably entered the letters" << std::endl;
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cin >> k;
			}
			st << (k);
			std::cout << "Your result:  ";
			std::cout << st;
			break;
		case 5:
			std::cout << "Enter the shift amount:  ";
			std::cin >> k;
			while (!std::cin.good())
			{
				if (std::cin.eof())
					return 0;
				std::cout << "You are wrong! You probably entered the letters" << std::endl;
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cin >> k;
			}
			st >> (k);
			std::cout << "Your result:  ";
			std::cout << st;
			break;
		case 6:
			std::cout << "Enter the second number:  ";
			try
			{
				std::cin >> sum;;
			}
			catch (const std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			std::cout << "Your the first number:  ";
			std::cout << st;
			std::cout << "Your the second number:  ";
			std::cout << sum;
			n = st == (sum);
			std::cout << "The numbers are equal:  ";
			if (n == true)
				puts("True");
			else
				puts("False");
			break;
		case 7:
			std::cout << "Enter the second number:  ";
			try
			{
				std::cin >> sum;;
			}
			catch (const std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			std::cout << "Your the first number:  ";
			std::cout << st;
			std::cout << "Your the second number:  ";
			std::cout << sum;
			n = (st != (sum));
			std::cout << "The numbers are not equal:  ";
			if (n == true)
				puts("True");
			else
				puts("False");
			break;
		case 8:
			std::cout << "Enter the second number:  ";
			try
			{
				std::cin >> sum;;
			}
			catch (const std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			std::cout << "Your the first number:  ";
			std::cout << st;
			std::cout << "Your the second number:  ";
			std::cout << sum;
			n = st > (sum);
			std::cout << "The first one is greater than the second one:  ";
			if (n == true)
				puts("True");
			else
				puts("False");
			break;
		case 9:
			std::cout << "Enter the second number:  ";
			try
			{
				std::cin >> sum;
			}
			catch (const std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			std::cout << "Your the first number:  ";
			std::cout << st;
			std::cout << "Your the second number:  ";
			std::cout << sum;
			n = st < (sum);
			std::cout << "The first one is less than the second one:  ";
			if (n == true)
				puts("True");
			else
				puts("False");
			break;
		case 10:
			std::cout << "Your number:  ";
			std::cout << st;
			if (st.multoftwo() == true)
				puts("The number is odd");
			else
				puts("The number is even");
			break;
		case 11:
			std::cout << "Enter the second number:  ";
			try
			{
				std::cin >> sum;;
			}
			catch (const std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			std::cout << "Your the first number:  ";
			std::cout << st;
			std::cout << "Your the second number:  ";
			std::cout << sum;
			n = st >= (sum);
			std::cout << "The first one is greater than the second one or equal:  ";
			if (n == true)
				puts("True");
			else
				puts("False");
			break;
		case 12:
			std::cout << "Enter the second number:  ";
			try
			{
				std::cin >> sum;
			}
			catch (const std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			std::cout << "Your the first number:  ";
			std::cout << st;
			std::cout << "Your the second number:  ";
			std::cout << sum;
			n = st <= (sum);
			std::cout << "The first one is less than the second one or equal:  ";
			if (n == true)
				puts("True");
			else
				puts("False");
			break;
		default:
			std::cout << "Invalid number";
			break;
		}
		std::cout << "0. Exit \n1. Enter new hex number\n2. Add\n3. Subtract\n4. Shift left\n5. Shift right\n6. Equal\n7. Not equal\n8. Greater\n9. Less\n10. Multiple of two\n11. Greater or equal\n12. Less or equal" << std::endl;
		std::cout << "Enter the next step:  ";
		std::cin >> b;
		while (!std::cin.good())
		{
			if (std::cin.eof())
				return 0;
			std::cout << "You are wrong! You probably entered the letters" << std::endl;
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cin >> b;
		}
	} while (b != 0);
	return 0;
}