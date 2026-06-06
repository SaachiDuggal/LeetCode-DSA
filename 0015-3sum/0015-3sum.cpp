class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        //initialising the vector result
        vector<vector<int>>result;

        //edge case to handle less than 3 elements
        if(nums.size() <= 2){
            return{};
        }

        //sorting the array
        sort(nums.begin(), nums.end());

        //looping through the array to find the triplets
        for(int i = 0; i < nums.size()-2; i++){

            //getting past the duplicates to avoid getting same answers again
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            //calculating the target for the rest of the array to find the sum
            int target = -nums[i];

            //initialising j and k pointers
            int j = i+1;
            int k = nums.size()-1;

            while(j < k){
                //find the sum in the rest of the array
                int answer = nums[j] + nums[k]; 

                if(answer == target){
                    result.push_back({nums[i], nums[j], nums[k]});

                    //sliding j forward to skip the same elements
                    while(j < k && nums[j]== nums[j+1])j++;

                    //sliding k backward to skip the same elements
                    while(j < k && nums[k] == nums[k-1]) k--;

                    //one final time to actually reach the new element
                    j++;
                    k--;
                    
                }
                else if(answer < target){
                    j++;
                }
                else{
                    k--;
                }
            }  
        }
        return result;
    }
};

/*
-initialised results as we needed a list of lists to store the answer
-we handled the edge case of less than 3 elements
-we sorted the array as to make it easier to find triplets and go through the duplicates
-we looped our int i so that we can find its parts of matching triplets
-then we treated the rest of the array as 2 sum problem with 2 pointers as it was sorted and for the target we used 0-nums[i] and whenever we found a match we just simply added it to the result.
-now to avoid duplicates: for i we added an if loop to check if i == i-1; for j and k we used while loops to ensure that they stay within j<k and they check if j and j+1 are equal we j++; doing this we reach the last same element so we used one more j++ to reach the new one.
*/

