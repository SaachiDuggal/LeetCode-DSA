class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        //edge case: when array is less than 2 numbers
        if(heights.size() < 2){
            return 0;
        }

        //initialise a pointer to keep track of the left side and the right side
        int left = 0;
        int right = heights.size() - 1;

        //initialising a variable to hold the max_area
        int max_area = 0;

        //looping through the array in a converging manner
        while(left < right){

            //calculate the area
            int area = (right - left) * min(heights[left], heights[right]);

            //checking if the area just calculated is greater than the maximum area recorded 
            if(area > max_area){
                max_area = area;
            }

            //updating the pointers
            if(heights[left] < heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return max_area;
    }
};