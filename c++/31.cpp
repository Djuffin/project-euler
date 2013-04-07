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
