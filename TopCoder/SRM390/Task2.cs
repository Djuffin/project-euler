using System;
using System.Collections.Generic;
using System.Text;

public class ConcatenateNumber
{



	
	private List<int> GetDigits(int n)
	{
		List<int> digits = new List<int>();
		while (n > 0)
		{
			digits.Add(n % 10);
			n -= n % 10;
			n /= 10;
		}
		return digits;
	}

	List<int> _digits;
	List<int> rs = new List<int>();
	private void getR(int k)
	{
		int r = 1;

		while (!rs.Contains(r))
		{
			rs.Add(r);
			r = (r * 10) % k;
		}
	}

	private int GetSum()
	{
		int result = 0;
		for (int i = 0; i < _digits.Count; i++)
		{
			result += _digits[i] * rs[i % rs.Count];
		}
		return result;
	}

	private void AddDigits(int n)
	{
		_digits.AddRange(GetDigits(n));
	}


	public int getSmallest(int number, int k)
	{
		_digits = GetDigits(number);
		getR(k);

		int result = 1;

		int s;
		while (true)
		{
			s = GetSum();
			if (s % k == 0)
				return result;
			else
			{
				//if (digits.Count > rs.Count) return -1;
				AddDigits(number);
				result++;
			}
		} 

	}
}
