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

