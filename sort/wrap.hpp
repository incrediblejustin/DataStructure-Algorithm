#ifndef _WRAP_HPP_
#define _WRAP_HPP_
#include <iostream>

using namespace std;

template<typename _It>
void Print_1(_It First, _It Last)
{
	for (; First != Last; ++First)
	{
		cout << *First << ' ';
	}
	cout << '\n';
}

template<typename _Ty>
void Swap(_Ty &Left, _Ty &Right)
{
	_Ty tmp(move(Left));
	Left = move(Right);
	Right = move(tmp);
}

#endif