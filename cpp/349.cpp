#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> se1;
        set<int> se2;
        vector<int> re;
        if (nums1.size() <= nums2.size())
        {
            for (int i = 0; i < nums1.size(); i++)
                se1.insert(nums1[i]);
            for (int i = 0; i < nums2.size(); i++)
            {
                if (se1.count(nums2[i]))
                {
                    re.push_back(nums2[i]);
                    se1.erase(nums2[i]);
                }
            }
        }
        else
        {
            for (int i = 0; i < nums2.size(); i++)
                se1.insert(nums2[i]);
            for (int i = 0; i < nums1.size(); i++)
            {
                if (se1.count(nums1[i]))
                {
                    re.push_back(nums1[i]);
                    se1.erase(nums1[i]);
                }
            }
        }
        return re;
    }
};