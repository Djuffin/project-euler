/* Problem 31
Coin sums

In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
It is possible to make £2 in the following way:

1£1 + 150p + 220p + 15p + 12p + 31p
How many different ways can £2 be made using any number of coins?
*/

#include <iostream>
#include <inttypes.h>

const int target  = 200;
int  result[target + 1];

void one_step(int coin)
{
	result[coin]++;
	for (int i = coin + 1; i <= target; i++)
		result[i] += result[i - coin]; 
}
int main()
{
	one_step(1);
	one_step(2);
	one_step(5);
	one_step(10);
	one_step(20);
	one_step(50);
	one_step(100);
	one_step(200);
	std::cout << result[target] << std::endl;
	return 0;
}
