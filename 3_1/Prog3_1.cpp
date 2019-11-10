#include "Hex_S_1.h"

using namespace Prog3_1;


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
				st.input(std::cin);
			}
			catch (const std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			std::cout << "Your new hex number:  ";
			st.print(std::cout);
			break;
		case 2:
			std::cout << "Enter the second summand:  ";
			try
			{
				sum.input(std::cin);
			}
			catch (const std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			std::cout << "Your the second summand:  ";
			sum.print(std::cout);
			st.add(sum);
			std::cout << "Your result:  ";
			st.print(std::cout);
			break;
		case 3:
			std::cout << "Enter subtrahned:  ";
			try
			{
				sum.input(std::cin);;
			}
			catch (const std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			std::cout << "Your subtrahned:  ";
			sum.print(std::cout);
			st.sub(sum);
			std::cout << "Your result:  ";
			st.print(std::cout);
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
			st.shiftleft(k);
			std::cout << "Your result:  ";
			st.print(std::cout);
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
			st.shiftright(k);
			std::cout << "Your result:  ";
			st.print(std::cout);
			break;
		case 6:
			std::cout << "Enter the second number:  ";
			try
			{
				sum.input(std::cin);;
			}
			catch (const std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			std::cout << "Your the second number:  ";
			sum.print(std::cout);
			n = st.equal(sum);
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
				sum.input(std::cin);;
			}
			catch (const std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			std::cout << "Your the second number:  ";
			sum.print(std::cout);
			n = st.notequal(sum);
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
				sum.input(std::cin);;
			}
			catch (const std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			std::cout << "Your the second number:  ";
			sum.print(std::cout);
			n = st.greater(sum);
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
				sum.input(std::cin);
			}
			catch (const std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			std::cout << "Your the second number:  ";
			sum.print(std::cout);
			n = st.less(sum);
			std::cout << "The first one is less than the second one:  ";
			if (n == true)
				puts("True");
			else
				puts("False");
			break;
		case 10:
			if (st.multoftwo() == true)
				puts("The number is odd");
			else
				puts("The number is even");
			break;
		default:
			std::cout << "Invalid number";
			break;
		}
		std::cout << "0. Exit \n1. Enter new hex number\n2. Add\n3. Subtract\n4. Shift left\n5. Shift right\n6. Equal\n7. Not equal\n8. Greater\n9. Less\n10. Multiple of two" << std::endl;
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