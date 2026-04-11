// Last updated: 2026/4/11 下午7:20:25
class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        vector<string> words;
        string word;

        while (iss >> word) {
            words.push_back(word);
        }

        int left = 0, right = words.size() - 1;
        while (left < right) {
            swap(words[left], words[right]);
            left++;
            right--;
        }

        string result;
        for (const string& w : words) {
            if (!result.empty()) {
                result += " ";
            }
            result += w;
        }

        return result;
    }
};