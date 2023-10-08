#include<iostream>
#include<vector>
using namespace std;

int getMaxDotProduct(vector<int>&nums1,vector<int>&nums2){
    vector<vector<int>>dp(nums1.size(),vector<int>(nums2.size()));
    dp[0][0]=nums1[0]*nums2[0];
    for(unsigned int i=1;i<nums2.size();i++){
        dp[0][i] = max(dp[0][i-1],nums1[0]*nums2[i]);
    }
    for(unsigned int i=1;i<nums1.size();i++){
        dp[i][0] = max(dp[i-1][0],nums1[i]*nums2[0]);
    }
    for(unsigned int i=1;i<nums1.size();i++){
        for(unsigned int j=1;j<nums2.size();j++){
            dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            dp[i][j] = max(dp[i-1][j-1]+(nums1[i]*nums2[j]),dp[i][j]);
            dp[i][j] = max(dp[i][j],nums1[i]*nums2[j]);     
        }
    }
    return dp[nums1.size()-1][nums2.size()-1];
}


int main(){
    vector<int>nums1 = {2,1,-2,5};
    vector<int>nums2 = {3,0,-6};
    printf("%d\n",getMaxDotProduct(nums1,nums2));
    return 0;
}