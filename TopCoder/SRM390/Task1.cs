using System;
using System.Collections.Generic;
using System.Text;

public class FingerCounting
{

	int[] fingers = new int[] { 1, 2, 3, 4, 5, 4, 3, 2 };
	int index = 0;

	private int GetNext()
	{
		return fingers[index++ % fingers.Length];
	}

	public int maxNumber(int weakFinger, int maxCount)
	{
		for (int result = 0; ; result++)
		{
			int finger = GetNext();
			if (weakFinger == finger)
			{
				if (maxCount == 0) return result;
				else maxCount--;
			}
			
		}
	}
}
