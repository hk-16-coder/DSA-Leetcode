class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN , max2 = INT_MIN , max3 = INT_MIN;
        int max_neg1 = INT_MIN , max_neg2 = INT_MIN;

        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i] > max1){
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i] > max2 && nums[i] <= max1){
                max3 = max2;
                max2 = nums[i];
            }
            else if(nums[i] > max3 && nums[i] <= max2){
                max3 = nums[i];
            }

            // FOR NEGATGIVES
            if(nums[i] < 0){
                if(abs(nums[i]) > max_neg1){
                    max_neg2 = max_neg1;
                    max_neg1 = abs(nums[i]);
                }
                else if(abs(nums[i]) > max_neg2 && abs(nums[i]) <= max_neg1){
                    max_neg2 = abs(nums[i]);
                }
            }
        }
        if(max_neg1<0 || max_neg2<0) return max1*max2*max3;
        return max(max1*max2*max3 , max1*max_neg1*max_neg2);
    }
};