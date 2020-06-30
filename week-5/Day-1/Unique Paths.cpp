/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28

*/

/*
Time Complexity: O(N*M)
Space Complexity: O(N*M)
Concept used: grid dp
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int i,j;
        int t[m][n];
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==0||j==0)
                t[i][j]=1;
                else
                    t[i][j]=t[i-1][j]+t[i][j-1];
            }
        }
        return t[m-1][n-1];
    }
};
