#include <iostream>
#include <vector>
#include <sstream>

using std::vector;
using std::string;
using std::stringstream;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1, size2;
        size1 = nums1.size();
        size2 = nums2.size();
        
        if ((size1+size2) == 0) {
            return 0;
        }
        if ((size1+size2) == 1 && size1 ==1) {
            return nums1[0];
        }
        if ((size1+size2) == 1 && size2 == 1) {
            return nums2[0];
        }
        
        int mid = size1 + size2;
        if (mid%2 == 0) {
            int term1, term2;
            term1 = (mid - 1) / 2;
            term2= mid / 2;
            vector<int> n1, n2;
            for (size_t i = 0; i != nums1.size(); ++i){
                n1.push_back(nums1[i]);
            }
            for (size_t i = 0; i != nums2.size(); ++i){
                n2.push_back(nums2[i]);
            }
            return (find(nums1, nums2, term1) + find(n1, n2, term2))/2;
            
        } else {
            return find(nums1, nums2, mid/2);
        }
        
    }
    
    double find(vector<int>& nums1, vector<int>&nums2, int mid){
        int size1, size2;
        size1 = nums1.size();
        size2 = nums2.size();
        
        if (size1 == 0) {
            return nums2[mid];
        }
        if (size2 == 0) {
            return nums1[mid];
        }
        
        int mid1, mid2;
        
        mid1 = size1 / 2;
        mid2 = size2 / 2;
        
        if (nums1[mid1] <= nums2[0] && mid <= mid1) {
            return nums1[mid];
        } else if (nums1[mid1] <= nums2[0] && mid > mid1) {
            nums1.erase(nums1.begin(), nums1.begin()+mid1+1);
            return find(nums1, nums2, mid-mid1-1);
        }
        if (nums1[mid1] >= nums2[size2-1] && mid >= mid1+size2) {
            return nums1[mid-size2];
        } else if (nums1[mid] >= nums2[size2-1] && mid < mid1+size2) {
            nums1.erase(nums1.begin()+mid1);
            return find(nums1, nums2, mid);
        }
        if (nums2[mid2] <= nums1[0] && mid <= mid2) {
            return nums2[mid];
        } else if (nums2[mid2] <= nums1[0] && mid > mid2) {
            nums2.erase(nums2.begin(), nums2.begin()+mid2+1);
            return find(nums1, nums2, mid-mid2-1);
        }
        if (nums2[mid2] >= nums1[size1-1] && mid >= mid2+size1) {
            return nums2[mid-size1];
        } else if (nums2[mid] >= nums1[size1-1] && mid < mid2+size1) {
            nums2.erase(nums2.begin()+mid2);
            return find(nums1, nums2, mid);
        }
        
        if (mid < mid1+mid2) {
            nums1.erase(nums1.begin()+mid1);
            nums2.erase(nums2.begin()+mid2);
            return find(nums1, nums2, mid);
        } else if (mid == mid1+mid2){
            if (nums1[mid1] >= nums2[mid2]) {
                return nums1[mid1];
            } else {
                return nums2[mid2];
            }
        } else {
            nums1.erase(nums1.begin(), nums1.begin()+mid1);
            nums2.erase(nums2.begin(), nums2.begin()+mid2);
            return find(nums1, nums2, mid-mid1-mid2);
        }
        
    }
};

//Test unit
int main(int argc, const char * argv[]){
    vector<int> nums1, nums2;
    string line;
    std::cout << "Enter the First array:" << std::endl;
    getline(std::cin,line);
    string str1(line);
    int insert;
    stringstream ss(line);
    while (ss >> insert) {
        nums1.push_back(insert);
    }
    std::cout << "Enter the Second array:" << std::endl;
    getline(std::cin, line);
    stringstream ss2(line);
    while (ss2 >> insert) {
        nums2.push_back(insert);
    }
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    double result = Solution().findMedianSortedArrays(nums1, nums2);
    std::cout << result << std::endl;
    
    return 0;
}
