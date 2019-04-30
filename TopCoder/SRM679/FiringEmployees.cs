/*
Problem Statement
    	BottomCoder has a CEO and N employees. The CEO has number 0, the employees are numbered 1 through N. Each employee can be described by three numbers: their salary, their productivity, and the number of their direct manager. For each employee E, employee E's manager has a number smaller than E. Hence, the company has a tree-like hierarchy. 

You are given the description of BottomCoder in the int[]s manager, salary, and productivity. For each i between 1 and N, inclusive, employee i is described by the values manager[i-1], salary[i-1], and productivity[i-1]. 

The profit from an employee can be computed as the employee's productivity minus their salary. Note that the profit from an employee can be negative. The total profit of the company is the sum of profits of its employees. 

The CEO would like to increase the total profit of the company by firing some of its employees. However, if he fires an employee E, he must also fire all employees who reported to E. For example, if he fires your manager, he must fire you as well. As another example, if he fires the manager of your manager, he must fire your manager and therefore he must also fire you. 

Find a valid way of firing some (possibly none, possibly all) employees that maximizes the profit of the resulting company. Return the total profit after the selected employees are fired.
 
Definition
    	
Class:	FiringEmployees
Method:	fire
Parameters:	int[], int[], int[]
Returns:	int
Method signature:	int fire(int[] manager, int[] salary, int[] productivity)
(be sure your method is public)
    
 
Notes
-	The CEO of BottomCoder has both salary and productivity equal to zero. The CEO cannot be fired.
 
Constraints
-	manager, salary and productivity will contain N elements each.
-	manager will contain between 1 and 2500 elements inclusive.
-	Each element of salary will be between 1 and 10,000 inclusive.
-	Each element of productivity will be between 1 and 10,000 inclusive.
-	The i-th element of manager will be between 0 and i inclusive.
 
Examples
0)	
    	
{0,0,0}
{1,2,3}
{3,2,1}
Returns: 2
The CEO has three direct employees.

The first one has a salary of 1 and a productivity of 3.

The second one has a salary of 2 and a productivity of 2.

The third one has a salary of 3 and a productivity of 1.

The CEO should fire employee 3.

The CEO can also fire employee 2, but it does not matter: here, firing is equally good as keeping.
1)	
    	
{0,1,2,3}
{4,3,2,1}
{2,3,4,5}
Returns: 4
Employee 1 has a negative profit: 2-4 = (-2).

The other three employees have nonnegative profits: 0, 2, and 4. 



It would seem that the CEO should fire employee 1.

However, if he does that, he would have to fire all four employees, because 1 is (either directly or indirectly) the manager of each of them.

This would leave the CEO with an empty company that has profit 0. 



The optimal strategy is not to fire anyone.

The total profit in this case will be (-2) + 0 + 2 + 4 = 4.
2)	
    	
{0,1}
{1,10}
{5,5}
Returns: 4
In this case the best choice is to fire employee number 2 and keep employee number 1.
3)	
    	
{0,1,2,1,2,3,4,2,3}
{5,3,6,8,4,2,4,6,7}
{2,5,7,8,5,3,5,7,9}
Returns: 6
4)	
    	
{0,0,1,1,2,2}
{1,1,1,2,2,2}
{2,2,2,1,1,1}
Returns: 3

This problem was used for: 
       Single Round Match 679 Round 1 - Division I, Level One
*/

using System.Linq;
class Employee
{
    public int profit = 0;
    public Employee manager = null;
}    

class FiringEmployees 
{
     public int fire(int[] manager, int[] salary, int[] productivity) 
     {         
         var ceo = new Employee();         
         int N = manager.Length;
         var employees = new Employee[N + 1];
         employees[0] = ceo;
         
         for (int i = 0; i < N; i++) 
         {
             var e = new Employee();
             e.profit = productivity[i] - salary[i];
             e.manager = employees[manager[i]];
             employees[i + 1] = e;
         }
         
         foreach (var e in employees.Reverse()) 
         {
             if (e.manager != null && e.profit > 0)
         	 	e.manager.profit += e.profit;
         }       
         return ceo.profit;
     }
}    