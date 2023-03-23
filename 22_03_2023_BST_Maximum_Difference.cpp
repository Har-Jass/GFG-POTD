void help(Node* root, int target, int a, int b, int &ans, bool found){
        if(!root) {
            return;
        }
        if(root -> data == target) {
            found = true;
        }
        if(found == true){
            b += root->data;
            help(root -> left, target, a, b, ans, found);
            help(root -> right, target, a, b, ans, found);
            if(!root -> left and !root -> right){
                b -= target;
                ans = max(ans, a - b);
            }
        }
        else{
            a += root -> data;
            if(target < root -> data) {
                help(root -> left, target, a, b, ans, found);
            }
            else {
                help(root -> right, target, a, b, ans, found);
            }
        }
    }
    int maxDifferenceBST(Node *root, int target){
        int a = 0, b = 0, ans = INT_MIN;
        bool found = false;
        help(root, target, a, b, ans, found);
        if(ans == INT_MIN) {
            return -1;
        }
        return ans;
    }
