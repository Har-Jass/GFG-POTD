long long help(string S, int X, int Y, string rem) {
        stack<char> st;
        long long total = 0;
        for(int i = 0; i < S.size(); i++) {
            if(st.size() and S[i] == rem[1] and st.top() == rem[0]) {
                total += X;
                st.pop();
            }
            else {
                st.push(S[i]);
            }
        }
        S = "";
        while(st.size()) {
            S += st.top();
            st.pop();
        }
        for(int i = 0; i < S.size(); i++) {
            if(st.size() and S[i] == rem[1] and st.top() == rem[0]) {
                total += Y;
                st.pop();
            }
            else {
                st.push(S[i]);
            }
        }
        return total;
    }
    
    long long solve(int X,int Y,string S){
      long long ans= 0;
      if(X > Y) {
          ans = help(S, X, Y, "pr");
      }
      else {
          ans = help(S, Y, X, "rp");
      }
      return ans;
    }
