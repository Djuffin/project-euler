using System;
using System.Collections.Generic;
using System.Text;

public class RandomNetwork
{

	private bool[,] connected;


	public double[] probableLocation(string[] network, int steps)
	{
		ParseInput(network);

		double[] result = new double[network.Length];
		result[0] = 1.0;

		for (int i = 0; i < steps; i++)
			result = OneStep(result);

		return result;

	}

	private double[] OneStep(double[] initial)
	{
		double[] result = new double[initial.Length];

		for (int i = 0; i < initial.Length; i++)
		{
			int count = 0;
			for (int j = 0; j < initial.Length; j++)
			{
				if (i == j) continue;
				if (connected[i, j])
					count++;
			}

			double probability = initial[i] / count;
			for (int j = 0; j < initial.Length; j++)
			{
				if (i == j) continue;
				if (connected[i, j])
					result[j] += probability;
			}
		}

		return result;
	}

	private void ParseInput(string[] network)
	{
		connected = new bool[network.Length, network.Length];
		for (int i = 0; i < network.Length; i++)
			for (int j = 0; j < network.Length; j++)
				connected[i, j] = network[i][j] == 'Y';
	}
}
