/*
PAndPuns

Kaede loves puns. You want to please her by telling her a pun.

Given the String text, you should return the String "pun" (quotes for clarity) if text is a pun. 
Otherwise, return "not a pun".

For the purpose of this problem, text is a pun if there exists some string S of length two or 
more that has two non-overlapping occurrences in text. 
(Each occurrence must be a contiguous substring of text, you may not skip letters.)

 
Definition
    	
Class:	PAndPuns
Method:	check
Parameters:	String
Returns:	String
Method signature:	String check(String text)
(be sure your method is public)
    
 
Constraints
-	Length of text will be between 4 and 2,500, inclusive.
-	text will consist of lowercase English letters only ('a'-'z').
 
Examples
0)	  	
"aaaa" 
Returns: "pun"
This is a pun because we can find two non-overlapping occurrences of the substring "aa".

1)	    	
"aaab" 
Returns: "not a pun"
This is not a pun. Note that the two occurrences of "aa" in "aaab" overlap.

2)	    	
"pandpuns" 
Returns: "not a pun"
"pan" and "pun" are similar but differ.

3)	    	
"producerandproduction" 
Returns: "pun"    
*/

#include <string>
#include <unordered_map>
using namespace std;

struct PAndPuns {
    string check(string text) {
        unordered_map<string, int> s;
        
        for (int i = 0; i < text.size() - 1; i++) {
            auto ip = s.insert({text.substr(i, 2), i});
            if (!ip.second) {
                if (i - ip.first->second > 1)
                	return "pun";
            }
        }
        
        return "not a pun";
    }
};