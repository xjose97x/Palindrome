/********************************************
*Program Name: Palindrome					*
*Programming Language: C++                  *
*Author: José I. Escudero                   *
*E-mail: joseignacioescudero97@hotmail.com  *
********************************************/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <multiprecision\cpp_int.hpp>


bool isint(std::string placeholder);
boost::multiprecision::uint1024_t reverse(boost::multiprecision::uint1024_t num);

int main()
{
	boost::multiprecision::uint1024_t num;
	std::string placeholder;
	do
	{
		std::cout << "Please give me a number: " << std::endl;
		std::cin >> placeholder;
	} while (isint(placeholder) != true);
	num = std::stol(placeholder);
	boost::multiprecision::uint1024_t reversed = 0;
	int iterator = 1;
	while (reversed != num)
	{
		std::cout << "Iteration #" << iterator << std::endl;
		reversed = reverse(num);
		if (reversed != num)
		{
			num += reversed;
		}
		std::cout << reversed << std::endl;
		iterator++;
	}

    return 0;
}

bool isint(std::string placeholder)
{
	for (int i = 0; i < size(placeholder); i++)
	{
		if (!isdigit(placeholder[i]))
		{
			return false;
		}
	}
	return true;
}

boost::multiprecision::uint1024_t reverse(boost::multiprecision::uint1024_t num)
{
	boost::multiprecision::uint1024_t x = 0;
	boost::multiprecision::uint1024_t reversed;
	while (num != 0)
	{
		boost::multiprecision::uint1024_t remainder = num % 10;
		x = x * 10 + remainder;
		num /= 10;
	}
	reversed = x;
	return reversed;
}