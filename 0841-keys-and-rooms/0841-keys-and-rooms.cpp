class Solution {
public:
    int n;

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n = rooms.size();
        vector<int> visit(n,0);
        bool ans = true;


        DFS(rooms, visit, 0);
 

        for(int i=0;i<n;i++)
        {
            ans &= visit[i];
        }

        return ans;

    }

    void DFS(vector<vector<int>>& rooms, vector<int>& visit, int i)
    {
        visit[i] = 1;

        for(int temp : rooms[i])
        {
            if(visit[temp] == 0)
            {
                DFS(rooms, visit, temp);
            }
        }
    }
};