class Solution {
public:
    int search(vector<int>& nums, int target) {
        //edge cases
        //initialising pointer left and right
        int left = 0;
        int right = nums.size() - 1;

        //loop till left <= right
        while(left <= right){

            //calculating mid
            int mid = left + (right - left) / 2;

            //if target found return mid
            if(target == nums[mid]){
                return mid;
            }

            //check if left side is sorted
            else if(nums[left] <= nums[mid]){
                //check if target exists in the range
                if(target >= nums[left] && target < nums[mid]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            //check if right side is sorted
            else{
                //check if it exists in the range
                if(target > nums[mid] && target <= nums[right]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }

        }
        return -1;
    }
};