class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int maxLen = 0;
        unordered_set<char> charSet;

        while (r < s.size()) {
            while (charSet.find(s[r]) != charSet.end()) {
                charSet.erase(s[l]);
                l++;
            } 
            charSet.insert(s[r]);
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};

