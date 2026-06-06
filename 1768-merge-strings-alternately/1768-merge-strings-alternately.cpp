class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        //initialising result
        string result;
        
        //edge case
        if(word1.empty() && word2.empty()){
            return {};
        }

        //edge case of either one word being empty handled in our while loops

        //initialising variables
        int first = 0;
        int second = 0;

        //mail loop for alternating
        while(first < word1.size() && second < word2.size()){
            //adding first
            result.push_back(word1[first]);
            first++;

            //adding second
            result.push_back(word2[second]);
            second++;
        }

        //when word1 is longer than word2
        while(first < word1.size()){
            result.push_back(word1[first]);
            first++;
        }

        //when word2 is longer than word1
        while(second < word2.size()){
            result.push_back(word2[second]);
            second++;
        }
        return result;
    }
};