#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool robot(string command, vector<vector<int>> &obstacles, int x, int y)
    {
        int pos_x = 0, pos_y = 0;
        vector<vector<int>> path;
        vector<int> t(2, 0);
        path.push_back(t);
        for (int i = 0; i < command.size(); i++)
        {
            if (command[i] == 'U')
                pos_y++;
            if (command[i] == 'R')
                pos_x++;
            t[0] = pos_x;
            t[1] = pos_y;
            path.push_back(t);
        }
        int t_n, t_x, t_y;
        if (pos_x != 0)
        {
            t_n = x / pos_x;
            t_x = x - pos_x * t_n;
            t_y = y - pos_y * t_n;
            bool flag = false;
            if (t_y >= 0 && t_y <= pos_y)
                for (int j = 0; j < path.size(); j++)
                    if (path[j][0] == t_x && path[j][1] == t_y)
                        flag = true;
            if (!flag)
                return false;
            if ((obstacles.size() <= 0) || (x == 0 && y == 0))
                return true;
            for (int i = 0; i < obstacles.size(); i++)
            {
                if (obstacles[i][0] > x || obstacles[i][1] > y)
                    continue;
                t_n = obstacles[i][0] / pos_x;
                t_x = obstacles[i][0] - pos_x * t_n;
                t_y = obstacles[i][1] - pos_y * t_n;
                if (t_y >= 0 && t_y <= pos_y)
                    for (int j = 0; j < path.size() - 1; j++)
                        if (path[j][0] == t_x && path[j][1] == t_y)
                            return false;
            }
        }
        else
        {
            t_n = y / pos_y;
            t_x = x - pos_x * t_n;
            t_y = y - pos_y * t_n;
            bool flag = false;
            if (t_x >= 0 && t_x <= pos_y)
                for (int j = 0; j < path.size(); j++)
                    if (path[j][0] == t_x && path[j][1] == t_y)
                        flag = true;
            if (!flag)
                return false;
            if ((obstacles.size() <= 0) || (x == 0 && y == 0))
                return true;
            for (int i = 0; i < obstacles.size(); i++)
            {
                if (obstacles[i][0] > x || obstacles[i][1] > y)
                    continue;
                t_n = obstacles[i][1] / pos_y;
                t_x = obstacles[i][0] - pos_x * t_n;
                t_y = obstacles[i][1] - pos_y * t_n;
                if (t_x >= 0 && t_x <= pos_x)
                    for (int j = 0; j < path.size() - 1; j++)
                        if (path[j][0] == t_x && path[j][1] == t_y)
                            return false;
            }
        }
        return true;
    }
};