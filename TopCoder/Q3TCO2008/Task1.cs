using System;
using System.Collections.Generic;
using System.Text;

public	class ChessTourney
{

	public double expectedWinning(int[] winnings, int[] odds)
	{
		double result = winnings[0];
		double probability = 1.0;
		for (int i = 1; i < winnings.Length; i++)
		{
			probability *= odds[i - 1] / 100.0;
			result += winnings[i] * probability;
		}

		return result;
	}
}
