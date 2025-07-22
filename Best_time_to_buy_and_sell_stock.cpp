#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& arr){
    int n= arr.size();
    int profit=0;
    int mini=arr[0];
    for(int i=0; i<n; i++){
        int cost= arr[i]-mini;
         profit=max(profit, cost);
mini= max(mini, arr[i]);
    }
    return profit;

}
int mian(){
    int n;
    cin>>n;
    vector<int>arr= {3 , 8,1,4,6,2};
    int ans= maxProfit(arr);
    cout<<ans<<endl;
  
}