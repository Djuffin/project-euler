using System;
using System.Collections.Generic;
using System.Text;

class CommonMultiples
{


	public int countCommMult(int[] a, int lower, int upper)
	{
		int M = 1;

		for (int i = 0; i < a.Length; i++) {
			M *= a[i];
		}  

		for (int i = 2; i < M; i++)
			if (M % i == 0) {

				int k = M / i;
				bool ok = true;
				for (int j = 0; j < a.Length; j++) {
					if (k % a[j] != 0)
						ok = false;
				}
				if (ok) M = k;


			}

		int count = (upper - lower) / M;
		if (lower % M == 0) count++;
		if (lower / M != upper / M) count++;

		return count;
	}
}
