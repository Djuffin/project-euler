/*
Problem Statement
    	
The number 31143310 is self-describing because we can read it as the statement "this number contains three '1's, one '4's, three '3's, and one '0'", 
and that statement correctly describes the whole number.

More formally, a number is called self-describing if it satisfies the following:

It has an even number of digits. Below, we will label the individual digits a[0], b[0], a[1], b[1], ... from the left to the right.
The digits b[i] are all distinct.
For each valid i, the number contains exactly a[i] copies of the digit b[i].
The number does not contain any other digits, except for those described by the statements mentioned above.
You are given the int[] digits. Find the smallest self-describing number N such that the digits that appear in N are precisely the digits in digits. 
If such a number exists, return a String with its decimal representation. Otherwise, return an empty String

 
Definition
    	
Class:	SelfDescFind
Method:	construct
Parameters:	int[]
Returns:	String
Method signature:	String construct(int[] digits)
(be sure your method is public)
    
 
Notes
-	Watch out for integer overflow.
 
Constraints
-	digits will contain between 1 and 10 elements, inclusive.
-	Each element of digits will be between 0 and 9, inclusive.
-	The elements of digits will form a strictly increasing sequence.
 
Examples
0)	    	
{1}
Returns: ""

1)	    	
{2}
Returns: "22"
The smallest self-describing number is 22. It contains two '2's, and it says about itself that it contains two '2's.

2)    	
{0,1,3,4}
Returns: "10143133"

3)	    	
{0,1,2,4,5,6,8,9}
Returns: ""

4)	   	
{0,1,2,3,5,6,8,9}
Returns: "1016181923253251"

5)	
   	
{4}
Returns: ""
Note that 4444 is not a valid self-describing number.

*/

#include <algorithm>
#include <vector>
#include <string>
#include <cstdint>
#include <strings.h>
using namespace std;

struct SelfDescFind {
    
    long long minimize_and_render(vector<int> &v) {
        long long result = 0;        
        vector<int> buf(v.size());
        
        for(int i = 0; i < v.size(); i += 2) {
            buf.push_back(v[i] * 10 + v[i + 1]);
        }
        
        sort(buf.begin(), buf.end());
        
        for (int n : buf)
            result = 100 * result + n;
        
        return result;
    }
    
    bool is_self_describing (vector<int> &v) {
        int count[10] = {};
        for (int i : v)
            count[i]++;
        for (int i = 0; i < v.size(); i += 2) {
            if (count[v[i + 1]] != v[i])
                return false;
        }
        return true;        
    }
    
    bool inc(vector<int> &next, vector<int> &num) {
        bool overflow = true;        
        for (int i = 0; i < num.size(); i += 2) {
            int d = next[num[i]];
            if (d != 0) {
                num[i] = d;
                overflow = false;
                break;
            } else {
                num[i] = next[0];
            }
        }
        return !overflow;
    }
    
    string construct(vector<int> digits) {
        long long min = 0;
        vector<int> num;
        vector<int> next(10);
        next[0] = digits[0];
        for (int i = 0; i < digits.size(); i++) {
            num.push_back(next[0]);
            num.push_back(digits[i]);
        	if (i > 0) 
                next[digits[i - 1]] = digits[i];
        }
        
        do {
            if (is_self_describing(num)) {
                long long value = minimize_and_render(num);
                if (min == 0 || value < min)
                    min = value;
            }               
        } while(inc(next, num));
        
       if (min != 0)
           return to_string(min);
        return {};        
    }
};