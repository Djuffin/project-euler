/*
  	
There is a very simple way to draw mazes using ASCII characters. One sample maze with three entrances is shown below. (The '#'s represent walls, the '.'s represent empty cells.)

#######.#####
......#.#...#
#.###.#.#.#.#
#.#.......#.#
#.#######.#.#
#.......#.#.#
#########.###
Here is the construction of such a maze in more detail. Let's take a look at an unfinished maze that has walls everywhere.

#############
#.#.#.#.#.#.#
#############
#.#.#.#.#.#.#
#############
#.#.#.#.#.#.#
#############
Rows and columns of the bitmap are numbered starting from 0 in the top left corner. Notice that the cells with both coordinates odd are still empty. 
These cells are called rooms. The cells that share a side with a room are called hallways and the remaining cells are called pillars. 
Hence, pillars have both coordinates even. Pillars will always be walls. Some hallways will eventually be empty while others will be walls.

You are given ints R, C, and X. Your task is to design any maze with R rows and C columns of rooms (that is, 2R+1 rows of characters, each containing 2C+1 characters). 
The maze must have the following additional properties:

Each room must be reachable from each other room, without leaving the maze.
There have to be exactly X exits (i.e., empty hallways on the boundary of the maze).
The total number of wall cells ('#' characters) must be maximized.
Return a String[] with the resulting maze. Any valid answer will be accepted.

 
Definition
    	
Class:	FillInTheMaze
Method:	filled
Parameters:	int, int, int
Returns:	String[]
Method signature:	String[] filled(int R, int C, int X)
(be sure your method is public)
    
 
Constraints
-	R will be between 1 and 24, inclusive.
-	C will be between 1 and 24, inclusive.
-	X will be between 1 and 2R+2C, inclusive.
 
Examples
0)	
    	
3
6
3
Returns: 
{"#######.#####",
"......#.#...#",
"#.###.#.#.#.#",
"#.#.......#.#",
"#.#######.#.#",
"#.......#.#.#",
"#########.###" }
These dimensions correspond to the examples in the problem statement. The maze shown in the statement is indeed one of the optimal solutions.
1)	
    	
1
3
2
Returns: {"#######", ".......", "#######" }
A very simple maze with just one row of rooms and with two exits.
2)	
    	
2
2
8
Returns: {"#.#.#", ".....", "#.###", ".....", "#.#.#" }
The returned maze:
#.#.#
.....
#.###
.....
#.#.#
Notice the one hallway that remained a wall. An answer without that wall would not be accepted, 
as the number of '#'s would not be as large as possible.
*/

#include <vector>
#include <string>
using namespace std;

struct FillInTheMaze {
    vector<string> filled(int R, int C, int X) {
        string outer_wall(2 * C + 1, '#');
        string inner_wall = string("#.") + string(2 * C - 1, '#');
        string inner_pass = string("#") + string(2 * C - 1, '.') + string("#");
        vector<string> result;
        
        result.push_back(outer_wall);
        result.push_back(inner_pass);
        for (int i = 1; i < R; i++) {
            result.push_back(inner_wall);
            result.push_back(inner_pass);
        }
        result.push_back(outer_wall);
        
        int cnt = 0;
        for (;cnt < X && cnt < 2 * R; cnt++) {
            if (cnt % 2 == 0)
                result[cnt + 1][0] = '.';
            else 
                result[cnt][2 * C] = '.';            
        }
        X -= cnt;
        cnt = 0;
        for (;cnt < X; cnt++) {
            if (cnt % 2 == 0)
                result[0][cnt + 1] = '.';
            else 
                result[2 * R][cnt] = '.';            
        }
        return result;
    }
};