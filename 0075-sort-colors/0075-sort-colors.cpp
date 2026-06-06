class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        //edge case for empty or single element array
        if(nums.empty() || nums.size() == 1){
            return;
        }

        //initialising variables
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        //solution loop
        while(mid <= high){

            //if mid == 0
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            //if mid == 1
            else if(nums[mid] == 1){
                mid++;
            }
            //if mid == 2
            else if(nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        return;
    }
};