int minimumTime(int N,int cur,vector<int> &pos,vector<int> &time){
        int ans = INT_MAX;
        for(int i = 0; i < N; i++) {
            int distance = abs(cur - pos[i]);
            ans = min(ans, distance * time[i]);
        }
        return ans;
    }
