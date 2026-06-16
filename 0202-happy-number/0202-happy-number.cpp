class Solution {
public:

    //Helper Function: solving the number to get the square and sum
    int getNext(int n){
        int total_sum = 0;

        //calculating the sum
        while(n > 0){
            //grabbing the last digit of the number
            int digit = n % 10;
            total_sum += digit*digit;
            n/=10;
        }
        return total_sum;
    }

    bool isHappy(int n) {
        
        //initialising pointers
        int slow = n;
        int fast = getNext(n);

        //looping till we find a cycle
        while(slow != fast){
            //moving pointers
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }

        //checking if its a happy number
        if(fast == 1){
            return true;
        }
        else{
            return false;
        }
    }
};