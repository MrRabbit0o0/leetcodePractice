class Solution {
public:
    int trap(int A[], int n) {
        int leftMax, rightMax;
        leftMax = A[0];
        rightMax = A[n-1];
        int i = 0, j = n-1;
        int sum = 0;
        while (i < j) {
            if (leftMax < rightMax){
                i ++;
                if (leftMax > A[i]) {
                    sum += leftMax - A[i];
                } else {
                    leftMax = A[i];
                }
            } else {
                j --;
                if (rightMax > A[j]) {
                    sum += rightMax - A[j];
                } else {
                    rightMax = A[j];
                }
            }
        }
        return sum;
    }
    
};
