class Solution {
public:
    int hammingWeight(int n) {
        vector<int> bin;
        int num = 0;

        while(n != 0)
        {
            if(n % 2 == 1)
            {
                bin.push_back(1);
            }
            else
            {
                bin.push_back(0);
            }

            n = n / 2;
        }

        for(int i=0;i<bin.size();i++)
        {
            if(bin[i] == 1)
            {
                num += 1;
            }
        }
        
        return num;
    }

};