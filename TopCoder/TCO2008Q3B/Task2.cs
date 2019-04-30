using System;
using System.Collections.Generic;
using System.Text;

public class CableDonation
{
	private int N;
	private int[,] len;
	private int totalDonate = 0;
	private int[] color;

	List<Cabel> cabels = new List<Cabel>();

	private class Cabel
	{
		public int i, j;
		public int len;
	}

	public int cable(string[] lengths)
	{
		Parse(lengths);
		foreach (Cabel c in cabels)
		{
			if (color[c.i] != color[c.j])
			{
				ReplaceColor(color[c.j], color[c.i]);
			}
			else
			{
				totalDonate += c.len;
			}
		}

		for (int i = 1; i < color.Length; i++)
			if (color[i] != color[0]) 
				return -1;

		return totalDonate;
	}

	private void ReplaceColor(int oldColor, int newColor)
	{
		for (int i = 0; i < color.Length; i++)
		{
			if (color[i] == oldColor)
				color[i] = newColor;
		}
	}

	private void Parse(string[] lengths)
	{

		N = lengths.Length;
		len = new int[N, N];
		color = new int[N];
		for (int i = 0; i < N; i++)
		{
			color[i] = i;
			for (int j = 0; j < N; j++)
			{
				char c = lengths[i][j];
				if (c == '0')
					len[i, j] = 0;

				if (char.IsUpper(c))
					len[i, j] = c - 'A' + 27;

				if (char.IsLower(c))
					len[i, j] = c - 'a' + 1;

				if (len[i, j] != 0)
				{
					Cabel cab = new Cabel();
					cab.i = i;
					cab.j = j;
					cab.len = len[i, j];
					cabels.Add(cab);
				}
			}
		}

		cabels.Sort(delegate(Cabel left, Cabel rigth)
		{
			return left.len - rigth.len;
		});
	}
}
