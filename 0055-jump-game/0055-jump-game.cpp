class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        //edge case
        if(nums.size() == 1){
            return true;
        }

        //initialising the variable for farthest possibility
        int max_reach = 0;

        //looping through the array to find the possibility
        for(int i = 0; i < nums.size(); i++){
            //comparing if we exceeded the max point we can reach
            if(i > max_reach){
                return false;
            }

            //updating the max reach for this i
            max_reach = max(max_reach, (i + nums[i]));
            
            //checking if we have already reached
            if(max_reach >= nums.size() - 1){
                return true;
            }
        }
        return true;
    }
};