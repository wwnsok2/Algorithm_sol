class Solution {
public:
    vector<string> temp;
    vector<vector<string>> result;

    vector<vector<string>> partition(string s) {
        int str_len = s.size();
        
        int isPal[16][16] = {0};

        for(int i=0;i<str_len;i++)
        {
            isPal[i][i] = true;

            if(i < str_len - 1 && s[i] == s[i+1])
            {
                isPal[i][i+1] = true;
            }
        }        
        for(int len=3;len<=str_len;len++)
        {
            for(int i=0;i<=str_len-len;i++)
            {
                int j = i + len - 1;
                if((s[i] == s[j]) && (isPal[i+1][j-1] == true))
                {
                    isPal[i][j] = true;
                }
            }
        }

        DFS(isPal, str_len, 0, s);

        return result;

    }

    void DFS(int isPal[16][16], int str_len, int now, string& s)
    {
        if(now == str_len)
        {
            result.push_back(temp);
            return;
        }

        for(int i=now;i<str_len;i++)
        {
            if(isPal[now][i] == true)
            {
                temp.push_back(s.substr(now,i-now+1));
                DFS(isPal, str_len, i+1, s);
                temp.pop_back();
            }
        }
    }
};