#include<iostream>
#include<vector>
using namespace std;


int countInversion(vector<int>&arr,int s, int e){
    int mod=1E9+7;
    int findFloor(vector<int>&arr,int s, int e,int key);
    void merge(vector<int>&arr,int s1, int s2,int e);
    if(s==e)return 0;
    int mid = (s+e)/2;
    int left = countInversion(arr,s,mid)%mod;
    int right = countInversion(arr,mid+1,e)%mod;
    int ans = (left%mod + right%mod)%mod;
    for(unsigned int i=s;i<=mid;i++){
        int temp = findFloor(arr,mid+1,e,arr[i])-(mid+1)+1;
        ans = (ans%mod + temp%mod)%mod;
    }
    merge(arr,s,mid+1,e);
    return ans;
}

int findFloor(vector<int>&arr,int s, int e,int key){
    int ans=s-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid]>=key){
            e=mid-1;
        } else {
            ans = mid;
            s=mid+1;
        }
    }
    return ans;
}

void merge(vector<int>&arr,int s1, int s2,int e){
    vector<int>ans(e-s1+1);
    int i=s1;
    int j=s2;
    int k=0;
    while(i<=s2-1 && j<=e){
        if(arr[i]<=arr[j]) ans[k++] = arr[i++];
        else ans[k++] = arr[j++];
    }
    while(i<=s2-1){
        ans[k++]=arr[i++];
    }
    while(j<=e){
        ans[k++]=arr[j++];
    }
    k=0;
    for(unsigned int i=s1;i<=e;i++){
        arr[i] = ans[k++];
    }
}



int main(){
    vector<int>arr={3,4,1,2};
    cout << countInversion(arr,0,arr.size()-1)<<endl;
    return 0;
}