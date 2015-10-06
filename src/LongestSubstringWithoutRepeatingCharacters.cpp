#include <vector>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        if (s.size() == 1) {
            return 1;
        }
        unordered_map<char, int> map;
        unordered_map<char, int>::iterator find;
        int max(0), length(0), index(0);
        for (int i = 0; i < s.size(); ++i) {
            char search = s[i];
            find = map.find(search);
            if (find != map.end()) {
                if (find->second >= index) {
                    length = i - index;
                    if (max < length) {
                        max = length;
                    }
                    index = find->second+1;
                }
                find->second = i;

            } else {
                map.insert({s[i], i});
            }
        }
        length = s.size() - index;
        if (max < length) {
            max = length;
        }
        return max;
    }
};

