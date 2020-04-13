class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        if (matrix.empty())
            return false;
        int row = matrix.size() - 1;       //rows
        int colmax = matrix[0].size() - 1; //columns
        if (target > matrix[row][colmax] || target < matrix[0][0])
            return false;
        int col = 0;

        while (row >= 0 && col < colmax)
        {
            if (target < matrix[row][col])
                row--;
            else if (target > matrix[row][col])
                col++;

            else
                return true;
        }
        return false;
    };
};
