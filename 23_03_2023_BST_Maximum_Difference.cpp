void help(Node* root, int target, int a, int b, int &ans, bool found){
        // agr root hi null hai to kch calculate hi nahi hoga so simple return kr jayege
        if(!root) {
            return;
        }
        // agr root ki value hi target se match krjati hai to found ko true krdenge
        if(root -> data == target) {
            found = true;
        }
        // agr found true hai means target mil gaya
        // to simple baaki saari nodes ko 'b' variable me add krenge
        if(found == true){
            b += root -> data;
            // node ki dono side ki values ko check krna pdega
            // below is the left of root
            help(root -> left, target, a, b, ans, found);
            // below is the right of root
            help(root -> right, target, a, b, ans, found);
            // agr node ka left or right dono null ho jate h means leaf node mil gaya
            if(!root -> left and !root -> right){
                // 'b' me target bhi add ho gaya tha so target ko subtract krna pdega
                b -= target;
                // 'a' and 'b' dono me se maximum value to 'ans' variable me save krwa denge
                ans = max(ans, a - b);
            }
        }
        // agr found true nahi h means target abhi tk nahi mila
        else{
            // target nahi mil means target se upar ki saari nodes ki value ko 'a' me add krte rhege
            a += root -> data;
            // agr target root se small hai to left search
            if(target < root -> data) {
                help(root -> left, target, a, b, ans, found);
            }
            // agr target root se greater hai to right search 
            else {
                help(root -> right, target, a, b, ans, found);
            }
        }
    }
    int maxDifferenceBST(Node *root, int target){
        int a = 0, b = 0, ans = INT_MIN;
        // initially target nahi mil to found false rhega
        bool found = false;
        help(root, target, a, b, ans, found);
        // ans ki value INT_MIN means target value available hi nahi h tree me to -1 return hoga
        if(ans == INT_MIN) {
            return -1;
        }
        return ans;
    }
