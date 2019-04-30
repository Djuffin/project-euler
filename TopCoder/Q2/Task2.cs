using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;

public class BasketballStandings
{
	class Team
	{
		public string name;
		public int wins;
		public int lose;
		public double score;
		public int games
		{
			get
			{
				return wins + lose;
			}
		}

		public Team() { }
		public Team (string str)
		{
			Match m = Regex.Match(str, @"(\w+)\s+(\d+)\s+(\d+)", RegexOptions.IgnoreCase );
			name = m.Groups[1].Value;
			wins = int.Parse(m.Groups[2].Value);
			lose = int.Parse(m.Groups[3].Value);
		}

		public string ToString(double maxScore)
		{
			double gap = maxScore - score;


			string strGap = ((int)gap).ToString() + "." + ((gap - (int)(gap)) != 0 ? "5" : "0");
			return name + " " + strGap;

		}
	}


	public string[] constructTable(string[] teams)
	{
		List<Team>Teams = new List<Team>();

		int maxGames = 0;

		foreach (string s in teams)
		{
			Team t = new Team(s);

			if (t.games > maxGames)
				maxGames = t.games;
			Teams.Add(t);
		}

		foreach (Team t in Teams)
		{
			t.score = t.wins + (maxGames - t.games) / 2.0;
		}

		Teams.Sort(delegate(Team t1, Team t2)
		{
			int gap = (int)((t2.score - t1.score) * 100);
			if (gap != 0) return gap;

			return t1.name.CompareTo(t2.name);
		});

		List<string> result = new List<string>();
		double maxScore = Teams[0].score;
		foreach (Team t in Teams)
		{
			result.Add(t.ToString(maxScore));
		}

		return result.ToArray();
	}
}