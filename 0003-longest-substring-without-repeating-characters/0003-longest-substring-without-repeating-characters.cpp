class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        //edge case: if the string is empty
        if(s.empty()){
            return 0;
        }

        //edge case: if it only has one character
        if(s.size() == 1){
            return 1;
        }

        //initialise a variable to store the maximum length
        int max_length = 0;

        //initialising an unordered set to keep track of the subsequence
        unordered_set<char> substring;

        //initialising variables to go through the string
        int first = 0;

        //looping through the string and keeping track of the longest substring
        for(int last = 0; last < s.size(); last++){

            //if we found a match for s[last] in the set
            while(substring.find(s[last]) != substring.end()){
                //removing elements from the substring till it becomes clean again
                substring.erase(s[first]);
                first++;
            }
            
            //now we are at a place where the s[last] is cleaned and the pointer is updated
            substring.insert(s[last]);

            //now our window is cleared, so we calculate the length
            int current_length = last - first + 1;

            //updating the max_length
            max_length = max(current_length, max_length);
        }
        return max_length;
    }
};