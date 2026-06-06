class Solution {
public:

    //helper function
    bool isPalindrome(string s, int left, int right){
        //check for palindrome
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left ++;
            right --;
        }
        return true;
    }

    bool validPalindrome(string s) {
        
        //edge case
        if(s.empty()){
            return true;
        }

        //initialise the variables
        int first = 0;
        int last = s.size()-1;

        //logic to check for palindrome
        while(first < last){
            if(s[first] != s[last]){
                return (isPalindrome(s,first,last-1) || isPalindrome(s,first+1,last));
            }
            first++;
            last--;
        }
        return true;
    }
};