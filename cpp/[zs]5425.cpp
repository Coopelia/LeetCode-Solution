#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>
using namespace std;

class Solution
{
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        vector<int> H, W;
        H.push_back(0);
        W.push_back(0);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        for (int i = 0; i < horizontalCuts.size(); i++)
            H.push_back(horizontalCuts[i]);
        for (int i = 0; i < verticalCuts.size(); i++)
            W.push_back(verticalCuts[i]);
        H.push_back(h);
        W.push_back(w);
        double max_h = 0, max_w = 0;
        for (int i = 0; i < H.size() - 1; i++)
            max_h = max(max_h, fabs(H[i] - H[i + 1]));
        for (int i = 0; i < W.size() - 1; i++)
            max_w = max(max_w, fabs(W[i] - W[i + 1]));
        return fmod(max_h * max_w, ((int)pow(10, 9) + 7));
    }
};