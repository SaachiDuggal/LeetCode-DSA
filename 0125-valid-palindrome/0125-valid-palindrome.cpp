class Solution {
public:
    bool isPalindrome(string s) {

        //Edge case of it being empty
        if(s.empty() || s.size() == 1){
            return true;
        }

        //initializing 2 pointers
        int left = 0;
        int right = s.size() - 1;
        
        //put them in a 2 pointer rule
        while(left < right){

            //check for elements being non alphanumeric
            while(left < right && !isalnum(s[left])){
                left++;
            }

            while(left < right && !isalnum(s[right])){
                right--;
            }

            //converting elements to lowercase
            char leftChar = tolower(s[left]);
            char rightChar = tolower(s[right]);

            //check for the similarity
            if(leftChar == rightChar){
                left++;
                right--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};