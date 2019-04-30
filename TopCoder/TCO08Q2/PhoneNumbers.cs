using System;
using System.Collections.Generic;
using System.Text;

public class PhoneNumbers
{

	private int groupCost(string group)
	{
		int[] digits = new int[10];
		foreach (char c in group)
			digits[c - '0']++;

		int cost = 0;
		foreach(int i in digits)
		{
			if (i == group.Length)
			{
				cost = 2;
				break;
			}
			if (i == 2)
			{
				cost = 1;
			}
		}
		return cost;
	}

	class Breakup
	{
		public int cost;
		public int position;
		public List<string> groups = new List<string>();

		public override string ToString()
		{
			return string.Join("-", groups.ToArray());
		}

		public bool IsBefort(Breakup other)
		{
			for (int i = 0; i < Math.Min(groups.Count, other.groups.Count); i++)
			{
				if (groups[i].Length == 2 && other.groups[i].Length == 3)
					return true;
				if (groups[i].Length == 3 && other.groups[i].Length == 2)
					return false;
			}

			return false;

		}
	}

	private Breakup[,] breaks = new Breakup[50, 50];


	private Breakup GetNewBreakup(string number, Breakup old, int size)
	{
		if (old == null) return null;
		if (number.Length < old.position + size) return null;
		
		string group = number.Substring(old.position, size);
		Breakup result = new Breakup();
		result.groups.AddRange(old.groups);
		result.groups.Add(group);
		result.cost = groupCost(group) + old.cost;
		result.position = old.position + group.Length;

		return result;
	}


	public string bestNumber(string number)
	{
		breaks[0, 0] = new Breakup();

		Breakup result = null;
		for (int y = 0; y < 50; y++)//groups by 3
		{
			for (int x = 0; x < 50; x++) //groups by 2
			{
				if (x == 0 && y == 0) continue;

				Breakup bg2 = null, bg3 = null;
				if (x != 0)
					bg2 = GetNewBreakup(number, breaks[x - 1, y], 2);
				if (y != 0) 
					bg3 = GetNewBreakup(number, breaks[x, y - 1], 3);

				Breakup current = bg2;
				if (current == null || (bg3 != null && (bg3.cost > current.cost || (bg3.cost == current.cost && bg3.IsBefort(current)))))
					current = bg3;

				if (current == null)
					continue;

				if (current.position == number.Length)
				{
					if (result == null ||
						result.cost < current.cost ||
						result.cost == current.cost && current.IsBefort(result))
					{
						result = current;
					}
				}
				breaks[x, y] = current;
			}
		}

		return result.ToString();


				
	}
}
