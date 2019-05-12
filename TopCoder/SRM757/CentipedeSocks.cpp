/*
You have C pet centipedes. You want to take them out for a walk, but it's quite cold. 
You want to give them socks to make them feel more comfortable.

Each of your centipedes has F feet. You have a large bin with centipede socks. 
The socks come in different colors, but your centipedes are quite picky and 
each of them requires to wear F socks of the same color.

You are given the s C and F. You are also given the sockCounts. 
Each element of sockCounts is the number of socks of one particular 
color you have in the bin.

Find and return the smallest X such that if you take any X socks 
out of the bin, it is guaranteed that you will be able to use some of 
them to keep all feet of all your centipedes warm. 
If there is no such X, return -1 instead.

Definition
Class: CentipedeSocks
Method: fewestSocks
Parameters: int, int, vector <int>
Returns: int
Method signature: int fewestSocks(int C, int F, vector <int> sockCounts)
(be sure your method is public)
Limits
Time limit (s): 2.000
Memory limit (MB): 256
Constraints
- C will be between 1 and 50, inclusive.
- F will be between 1 and 100, inclusive.
- sockCounts will have between 1 and 100 elements, inclusive.
- Each element of sockCounts will be between 1 and 10^7, inclusive.
Examples
0)
1
100
{1, 1, 1, 1, 100}
Returns: 104
One centipede with 100 feet. If you are really unlucky, you need to 
remove all 104 socks from the bin until you get all 100 pink ones.

1)
1
100
{40, 50, 60, 70}
Returns: -1
You do not have 100 socks of any single color, so the poor centipede will be cold.

2)
3
10
{12345}
Returns: 30
There are 12345 red socks in the bin. You just grab the first 
30 and put 10 of them onto each of your centipedes.

3)
2
3
{4, 4, 5}
Returns: 10
Two red, two blue, and five pink socks are still not enough to satisfy two three-legged centipedes
*/

#include <queue>
#include <vector>
using namespace std;

struct Color {
    int used;
    int left;
};

struct CentipedeSocks {
int fewestSocks(int C, int F, vector <int> sockCounts) {
    int socksLeft = 0;
    int socksUsed = 0;
    auto comp_used =
        [](const Color& lhs, const Color& rhs) 
        { 
        	if (lhs.used == rhs.used)
                return lhs.left < rhs.left;
        	return lhs.used > rhs.used; 
   		};
    priority_queue<Color, vector<Color>, decltype(comp_used)> queue(comp_used);
    
    for (int s : sockCounts) {
        queue.push({0, s});
        socksLeft += s;
    }
    
    while(socksLeft > 0 && C > 0 && !queue.empty()) {
        Color color = queue.top();
        queue.pop();
        color.used++;
        color.left--;
        socksUsed++;
        if (color.used == F) {
            C--;
            color.used = 0;
        }
        if (color.left > 0) {
            queue.push(color);
        }           
    }
        
    return C > 0 ? -1 : socksUsed;
    
}
};