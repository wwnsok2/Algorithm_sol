class Solution {
public:
    int m;
    int n;
    int dy[4] = {0,0,1,-1};
    int dx[4] = {1,-1,0,0};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       m = image.size();
       n = image[0].size();

        BFS(image,sr,sc,color);

        return image;

    }

    int isValid(int y, int x)
    {
        if(y<0 || y>= m || x<0 || x>= n)
        {
            return 0;
        }

        return 1;
    }

    void BFS(vector<vector<int>>& image, int sr, int sc, int color)
    {
        int temp = image[sr][sc];
        if (image[sr][sc] == color)
        {
            return;
        }

        image[sr][sc] = color;
        queue<pair<int,int>> q;
        q.push({sr,sc});



        while(!q.empty())
        {
            pair<int,int> now = q.front();
            q.pop();

            for(int i=0;i<4;i++)
            {
                int y_n = now.first + dy[i];
                int x_n = now.second + dx[i];

                if(isValid(y_n,x_n) && image[y_n][x_n]==temp)
                {
                    image[y_n][x_n] = color;
                    q.push({y_n,x_n});
                }
            }
        }
    }
};