long long int no_of_subarrays(int n, vector<int> &arr) {
    
    /* Approach 1 --> Using nested for loops & it gives TLE for O(n^2) complexity */
    // long long count = 0;
    // for(int i = 0; i < n; i++) {
        // for(int j = i; j < n; j++) {
            // if(arr[j] == 0) {
                // count++;
            // }
            // else {
                // break;
            // }
        // }
    // }
    // return count;
    
    /* Approach 2 --> O(n) complexity */
    long long ans = 0;
    long long count  = 0;
    // First we count the consecutive 0's in the Array
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            count++;
        }
        // When there is no 0 left, we calculate the subarrays using the formulae, i.e., count * (count + 1) / 2
        else {
            ans += (count * (count + 1) / 2);
            count = 0;
        }
    }
    // If there is more 0's at the end then again count the 0's and calculate subarrays using same formulae
    if(count > 0) {
        ans += (count * (count + 1) / 2);
    }
    return ans;
}
