/*
Problem Statement
    	
A sequence of distinct integers is called wild if it has the following properties:

It never increases twice in a row.
It never decreases twice in a row.
For example, {4, 7, 3, 9, 1, 5, 2} is a wild sequence but {4, 7, 3, 6, 9, 1, 5, 2} is not, 
as it increases twice in a row: from 3 to 6 and then from 6 to 9.

You are given the int head and the int[] rest. Construct any wild sequence that begins with head and continues with the elements of rest, 
in an order of your choice. You must use each element of rest exactly once and you cannot use any other numbers in your sequence. 
Return the answer as a int[]. Any valid wild sequence will be accepted. If there is no valid wild sequence, return an empty int[] instead.

 
Definition
    	
Class:	WildSequence
Method:	construct
Parameters:	int, int[]
Returns:	int[]
Method signature:	int[] construct(int head, int[] rest)
(be sure your method is public)
    
 
Constraints
-	head will be between 0 and 10^6, inclusive.
-	rest will contain between 0 and 49 elements, inclusive.
-	Each element of rest will be between 0 and 10^6, inclusive.
-	The elements of rest will be distinct.
-	head will be distinct from all elements of rest.
 
Examples
0)	    	
20
{10, 30}
Returns: {20, 10, 30 }
Both {20, 10, 30} and {20, 30, 10} are correct answers. You may return either of them.

1)	   	
20
{10, 30, 40}
Returns: {20, 10, 40, 30 }
This time, there are three correct answers: {20, 10, 40, 30}, {20, 30, 10, 40}, and {20, 40, 10, 30}. 
You may return any one of these sequences.

2)    	
4
{1, 2, 3, 6, 7, 5}
Returns: {4, 7, 5, 6, 1, 3, 2 }

*/

#include <vector>
#include <algorithm>
using namespace std;

struct WildSequence {
     vector <int> construct(int head, vector <int> rest) {         
         vector<int> result;
         result.push_back(head);      
                     
         sort(rest.begin(), rest.end());
         auto left = rest.begin();
         auto right = rest.rbegin();
         bool use_left = rest.empty() || (head > *left);
                 
         for (int i = 0; i < rest.size(); i++) {
             if (use_left)
             	 result.push_back(*left++);
             else
                 result.push_back(*right++);                 
             use_left = !use_left;
         }
         return result;
     }
};
