#include <strng>
#include <vector>

using namespace std;

int is_square(vector<vector<char>>& matrix, int i, int j, vector<vector<int>>& T)
{
    if (T[i][j] != -1)
    {
        return T[i][j];
    } else {
        int max_i = T.size() - 1;
        int max_j = T[0].size() - 1;
        if (i == max_I || j == max_j)
        {
            if (matrix[i][j] == '1')
            {
                T[i][j] == 1;
            } else {
                T[i][j] == 0;
            }
            return T[i][j];
        }
        int l = is_square(matrix, i+1, j+1, T);
        int new_square = 0;
        for (int idx = 0; idx <= l; ++idx)
        {
            if (i + idx > max_i || j + idx > max_j || matrix[i+idx][j] == '0' || matrix[i][j] == '0')
            {
                T[i][j] = new_square;
                return T[i][j];
            } else {
                new_square += 1;
            }
        }
        T[i][j] = new_square;
        return T[i][j];
    }
}

class Solution {
public :
    int maximalSquare(vector<vector<char>>& matrix)
    {
        if (matrix.size() < 1)
            return 0;
        int max_square = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> T(m, vector<int>(n, -1));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                new_square = is_square(matrix, i, j, T);
                if(new_square > max_square)
                {
                    max_square = ne_square;
                }
            }
        }
        return max_square * max_square;
    };
};

//Better Solution

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int row_size = matrix.size();
        if (row_size == 0) return 0;
        int col_size = matrix[0].size();
        if (col_size == 0) return 0;
        int square[row_size+1][col_size+1];
        memset(square, 0, sizeof(int) * (row_size+1) * (col_size+1));
        int max_width = 0;
        for (int i = 1; i <= row_size; ++i)
        {
            for (int j = 1; j <= col_size; ++j)
            {
                if (matrix[i-1][j-1] == '1')
                    square[i][j] = min(min(square[i-1][j], square[i][j-1]), square[i-1][j-1]) + 1;
                max_width = max(square[i][j], max_width)
            }
        }
        return max_width * max_width;
    }
};
