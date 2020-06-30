/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

 
Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

/*
Time: O(NlogN)
Space: O(1)
Concept Used: sort in assending order and insert
*/

vector<vector<int>> reconstructQueue(vector<vector<int>>& p) 
{
        sort(p.begin(),p.end(),[](vector<int>a,vector<int>b)
             {
                 if(a[0]!=b[0])
                     return a[0]>b[0];
                 else
                     return a[1]<=b[1];
             });
        vector<vector<int>> res;
        for (auto it : p)
        {
        res.insert(res.begin()+it[1], it);
        }
        return res;
    }
    
