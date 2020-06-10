/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.
*/

/*
Time Complexity: O(logN)
Space Complexity: O(1)
Concept Used: Binary search
*/

int searchInsert(vector<int>& a, int t) {
        
// i= lower_bound(a.begin(),a.end(),t)-a.begin();
        int i,j;
        i=0;j=a.size()-1;
        while(i<=j)
        {
            int m=(i+j)/2;
            if(a[m]==t)
                return m;
            else if(a[m]<t)
                i=m+1;
            else
                j=m-1;
        }
        return i;
    }
    
    
   
