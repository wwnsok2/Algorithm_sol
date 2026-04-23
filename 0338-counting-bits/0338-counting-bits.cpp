class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> result;

        for(int i=0;i<=n;i++)
        {
            int num = 0;
            int temp = i;
            if(i == 0)
            {
                result.push_back(0);
                continue;
            }
            else
            {
                while(temp > 0)
                {
                    if(temp & 1)
                    {
                        num += 1;
                    }
                    temp = temp >> 1;
                }
            }
            result.push_back(num);
        }

        return result;
    }
};