class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        //edge case if empty or just one element
        if(nums.empty() || nums.size() == 1){
            return;
        }

        //declare variables and assign them
        int writePointer = 0;

        //loop through the array to check for zero elements and swap them
        for(int readPointer = 0; readPointer < nums.size(); readPointer++){
            
            if(nums[readPointer] != 0){
                swap(nums[writePointer],nums[readPointer]);

                writePointer ++;
            }
        }
        return;
    }
};