/*
-initialised results as we needed a list of lists to store the answer
-we handled the edge case of less than 3 elements
-we sorted the array as to make it easier to find triplets and go through the duplicates
-we looped our int i so that we can find its parts of matching triplets
-then we treated the rest of the array as 2 sum problem with 2 pointers as it was sorted and for the target we used 0-nums[i] and whenever we found a match we just simply added it to the result.
-now to avoid duplicates: for i we added an if loop to check if i == i-1; for j and k we used while loops to ensure that they stay within j<k and they check if j and j+1 are equal we j++; doing this we reach the last same element so we used one more j++ to reach the new one.
*/


class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        //initialisng a vector for storing results
        vector<vector<int>> result;

        //edge case: array size less than 3
        if(nums.size() <= 2){
            return{};
        }

        //sorting the array
        sort(nums.begin(), nums.end());

        //Outer loop: to loop through the array as the first element of the result
        for(int i = 0; i < nums.size() - 2; i++){

            //detecting and skipping duplicates
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            //initialise a target for the inner loop
            int target = - nums[i];

            //initialising the 2 pointers
            int left = i + 1;
            int right = nums.size() - 1;

            //inner loop: to find the match for the target using 2 pointers
            while(left < right){

                //calulate the sum
                int answer = nums[left] + nums[right];

                //check if its equal target, if it is we push back
                if(answer == target){
                    //pushback the results
                    result.push_back({nums[i], nums[left], nums[right]});

                    //skipping the same elements for left
                    while(left < right && nums[left] == nums[left + 1]) left++;

                    //skipping the duplicate elements for right
                    while(left < right && nums[right] == nums[right - 1]) right--;

                    //finally one last skip to reach a new element
                    left++;
                    right--;
                }

                //the answer is less than the target
                else if(answer < target){
                    left++;
                }
                //the answer is more than target
                else{
                    right--;
                }
            }
        }
        return result;
    }
};










