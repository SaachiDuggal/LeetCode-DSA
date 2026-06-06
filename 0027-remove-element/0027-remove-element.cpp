class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        //edge case if array is empty or array has only one element which is the val
        if(nums.empty()){
            return 0;
        }

        //initialising the variables
        int write = 0;
        
        //looping to switch elements in the array to remove val
        for(int read = 0; read < nums.size(); read++){

            //if read == val then we swap
            if(nums[read] != val){
                //swap(nums[write], nums[read]);
                nums[write] = nums[read];
                write++;
            }
        }
        return write;
    }
};