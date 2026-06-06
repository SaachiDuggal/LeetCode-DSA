class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        //edge case
        if(nums.empty()){
            return 0;
        }

        //if only 1 element
        if(nums.size() == 1){
            return 1;
        }

        //initialising variables
        int write = 1; //since i = 0 would be the first unique element

        //looping for getting unique elements ahead
        for(int read = 1; read < nums.size(); read++){

            //finding unique elements and getting them ahead
            if(nums[read] != nums[read - 1]){
                nums[write] = nums[read];
                write++;
            }
        }
        return write;
    }
};