/*
You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

 

Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10] 
Output: 1
*/

/*
Time: O(N*M)
Space: O(N*M) we can reduce it to O(N) 
Concept used: DP (unbounded Knapsack)
*/

int change(int a, vector<int>& c) {
        int n=c.size(),i,j;
        int t[n+1][a+1];
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=a;j++)
            {
                if(j==0)
                    t[i][j]=1;
                else if(i==0)
                    t[i][j]=0;
                else if(c[i-1]<=j)
                {
                    t[i][j]=t[i-1][j]+t[i][j-c[i-1]];
                }
                else
                    t[i][j]=t[i-1][j];
            }
        }
        return t[n][a];
    }
    
