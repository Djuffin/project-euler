using System;
using System.Collections.Generic;
using System.Text;

class MaximizeSquares
{
	int criticalStep = 1;
	int lastCriticalPoint = 0;
	int skipIncrese = 2;

	public int GetNextCriticalPoint()
	{
		lastCriticalPoint += criticalStep;
		if (skipIncrese == 0) {
			criticalStep++;
			skipIncrese = 1;
		} else
			skipIncrese--;
		return lastCriticalPoint;
	}

	public int squareCount(int N)
	{
		if (N < 4) return 0;

		int lastCriticalPoint = 0;
		int nextCriticalPoint = GetNextCriticalPoint();
		int result = 0;

		for (int i = 1; i <= N; i++) {
			if (i == nextCriticalPoint) {
				lastCriticalPoint = nextCriticalPoint;
				nextCriticalPoint = GetNextCriticalPoint();
			} else
				result += i - lastCriticalPoint;
		}

		
		return result;
	}
}
