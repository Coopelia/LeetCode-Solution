#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution
{
public:
    string replaceWords(vector<string> &dict, string sentence)
    {
        vector<string> words;
        string s;
        for (int i = 0; i < sentence.size(); i++)
        {
            if (sentence[i] == ' ')
            {
                words.push_back(s);
                s.clear();
            }
            else
                s.push_back(sentence[i]);
        }
        words.push_back(s);
        set<string> dt;
        for (int i = 0; i < dict.size(); i++)
            dt.insert(dict[i]);
        string t;
        for (int i = 0; i < words.size(); i++)
        {
            t.clear();
            for (int j = 0; j < words[i].size(); j++)
            {
                t.push_back(words[i][j]);
                if (dt.count(t) != 0)
                {
                    words[i] = t;
                    break;
                }
            }
        }
        string res;
        for (int i = 0; i < words.size(); i++)
        {
            res += words[i];
            if (i < words.size() - 1)
                res.push_back(' ');
        }
        return res;
    }
};