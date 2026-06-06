class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        //edge case
        if(numbers.size()<=1){
            return{};
        }
        //initialising variables
        int ind1 = 0;
        int ind2 = numbers.size() - 1;

        //writing the loop condition
        while(ind1 < ind2){
            
            //answer
            int answer = numbers[ind1] + numbers[ind2];

            //if the addition equals target
            if(answer == target){
                return{ind1+1, ind2+1};
            }

            //if addition is greater than target
            if(answer > target){
                ind2--;
            }

            //if addition is smaller than target
            if(answer < target){
                ind1++;
            }
        }
        return {};
    }
};