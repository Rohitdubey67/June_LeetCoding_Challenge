/*
There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.

 

Example 1:

Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
*/

/*
Time: O(NlogN)
space: O(1)
concept: greedy sorting
*/

 int twoCitySchedCost(vector<vector<int>>& a) {
     // sort the element on the basis of diff b/w cost of a and b.
        sort(a.begin(),a.end(),[](vector<int> &x, vector<int> &y)
       {
         return x[0]-x[1]<y[0]-y[1];
       });
       int n=a.size();
       int profit=0; 
       for(int i=0;i<n;i++)
      {
          if(i<n/2)
          profit+=a[i][0];
          else
          profit+=a[i][1];
      }
     return profit;
    }
    
