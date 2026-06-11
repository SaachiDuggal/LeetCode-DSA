class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        //edge case: if array is empty
        if(nums.empty()){
            return 0;
        }

        //initialising variables for storing the result and the um of the current subarray
        int min_length = INT_MAX;
        int sum = 0;

        //initialising variable for the left index of the subarray
        int left = 0;

        //looping the right side index of the subarray to traverse through the subarray
        for(int right = 0; right < nums.size(); right++ ){

            //calculating the sum
            sum += nums[right];

            //while the subarray satisfies the target
            while(sum >= target){

                //calculating the length of the subarray and then comparing it with the minimum length
                int length = right - left + 1;
                min_length = min(length, min_length);

                //updating the left pointer to minimise the array
                sum -= nums[left];
                left++;
            }
        }
        return(min_length == INT_MAX) ? 0 : min_length;
    }
};