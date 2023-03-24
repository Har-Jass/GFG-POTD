string removeReverse(string S) {
        int n = S.length();
        // two pointer approach
        int i = 0;
        int j = n - 1;
        
        // unordered_map for storing the frequency of characters
        unordered_map<char, int> map;
        
        // iterate over each character and store its frequency in map
        for(auto it : S) {
            map[it]++;
        }
        
        // bool variable for checking left and right of the string,
        // initially its true because we start traversing from left of the string
        bool flag = true;
        
        while(i <= j) {
            if(flag == true) {
                if(map[S[i]] > 1) {
                    map[S[i]]--;
                    S[i] = '0';
                    flag = false;
                }
                i++;
            }
            // means flag == false
            else {
                if(map[S[j]] > 1) {
                    map[S[j]]--;
                    S[j] = '0';
                    flag = true;
                }
                j--;
            }
        }
        
        // temp string for storing final answer
        string ans = "";
        for(auto it : S) {
            // if final string doesn't contain '0' then we store string in ans string
            if(it != '0') {
                ans += it;
            }
        }
        
        // at the end if flag is true, means we are at left side and don't need to reverse the string then, return the string
        if(flag == true) {
            return ans;
        }
        // if flag is false, means we are at right side and first reverse the string then, return the string
        reverse(ans.begin(), ans.end());
        return ans;
    }
