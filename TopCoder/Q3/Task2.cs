using System;
using System.Collections.Generic;
using System.Text;

class MemorizingPi
{
	string input;
	List<string> output = new List<string>();
	int index;

	int[,] rank = new int[900, 900];
	bool[,] doGet3 = new bool[900, 900];

	string get3()
	{
		return input.Substring(index, 3);
	}

	string get4()
	{
		return input.Substring(index, 4);
	}

	int getDiff(string s)
	{
		char start = s[0];
		bool first = true;
		for (int i = 0; i < s.Length; i++)
			if (s[i] != start) first = false;
		if (first) return 1;

		for (int pow = 128; pow < 16384; pow *= 2)
		{
			if (pow.ToString() == s)
				return 2;
		}

		bool asc = true;
		for (int i = 1; i < s.Length; i++)
		{
			if (s[i - 1] + 1 != s[i])
				asc = false;
		}
		if (asc) return 4;


		bool desc = true;
		for (int i = 1; i < s.Length; i++)
		{
			if (s[i - 1] - 1 != s[i])
				desc = false;
		}
		if (desc) return 5;

		if (s[0] == s[s.Length - 1]) return 7;

		for (int i = 0; i < s.Length; i++)
			for (int j = i + 1; j < s.Length; j++)
				if (s[i] == s[j]) return 8;

		return 10;
	}



	public string[] segmentation(string[] digits)
	{
		StringBuilder sb = new StringBuilder();
		foreach (string d in digits)
			sb.Append(d);
		input = sb.ToString();

		for (int x3 = 0; x3 < 900 - 1; x3++)
		{
			index += 3;
			rank[x3 + 1, 0] = rank[x3, 0] + getDiff(get3());
			doGet3[x3 + 1, 0] = true;
		}

		index = 0;
		for (int y4 = 0; y4 < 900 - 1; y4++)
		{
			index += 4;
			rank[0, y4 + 1] = rank[0, y4 + 1] + getDiff(get4());
			doGet3[0, y4 + 1] = false;
		}

		index = 0;
		int bestX, bestY, bestR = int.MaxValue;

		for (int x3 = 1; x3 < 900; x3++)
		{
			for (int y4 = 1; y4 < 900; y4++)
			{
				index = x3 * 3 + y4 * 4;
				int r3 = getDiff(get3()); 
				int r4 = getDiff(get4());

				if (r3 + rank[x3 - 1, y4] < r4 + rank[x3, y4 - 1])
				{
					rank[x3, y4] = r3 + rank[x3 - 1, y4];
					doGet3[x3, y4] = true;
				}
				else
				{
					rank[x3, y4] = r4 + rank[x3, y4 - 1];
					doGet3[x3, y4] = false;
				}
				if (sb.Length - index < 3)
				{
					if (rank[x3, y4] < bestR)
					{
						bestR = rank[x3, y4];
						bestX = x3;
						bestY = y4;
					}
				}
			}
		}

		List<string> result = new List<string>();
		while (bestX != 0 || bestY != 0)
		{
			if (doGet3[bestX, bestY])
			{
				result.
			}
			else
			{
			}
		}

		
	}
}
