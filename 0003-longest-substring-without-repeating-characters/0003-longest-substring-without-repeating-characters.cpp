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



/*
1. we use nested loops, and for ever j moving forward we look back and check for its duplicacy in i to j-1. tc on2, sc o1
2. we loop i and for each i we loop a j and add j in a hashmap, if a duplicate found we will record the size of the map and then i++ and do it again. tc on2 sc on.
3. we point at i = 0, and then start a j loop for every j we check if s[j] exists in the hashmap (here unordered set as the order doesnt matter and we only need to store one thing hence set and not a map) if it exists, then we do i++ till s[j] isnt found in the map, and then we add s[j] to the map, then we calculate the length, then compare that length to max length
*/