/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'.
Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are 
connected if they are adjacent cells connected horizontally or vertically.
*/

 /*
 Time Complexity: O(N*M)
 Space Complexity: O(N*M)
 Concept Used: dfs
 */
 
 void dfs(vector<vector<char>>& a,int i,int j)
    {
        if(i<0||j<0||i>=a.size()||j>=a[0].size()||a[i][j]!='O')
            return;
        a[i][j]='1';
        dfs(a,i+1,j);
        dfs(a,i,j+1);
        dfs(a,i-1,j);
        dfs(a,i,j-1);
    }
    void solve(vector<vector<char>>& a) {
        int n=a.size(),i,j;
        if(n==0)
            return;
        int m=a[0].size();
        for(i=0;i<n;i++)
        {
            dfs(a,i,0);
            dfs(a,i,m-1);
        }
         for(i=1;i<m-1;i++)
        {
            dfs(a,0,i);
            dfs(a,n-1,i);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
               if(a[i][j]=='1')
                   a[i][j]='O';
                else if(a[i][j]=='O')
                    a[i][j]='X';
            }
        }
    }
    
