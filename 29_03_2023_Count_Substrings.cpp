class Solution
{
    public:
    int countSubstring(string S)
    {
        int c = 0;
        for(int i = 0; i < S.size(); i++) {
            int f = 0;
            int n = 0;
            for(int j = i; j < S.size(); j++) {
                if(S[j] >= 'a' and S[j] <= 'z') {
                    f++;
                }
                else {
                    n++;
                }
                if(f == n) { 
                    c++;
                }
            }
        }
        return c;
    }
};
