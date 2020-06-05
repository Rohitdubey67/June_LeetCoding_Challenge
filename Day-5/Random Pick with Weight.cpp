/*
Given an array w of positive integers, where w[i] describes the weight of index i.
write a function pickIndex which randomly picks an index in proportion to its weight.

Note:

1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.
Example 1:

Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]
Example 2:

Input: 
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, 
the array w. pickIndex has no arguments. Arguments are always wrapped with a list, even if there aren't any.
*/

/*
Time: O(n) 
space : O(n)
concept: prefix sum and binary search
*/

  vector<int>a;
    Solution(vector<int>& w) {
        int k=0;
        for(int i=0;i<w.size();i++)
        {
            k+=w[i];
            a.push_back(k);
        }
    }
    
    int pickIndex() {
        int n=a.back();
        int r=rand()%n;
        return upper_bound(a.begin(),a.end(),r)-a.begin();
    }
    
