#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        result.push_back(-1);
        result.push_back(-1);
        unordered_map<int, vector<int>> index;
        for (int i = 0; i != nums.size(); ++i) {
            unordered_map<int, vector<int>>::iterator it;
            it = index.find(nums[i]);
            if (it != index.end()) {
                it->second.push_back(i+1);
            } else {
                vector<int> temp;
                temp.push_back(i+1);
                index.insert({nums[i], temp});
            }
        }
        for (int i = 0; i != nums.size(); ++i) {
            unordered_map<int, vector<int>>::iterator it;
            int f = target - nums[i];
            it = index.find(f);
            if (it != index.end()) {
                if (it->first == nums[i] && it->second.size() > 1) {
                    result[0] = i+1;
                    result[1] = it->second[1];
                    break;
                } else if(it->first != nums[i]){
                    result[0] = i+1;
                    result[1] = it->second[0];
                    break;
                }
            }
        }
        return result;
    }
};
