class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        //edge case
        if(nums.empty()){
            return -1;
        }

        //calculating total sum of the array
        int totalSum = 0;
        for(int i = 0; i < nums.size(); i++){
            totalSum = totalSum + nums[i];
        }

        //initialise variables
        int leftSum = 0;

        //running through a loop
        for(int pivot = 0; pivot < nums.size(); pivot++){
            //calculating the rightSum for this
            int rightSum = totalSum - leftSum- nums[pivot];

            //checking for pivot
            if(rightSum == leftSum){
                return pivot;
            }
            else{
                leftSum += nums[pivot];
            }
        }
        return -1;
    }    
};