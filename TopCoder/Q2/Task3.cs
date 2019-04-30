using System;
using System.Collections.Generic;
using System.Text;

class BuildTheBestTeam
{

	class Player
	{
		public int usual;
		public int power;

		public Player(int usual, int power)
		{
			this.usual = usual;
			this.power = power;
		}

	}

	int add = 1;
	int teams;
	public int GetNext(int current)
	{
		if ((current == 0 && add == -1) || (current == teams - 1 && add == 1))
			add = -add;
		else
			current += add;

		return current;
	}

	public int maximalStrength(int[] usualSkills, int[] powerplaySkills, int teams, int ind)
	{
		this.teams = teams;
		List<Player> players = new List<Player>();

		for (int i = 0; i < usualSkills.Length; i++)
			players.Add(new Player(usualSkills[i], powerplaySkills[i]));

		players.Sort(delegate(Player p1, Player p2)
		{
			if (p1.usual == p2.usual)
				return p1.power - p2.power;

			return p1.usual - p2.usual;
		});

		int resultSkill = 0;
		int currentTeam = 0;
		while (players.Count != 0)
		{
			List<Player> forGet = new List<Player>();

			do
			{
				Console.Write(currentTeam);
				forGet.Add(players[players.Count - 1]);
				players.RemoveAt(players.Count - 1);
				currentTeam = GetNext(currentTeam);

			} while (currentTeam != ind - 1 && players.Count != 0);

			forGet.Sort(delegate(Player p1, Player p2)
			{
				return p1.power - p2.power;
			});

			if (currentTeam == ind - 1)
				resultSkill += forGet[forGet.Count - 1].power;
		}

		return resultSkill;
	}

}
