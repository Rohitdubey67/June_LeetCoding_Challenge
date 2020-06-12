/*
Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();
*/

/*
Time Complexity: O(n) for overall and O(1) for all operation
space: O(n) for overall and O(1) for all operation
Concept Used: using map(hash map) and extra array
*/

/*

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int>m;
    vector<int>v;
    int s;
    RandomizedSet() {
        s=0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val)==m.end())
        {
            m[val]=s;
            v.push_back(val);
            s++;
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val)!=m.end())
        {
            swap(v[m[val]],v[s-1]);
            int k=m[val];
            v.pop_back();
            s--;
            m[v[k]]=k;
            m.erase(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r=rand()%s;
        return v[r];
    }
};
