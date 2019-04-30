using System;
using System.Collections.Generic;
using System.Text;

class HandsShaking
{

	private Dictionary<int, long> cache = new Dictionary<int, long>();


	public long countPerfect(int n)
	{
		if (n < 4) return 1;
		long result = 0;

		if (cache.TryGetValue(n, out result))
			return result;

		for (int i = 1; i < n; i += 2)
			result += countPerfect(i - 1) * countPerfect(n - i - 1);

		cache[n] = result;
		return result;
	}
}
