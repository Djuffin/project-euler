using System;
using System.Collections.Generic;
using System.Text;


class MovieRating
{
	public double calculate(int[] marks, int lowCount, int highCount)
	{
		double sum = 0;
		Array.Sort(marks);
		for (int i = 0; i < marks.Length; i++) {
			if (i < lowCount) continue;
			if (marks.Length - i <= highCount) continue;

			sum += marks[i];
		}

		return (sum) / (marks.Length - lowCount - highCount);
	}
}

