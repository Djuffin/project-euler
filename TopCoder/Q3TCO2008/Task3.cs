using System;
using System.Collections.Generic;
using System.Text;

public class PokerSquare
{
	
	private class Card
	{
		public char suit;
		public char value;
		public Card() { }
		public Card(string p)
		{
			suit = p[1];
			value = p[0];
		}

		public override string ToString()
		{
			return value.ToString() + suit.ToString();
		}

	}

	private Card[,] gameBoard = new Card[5, 5];

	private Card[,] copyOfGameBoard = new Card[5,5];
	private Card[,] CopyGameBoard()
	{
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				copyOfGameBoard[i, j] = gameBoard[i, j];
		return copyOfGameBoard;
	}


	private int GetIntValue(char value)
	{
		if (char.IsDigit(value)) return int.Parse(value.ToString());
		switch (value)
		{
			case 'T': return 10;
			case 'J': return 11;
			case 'Q': return 12;
			case 'K': return 13;
			case 'A': return 14;
		}
		throw new Exception();

	}

	private int MeasureHand(Card[] cards)
	{
		if (cards.Length != 5)
			throw new Exception();

		Array.Sort(cards, delegate(Card left, Card right)
		{
			return GetIntValue(left.value) - GetIntValue(right.value);
		});

		if(IsRoyalFlush(cards))
			return 100;
		if (IsStraightFlush(cards))
			return 75;
		if (IsFour(cards))
			return 50;
		if (IsFullHouse(cards))
			return 25;
		if (IsFlush(cards))
			return 20;
		if (IsStraight(cards))
			return 15;
		if (IsThree(cards))
			return 10;
		if (IsTwoPair(cards))
			return 5;
		if (IsPair(cards))
			return 2;

		return 0;
	}

	private bool IsRoyalFlush(Card[] cards)
	{
		return IsStraightFlush(cards) && cards[4].value == 'A';
	}

	private bool IsStraightFlush(Card[] cards)
	{
		return IsFlush(cards) && IsStraight(cards);
	}

	private bool IsFour(Card[] cards)
	{
		if (cards[0].value == cards[1].value && cards[0].value == cards[2].value && cards[0].value == cards[3].value) return true;
		if (cards[2].value == cards[3].value && cards[2].value == cards[4].value && cards[2].value == cards[1].value) return true;
		return false;		
	}

	private bool IsFullHouse(Card[] cards)
	{
		if (cards[0].value != cards[1].value) return false;
		if (cards[3].value != cards[4].value) return false;
		return (cards[2].value == cards[0].value) || (cards[2].value == cards[4].value);
	}

	private bool IsFlush(Card[] cards)
	{
		for (int i = 1; i < 5; i++)
			if (cards[i].suit != cards[0].suit) return false;
		return true;
	}

	private bool IsStraight(Card[] cards)
	{
		for (int i = 1; i < 5; i++)
			if (GetIntValue(cards[i].value) - 1 != GetIntValue(cards[i - 1].value)) return false;

		return true;
	}

	private bool IsThree(Card[] cards)
	{
		for (int i = 2; i < 5; i++)
			if (cards[i].value == cards[i - 1].value && cards[i].value == cards[i - 2].value) return true;
		return false;
	}

	private bool IsTwoPair(Card[] cards)
	{
		bool onePair = false;

		for (int i = 1; i < 5; i++)
			if (cards[i].value == cards[i - 1].value)
			{
				if (onePair) 
					return true;
				else onePair = true;
				i++;
			}

		return false;
	}

	private bool IsPair(Card[] cards)
	{
		for (int i = 1; i < 5; i++)
			if (cards[i].value == cards[i - 1].value)
				return true;
		return false;

	}

	private void GetPermutation(List<Card> permutation, List<Card> source)
	{
		for (int i = 0; i < source.Count; i++)
		{
			Card c = source[i];
			permutation.Add(c);
			source.RemoveAt(i);

			if (source.Count == 0)
				TryPermutation(permutation);
			else
				GetPermutation(permutation, source);

			source.Insert(i, c);
			permutation.RemoveAt(permutation.Count - 1);
		}
	}


	private int bestScoreResult = 0;
	public int bestScore(string[] board, string[] remaining)
	{
		ParseBoard(board);
		Card[] remainCards = ParseLine(string.Join(" ", remaining));

		GetPermutation(new List<Card>(), new List<Card>(remainCards));


		return bestScoreResult;
	}

	int count = 0;
	private void TryPermutation(List<Card> cards)
	{
		count++;
		Card[,] board = CopyGameBoard();

		int fillIndex = 0;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
			{
				if (board[i, j] == null)
					board[i, j] = cards[fillIndex++];
			}

		int result = 0;
		for (int i = 0; i < 5; i++)
		{
			Card[] row = new Card[5];
			Card[] col = new Card[5];
			for (int j = 0; j < 5; j++)
			{
				row[j] = board[i, j];
				col[j] = board[j, i];
			}
			result += MeasureHand(row) + MeasureHand(col);
		}

		//WriteBoard(board, result);

		bestScoreResult = Math.Max(result, bestScoreResult);
	}

	private void WriteBoard(Card[,] board, int score)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				Console.Write("{0} ", board[i, j]);
			}
			Console.WriteLine();
		}
		Console.WriteLine("Score: {0}", score);
		Console.WriteLine();
	}

	private void ParseBoard(string[] board)
	{
		for (int i = 0; i < 5; i++)
		{
			Card[] line = ParseLine(board[i]);
			for (int j = 0; j < 5; j++)
				gameBoard[i, j] = line[j];
		}
	}

	private Card[] ParseLine(string line)
	{
		string[] ps = line.Split(' ');
		return Array.ConvertAll<string, Card>(ps, delegate(String p)
		{
			if (p == "--") return null;
			return new Card(p);
		});

	}

}
