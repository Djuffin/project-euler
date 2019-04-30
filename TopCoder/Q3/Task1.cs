using System;
using System.Collections.Generic;
using System.Text;

class PacketRepack
{

	int[] input;
	int[] Output;
	int b;

	public bool getBit(int index)
	{
		int n = index / b;
		int offset = index % b;
		return (input[n] & (1 << offset)) != 0;
	}


	public void setBit(int index, bool v)
	{
		int n = index / b;
		int offset = index % b;

		if (v)
			Output[n] = Output[n] | (1 << offset);
		else
			Output[n] = Output[n] & (~(1 << offset));
			
	}


	public int[] output(int[] input, int b, int num_fields, int field_size)
	{
		this.input = input;
		this.b = b;
		Output = new int[input.Length];

		for (int i = 0; i < num_fields; i++)
		{
			for (int j = 0; j < field_size; j++)
			{
				bool v = getBit(i * field_size + j);
				int index = (num_fields - 1 - i) * field_size + j;
				setBit(index, v);
			}
		}

		return Output;

	}
}
