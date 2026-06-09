class Solution {
public:
    bool isSubsequence(string s, string t) {

        //edge case- if s is empty
        if(s.empty()){
            return true;
        }

        //edge case - if s is not empty and t is empty
        if(!s.empty() && t.empty()){
            return false;
        }

        //edge case - if s is longer than t
        if(s.size() > t.size()){
            return false;
        }

        //initialising a variable to track string s
        int i = 0;

        //looping through string t to check for the subsequence
        for(int j = 0; j < t.size(); j++){

            //checking for a similarity
            if(s[i] == t[j]){
                i++;

                //checking if we reached the end of string s
                if(i == s.size()){
                    return true;
                }
            }
        }
        return false;
    }
};

