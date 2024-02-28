#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        map<char, int> mp; //Count
        deque<char> Q;     //Sequence

        mp.clear();

        int answer = 0;
        for (int i = 0; i < s.size(); i++)
        {
            //No occurance before, then direct push
            if (mp[s[i]] == 0)
            {
                Q.push_back(s[i]);
                mp[s[i]]++;
            }
            else
            {
                // answer = max(answer,Q.size());
                if (Q.size() > answer)
                {
                    answer = Q.size();
                }
                while (Q.front() != s[i])
                {
                    Q.pop_front();
                }
                Q.pop_front();
            }
        }
        return answer;
    }
};

int main()
{
    Solution *s = new Solution();
    cout << s->lengthOfLongestSubstring("abcabcbb") << endl;
}