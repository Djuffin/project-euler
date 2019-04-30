using System;
using System.Collections.Generic;
using System.Text;

public class BusAwaiting
{

	public class Route
	{
		public int start, count, interval;
		public Route(string s)
		{
			string[] ss = s.Split(' ');
			start = int.Parse(ss[0]);
			interval = int.Parse(ss[1]);
			count = int.Parse(ss[2]) - 1;
		}
	}

	private int getWaitTime(Route r, int arrivalTime)
	{

		if (arrivalTime > r.start)
		{
			int c = (arrivalTime - r.start) / r.interval;
			if ((arrivalTime - r.start) % r.interval != 0) c++;
			if (c > r.count) return -1;
			return c * r.interval + r.start - arrivalTime;
		}
		else
			return r.start - arrivalTime;
	}

	public int waitingTime(string[] buses, int arrivalTime)
	{
		List<Route> routes = new List<string>(buses).ConvertAll<Route>(delegate(string s)
		{
			return new Route(s);
		});

		int bestResult = -1;
		foreach (Route r in routes)
		{
			int result = getWaitTime(r, arrivalTime);
			if (bestResult == -1)
				bestResult = result;
			else
			{
				if (result != -1)
					bestResult = Math.Min(result, bestResult);
			}
		}

		return bestResult;

	}
}
