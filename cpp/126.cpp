#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string startWord;
    vector<string> wordList;
    vector<vector<int>> re;
    vector<vector<int>> sta;

    bool isOk(string a,string b)
    {
        for (int i = 0; i < a.size(); i++)
        {
            bool flag=true;
            for (int j = 0; j < a.size(); j++)
            {
                if(i==j)
                    continue;
                if(a[j]!=b[j])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
                return true;
        }
        return false;
    }

    bool find_begin(int num_re)
    {
        if(isOk(wordList[re[num_re][re[num_re].size()-1]],startWord))
            return true;
        vector<int> t;
        string s=wordList[re[num_re][re[num_re].size()-1]];
        for (int i = 0; i < wordList.size(); i++)
        {
            if(sta[num_re][i]==1)
                continue;
            if(isOk(s,wordList[i]))
                t.push_back(i);
        }
        for (int i = 0; i < t.size()-1; i++)
            re.push_back(re[num_re]);
        for (int i = 0; i < t.size(); i++)
        {
            re[num_re].push_back(i);
                sta[num_re][i]=0;
                if(!find_begin(num_re))
                {
                    re[num_re].pop_back();
                    sta[num_re][i]=1;
                }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {

    }
};