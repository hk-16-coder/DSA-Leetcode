class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersection_arr;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i = 0 ; i< n1 - 1 ; i++){
            for(int j = 0 ; j< n1 - i - 1 ; j++){
                if(nums1[j] >  nums1[j+1]) swap (nums1[j],nums1[j+1]);
        }
        }
        for(int i = 0 ; i< n2 - 1 ; i++){
            for(int j = 0 ; j< n2 - i - 1 ; j++){
                if(nums2[j] >  nums2[j+1]) swap (nums2[j],nums2[j+1]);
            }
        }
        int i = 0;
        int j = 0;
       while (i<n1 && j<n2){
        if(nums1[i] == nums2[j]){
            if(intersection_arr.size() == 0 || intersection_arr.back() != nums1[i]){
            intersection_arr.push_back(nums1[i]);
            }
            i++;
            j++;
            
        }
        else if (nums1[i] < nums2[j]) i++;
        else j++;
       }
       return intersection_arr;
    }
};