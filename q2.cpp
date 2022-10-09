// nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]

// [1,4,5],[2,3,9]

//.   dp[i][j] = num1[i]==nums2[j] 1+ dp[i+1][j+1] else 0
#include<bits/stdc++.h>
using namespace std;

int maxSubarray(vector<int> nums1, vector<int> nums2){
    int n = nums1.size();
    int m = nums2.size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    int ans=0;
    int val =0;
    vector<int> temp;
    for(int i=n-1;i>=0;i--){
        vector<int> temp1(m,0);
        for(int j=m-1;j>=0;j--){
            if(nums1[i]==nums2[j]){
                temp1[j] = 1;
                if(i+1<n and j+1<m){
                    temp1[j] += temp[j+1];
                }
                ans = max(ans, temp1[j]);
            }
        }
        temp = temp1;
    }
    return ans;
}


int main()
{
    return 0;
}