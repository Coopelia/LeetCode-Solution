#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        int *indepth = new int[numCourses];
        vector<vector<int>> out;
        vector<int> re;
        for (int i = 0; i < numCourses; i++)
        {
            indepth[i] = 0;
            vector<int> t;
            out.push_back(t);
        }
        for (int i = 0; i < prerequisites.size(); i++)
        {
            indepth[prerequisites[i][0]]++;
            out[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        int k = numCourses;
        while (k > 0)
        {
            for (int i = 0; i < numCourses; i++)
            {
                if (indepth[i] == 0)
                {
                    re.push_back(i);
                    for (int j = 0; j < out[i].size(); j++)
                        indepth[out[i][j]]--;
                    indepth[i] = -1;
                    k--;
                    break;
                }
            }
            bool flag = false;
            for (int i = 0; i < numCourses; i++)
            {
                if (indepth[i] == 0)
                    flag = true;
            }
            if (!flag)
                break;
        }
        if (re.size() < numCourses)
            re.clear();
        return re;
    }
};