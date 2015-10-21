#include <vector>

using std::vector;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1) {
            return 0;
        }
        int count(0), temp;
        int i(0);
        int j = (int) height.size() - 1 ;
        int left(height[i]), right(height[j]);
        int len = j-i;
        count = min(left, right) * len;
        while (i+1 != j) {
            if (left <= right) {
                ++i;
                if (left < height[i]) {
                    left = height[i];
                    len = j-i;
                }
            } else {
                --j;
                if (right < height[j]) {
                    right = height[j];
                    len = j-i;
                }
            }
            temp = min(left, right) * len;
            count = max(count, temp);
        }
        return count;
    }
private:
    int min(int i, int j){
        return i<=j? i:j;
    }
    int max(int i, int j){
        return i>=j? i:j;
    }
};
