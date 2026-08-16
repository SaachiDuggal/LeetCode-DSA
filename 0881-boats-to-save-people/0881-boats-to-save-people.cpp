class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        //edge cases
        //sort the array
        sort(people.begin(), people.end());

        //initialise 2 pointers to track the numbers
        int left = 0;
        int right = people.size() - 1;

        //initialise the boats variable
        int boats = 0;

        //loop through the array
        while(left <= right){

            //calculating the sum
            int total = people[right] + people[left];
            //checking if their sum <= limit
            if(total <= limit){
                //if yes, then move both the pointers 
                left++;
                right--;
            }
            ////if no, then move the right pointer
            else{
                right--;
            }
            boats++;
        }
        return boats;
    }
};