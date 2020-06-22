/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/

/*
Time Complexity: O(N*32)==O(N)
Space Complexity: O(1)
Concept Uesd: Bit masking
*/

 int singleNumber(vector<int>& a) {
        int k=0,i;
        for(i=0;i<32;i++)
        {
            int s=0;
            int m=1<<i;
            for(int j=0;j<a.size();j++)
            {
                if(a[j] & m )
                    s++;
            }
            if(s%3!=0)
                k=k|m;
        }
        return k;
    }
    
