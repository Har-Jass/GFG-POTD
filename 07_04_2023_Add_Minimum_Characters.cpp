/* Given a string str, find the minimum characters to be added at front of the string to make it a palindrome */
#include <bits/stdc++.h>
using namespace std;

int addMinChar(string str) {
    int n = str.length();
    int i = 0, j = n - 1, temp = n - 1;
    while (i <= j) {
        if (str[i] == str[j]) {
            i++;
        }
        else {
            j = temp;
            i = 0;
            temp--;
        }
        j--;
    }
    return n - temp - 1;
}

int main() {
    string str = "";
    cout << "\nMinimum characters to make this string as palindrome is " << addMinChar(str) << endl;
    return 0;
}
