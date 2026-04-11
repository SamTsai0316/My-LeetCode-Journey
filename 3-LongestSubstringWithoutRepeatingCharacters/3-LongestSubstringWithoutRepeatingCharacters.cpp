// Last updated: 2026/4/11 下午7:21:16
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, curLen = 0, maxLen = 0;
        int n = s.length();
        unordered_map<char, int> charMap;

        while (j < n) {
            charMap[s[j]]++;
            curLen++;

            // 如果有重複字元（出現次數 > 1）
            while (charMap[s[j]] > 1) {
                charMap[s[i]]--;
                i++;
                curLen--;
            }

            maxLen = max(maxLen, curLen);
            j++;
        }

        return maxLen;
    }
};
