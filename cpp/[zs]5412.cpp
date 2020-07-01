#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime)
    {
        int re=0;
        for (int i = 0; i < startTime.size(); i++)
        {
            if(startTime[i]<=queryTime&&endTime[i]>=queryTime)
                re++;
        }
        return re;
    }
};