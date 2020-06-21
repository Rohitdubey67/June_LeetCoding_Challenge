/*
Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)

Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)

 

Example 1:

Input: "banana"
Output: "ana"
Example 2:

Input: "abcd"
Output: ""
 

Note:

2 <= S.length <= 10^5
S consists of lowercase English letters.
*/

class Solution {
public:
     int prime = 19260817;
    string res;
    vector<int> power;
    string longestDupSubstring(string s) {
        res = "";
        power = vector<int>(s.length(), 1);
        int i;
        for (i = 1 ; i < s.length(); i++) {
            power[i] = (power[i - 1] * 26) % prime;
        }
        int low = 0, high = s.length();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            string tmp = val(mid, s);
            if (tmp.length() == 0) {
                high = mid - 1;
            } else {
                if (tmp.length() > res.length()) {
                    res = tmp;
                }
                low = mid + 1;
            }
        }
        return res;
    }
    string val(int desire, string &str) {
        if (desire == 0) return "";
        unordered_map<int, vector<int>> hash = unordered_map<int, vector<int>>();
        long long current = 0;
        int i;
        for (i = 0 ; i < desire; i++) {
            current = ((current * 26) % prime + (str[i] - 'a')) % prime;
        }
        hash[current] = vector<int>(1, 0);
        for (i = desire ; i < str.length(); i++) {
            current = ((current - (long long) power[desire - 1] * (str[i - desire] - 'a')) % prime + prime) % prime;
            current = (current * 26 + (str[i] - 'a')) % prime;
            if (hash.find(current) == hash.end()) {
                hash[current] = vector<int>(1, i - desire + 1);
            } else {
                for (auto it : hash[current]) {
                    
                    if (strcmp((str.substr(it, desire)).data(), str.substr(i - desire + 1, desire).data()) == 0) {
                        return str.substr(it, desire);
                    }
                }
                
                hash[current].push_back(i - desire + 1);
            }
        }
        
        return "";
    }
};
