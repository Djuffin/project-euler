using System;
using System.Collections.Generic;
using System.Text;

public class DiscountCombination
{
	private class Discount
	{
		public int price;
		public int percent;

		public Discount(string s)
		{
			string[] ss = s.Split(' ');
			price = int.Parse(ss[0]);
			percent = int.Parse(ss[1]);
		}
	}

	List<Discount> discounts = new List<Discount>();

	public double minimumPrice(string[] strD, int price)
	{
		double amount = price;
		foreach (string s in strD)
			discounts.Add(new Discount(s));

		discounts.Sort(delegate(Discount d1, Discount d2)
		{
			if (d1.percent == d2.percent)
				return d1.price - d2.price;
			else
				return d2.percent - d1.percent;
		});

		int gAmount = 0;
		foreach (Discount d in discounts)
		{
			double diff = amount * d.percent / 100;
			if (d.price < diff)
			{
				gAmount += d.price;
				amount -= diff;
			}

		}

		return amount + gAmount;



	}
}
