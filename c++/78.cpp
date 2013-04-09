/*
Coin partitions
Problem 78
Let p(n) represent the number of different ways in which n coins can be separated into piles. 
For example, five coins can separated into piles in exactly seven different ways, so p(5)=7.

OOOOO
OOOO   O
OOO   OO
OOO   O   O
OO   OO   O
OO   O   O   O
O   O   O   O   O
Find the least value of n for which p(n) is divisible by one million.

*/
#include <iostream>
#include <inttypes.h>

const int max_size  = 100000;
uint32_t  table[max_size + 1];
const int N = 1000000;
using namespace std;

//this function is taken from Problem 31, with only addition of % N to avoid overflow
void inline one_step(int coin)
{
	table[coin]++;
	table[coin] %= N;

	for (int i = coin + 1; i <= max_size; i++)
	{
		table[i] = (table[i] + table[i - coin]) % N; 
	}
}
int main()
{

	int result = 0;
	for (int i = 1; i < max_size; i++)
	{
		one_step(i);
		if (i != 1 && table[i] == 0)
		{
			result = i;
			break;
		}
	        
		if (i % 1000 == 0)
			cout << i << "  " << table[i] << endl;
	}
	
	std::cout << result <<  std::endl;
	return 0;
}
