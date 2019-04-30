using System;
using System.Collections.Generic;
using System.Text;

class OptimalGroupMovement
{
	class Group
	{
		public int len;
		public int x;
	}
	string board;
	List<Group> groups = new List<Group>();

	Group getGroup(ref int start)
	{
		while (start < board.Length && board[start] != 'X')
			start++;

		if (start == board.Length)
			return null;

		Group g = new Group();
		g.x = start;

		while (start < board.Length && board[start] == 'X')
			start++;

		g.len = start - g.x;

		return g;
	}

	public int minimumCost(string board)
	{
		this.board = board;
		

		int index = 0;
		Group g = getGroup(ref index);
		while (g != null) {
			groups.Add(g);
			g = getGroup(ref index);
		}

		groups.Sort(delegate(Group g1, Group g2)
		{
			return g1.x - g2.x;
		});


		int[] costs = groups.ConvertAll<int>(
		delegate(Group bestGroup)
		{
			return TryGoToThisGroup(bestGroup);
		}).ToArray();

		Array.Sort(costs);

		return costs[0];
	}

	private int TryGoToThisGroup(Group max)
	{
		List<Group> left = new List<Group>();
		List<Group> right = new List<Group>();
		List<Group> toAdd = left;

		foreach (Group eg in groups) {
			if (eg == max)
				toAdd = right;
			else
				toAdd.Add(eg);
		}

		left.Reverse();

		int cost = 0;
		int leftSide = max.x;
		int rightSide = max.x + max.len;

		foreach (Group lg in left) {
			cost += lg.len * lg.len * (leftSide - (lg.x + lg.len));
			leftSide -= lg.len;
		}

		foreach (Group rg in right) {
			cost += rg.len * rg.len * (rg.x - rightSide);
			rightSide += rg.len;
		}
		return cost;
	}
}
