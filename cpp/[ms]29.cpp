#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> re;
        if (matrix.empty())
            return re;
        int l = 0, r = matrix[0].size() - 1, u = 0, d = matrix.size() - 1;
        while (true)
        {
            for (int i = l; i <= r; i++)
                re.push_back(matrix[u][i]);
            if (++u > d)
                break;
            for (int i = u; i <= d; i++)
                re.push_back(matrix[i][r]);
            if (--r < l)
                break;
            for (int i = r; i >= l; i--)
                re.push_back(matrix[d][i]);
            if (--d < u)
                break;
            for (int i = d; i >= u; i--)
                re.push_back(matrix[i][l]);
            if (++l > r)
                break;
        }
        return re;
    }
};