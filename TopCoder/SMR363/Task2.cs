using System;
using System.Collections.Generic;
using System.Text;

class MirrorNumber
{

	private long GetCountByLen(int n)
	{
		if (n == 1) return 3;
		if (n == 2) return 4;
		if (n == 3) return 12;
		if (n == 4) return (GetCountByLen(n - 2) + 1) * 4;
	}

	private bool is018(char c)
	{
		return (c == '0' || c == '1' || c == '8');
	}

	private bool is25(char c)
	{
		return c == '2' || c == '5';
	}

	private bool Test(string N)
	{
		for (int i = 0; i < N.Length / 2; i++)
		{
			if (is018(N[i])) 
			{
				if (N[i] != N[N.Length - i - 1]) return false;
			} else if (is25(N[i]))
			{
				if (N[i] == '2') 
				{
					if (N[N.Length - i - 1] != '5') return false;
				}
				else if (N[N.Length - i - 1] != '2') return false;
			}

			return false;
		}

		if (N.Length % 2 == 1 && (!is018(!N[N.Length / 2])))
			return false;

		return true;
	}

	public int count(string A, string B)
	{
	}
}
