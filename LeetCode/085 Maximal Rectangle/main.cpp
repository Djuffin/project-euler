// maxrect.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#include "ilduganov.cpp";

int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<char> > matrix;
	string str;

	str = "0110111111111111110"; matrix.push_back(vector<char>(str.begin(), str.end()));
	str = "1011111111111111111"; matrix.push_back(vector<char>(str.begin(), str.end()));
	str = "1101111111110111111"; matrix.push_back(vector<char>(str.begin(), str.end()));
	str = "1111111111111011111"; matrix.push_back(vector<char>(str.begin(), str.end()));
	str = "1111111111111101111"; matrix.push_back(vector<char>(str.begin(), str.end()));
	str = "1110111011111111101"; matrix.push_back(vector<char>(str.begin(), str.end()));
	str = "1011111111111101111"; matrix.push_back(vector<char>(str.begin(), str.end()));
	str = "1111111111111110110"; matrix.push_back(vector<char>(str.begin(), str.end()));
	str = "0011111111111110111"; matrix.push_back(vector<char>(str.begin(), str.end()));
	str = "1101111111011111111"; matrix.push_back(vector<char>(str.begin(), str.end()));
	str = "1111111110111111111"; matrix.push_back(vector<char>(str.begin(), str.end()));
	str = "0110111011111111111"; matrix.push_back(vector<char>(str.begin(), str.end()));
	str = "1111011111111101111"; matrix.push_back(vector<char>(str.begin(), str.end()));
	str = "1111111111111111111"; matrix.push_back(vector<char>(str.begin(), str.end()));
	str = "1111111111111111111"; matrix.push_back(vector<char>(str.begin(), str.end()));
	str = "1111111111111111101"; matrix.push_back(vector<char>(str.begin(), str.end()));
	str = "1111111101101101111"; matrix.push_back(vector<char>(str.begin(), str.end()));
	str = "1111110111111110111"; matrix.push_back(vector<char>(str.begin(), str.end()));

	Solution s;
	int area = s.maximalRectangle(matrix);
	cout << "area = " << area << endl;
	return 0;
}
