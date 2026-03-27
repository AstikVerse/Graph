#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
void build(vector<int>&arr,vector<int>&segtree,int ind,int l, int r){
 if(l==r){
    segtree[ind] = arr[l];
    return ;
 }
    int mid = (l+r)/2;
    build(arr,segtree,2*ind+1,l,mid);
    build(arr,segtree,2*ind+2,mid+1,r);
    segtree[ind]= min(segtree[2*ind+1], segtree[2*ind+2]);
}
void update(vector<int>&arr,vector<int>&segtree,int i,int idx,int l, int r,int val){
    if(l==r){
        segtree[i]=val;
        arr[idx]=val;
        return;
    }
    int mid =(l+r)/2;
    if(idx<=mid){
        update(arr,segtree,2*i+1,idx,l,mid,val);
    }else{
           update(arr,segtree,2*i+2,idx,mid+1,r,val);
    }
     segtree[i]=min(segtree[2*i+1],segtree[2*i+2]);
}
int query(vector<int>&segtree,int ind,int start,int end,int l, int r){
    if(end<l||r<start){
        return INT_MAX;
    }
    if(start<=l && r<=end){
        return segtree[ind];
    }
    int mid=(l+r)/2;
    return min(query(segtree,2*ind+1,start,end,l,mid), query(segtree,2*ind+2,start,end,mid+1,r));
    
}
int main(){
    int n,q;
    cin>>n>>q;
vector<int>arr(n,0);
for(int i=0;i<n;i++){
    cin>>arr[i];
}
vector<int>segtree((4*n),0);
build(arr,segtree,0,0,n-1);
for(int i=0;i<q;i++){
    int m;
    cin>>m;
    if(m==1){
      int k,u;
      cin>>k>>u;
      update(arr,segtree,0,k-1,0,n-1,u);  
    }else{
        int a,b;
        cin>>a>>b;
       cout<< query(segtree,0,a-1,b-1,0,n-1)<<endl;
    }
}

return 0;
}