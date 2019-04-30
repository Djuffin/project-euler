using System;
using System.Collections.Generic;
using System.Text;

class BuildATeam
{
	public int maximalStrength(int[] skills, int teams)
	{
		List<int> Skills = new List<int>(skills);
		int[] Teams = new int [teams];

		Skills.Sort();
		int add = 1;
		int index = 0;

		while (Skills.Count != 0) {

			int skill = Skills[Skills.Count - 1];
			Skills.RemoveAt(Skills.Count - 1);

			Teams[index] += skill;

			if ((index == 0 && add == -1) || (index == Teams.Length - 1 && add == 1))
				add = -add;
			else
				index += add;
		}

		int max_team = 0;

		for (int i = 0; i < Teams.Length; i++)
			if (Teams[max_team] < Teams[i]) 
				max_team = i;

		return Teams[max_team];
	}
}
