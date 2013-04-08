/* Problem 26

Reciprocal cycles

A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

1/2	= 	0.5
1/3	= 	0.(3)
1/4	= 	0.25
1/5	= 	0.2
1/6	= 	0.1(6)
1/7	= 	0.(142857)
1/8	= 	0.125
1/9	= 	0.(1)
1/10	= 	0.1
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d  1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

*/


#include <iostream>

const int max_n = 1000;

int get_cycle_len(int n)
{
	int seen[max_n + 1];
	for (int i = 1; i < max_n; i++)
		seen[i] = -1;

	int count = 0;
	int reminder = 1;
	do
	{
		seen[reminder] = count;
		while (reminder < n)
		{
			reminder *= 10;
		}

		reminder %= n;
		if (reminder == 0)
		{
			return 0;
		}
		count++;
	}
	while (seen[reminder] == -1);

	return count - seen[reminder];
}
int main()
{
	int max = 0, d = 0;
	for (int i = 2; i < max_n; i++)
	{
		int c = get_cycle_len(i);
		std::cout << i << "  " << c << std::endl;
		if (c > max)
		{
			max = c;
			d = i;
		}
	}

	std::cout << "result:" << d << "  " << max << std::endl;
	return 0;
}

