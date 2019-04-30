using System;
using System.Collections.Generic;
using System.Text;

public class SquareConstruction
{
	int[,] sq;
	int N;
	int i = 0;
	int j = 0;
	int value = 1;

	private void Add(int incI, int incJ)
	{
		i = (i + incI) % N;
		j = (j + incJ) % N;
	}
	private void Fill()
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				sq[i, j] = -1;
	}

	public string[] construct(int N, int a, int b, int c, int d)
	{
		this.N = N;
		sq = new int[N, N];
		Fill();
		
		while (true)
		{
			if (sq[i,j] == -1)
			{
				sq[i, j] = value++;
			}
			else
			{
				Add(c, d);
				if (sq[i, j] != -1) return MakeResult();
				sq[i, j] = value++;
			}
			Add(a, b);
		}
	}

	private string[] MakeResult()
	{
		string[] result = new string[N];
		string[] line = new string[N];
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				line[j] = sq[i,j].ToString();
			result[i] = string.Join(" ", line);
		}

		return result;
	}
}
