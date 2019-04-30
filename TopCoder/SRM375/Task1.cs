using System;
using System.Collections.Generic;
using System.Text;

public class DivisibleByDigits
{
	long start;
	byte[] digits = new byte[100];
	int len = 1;

	private void inc()
	{
		for (int i = 0; i < len; i++) {
			if (digits[i] != 9) {
				digits[i]++;
				return;
			} else {
				digits[i] = 0;
			}
		}

		len++;
	}

	private long getNext()
	{
		string s = string.Empty;
		for (int i = len - 1; i >= 0; i--)
			s += digits[i].ToString();

		inc();
		return long.Parse(start.ToString() + s);		
	}

	private bool divisible(long p)
	{
		long p1 = p;

		for (; p1 != 0; p1 /= 10) {
			int d = (int)(p1 % 10);
			if (d != 0 && (p % d != 0)) return false;
		}

		return true;
	}

	public long getContinuation(int n)
	{
		start = n;
		if (divisible(start)) return start;
		

		while (true) {
			long m = getNext();
			if (divisible(m)) return m;
		}
	}
}
