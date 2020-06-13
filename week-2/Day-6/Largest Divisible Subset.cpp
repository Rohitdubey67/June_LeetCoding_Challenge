/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]
*/

/*
Time Complexity:O(n^2)
Space Complexity:O(n)
Concept Used: similar to LIS(longest increasing subsequance)
*/

vector<int> largestDivisibleSubset(vector<int>& a) {
        int n=a.size(),i,j,k,m=0,id=-1;
         vector<int>ans;
        if(n==0)
            return ans;
        int s[n];
        int p[n];
        sort(a.begin(),a.end());
        for(i=0;i<n;i++)
        {
            s[i]=1;
            p[i]=-1;
            k=0;
            for(j=i-1;j>=0;j--)
            {
              if(a[i]%a[j]==0)
              {
                 if(s[j]+1>s[i])
                 {
                    s[i]=s[j]+1;
                     p[i]=j;
                     
                 }
              }
            }
            if(s[i]>m)
            {
                id=i;
                m=s[i];
            }
        }
        while(id!=-1)
        {
            ans.push_back(a[id]);
            id=p[id];
        }
        return ans;
    }
    
