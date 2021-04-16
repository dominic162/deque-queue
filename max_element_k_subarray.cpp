/*
    Given a array, find largest of each subarray of size k;
*/

#include<iostream>
#include<deque>
using namespace std;

class basic{
    public:
        int* make_arr(int n);

        void disp_arr(int* arr,int n);
};

class solution:public basic{
    public:
        int* max_k(int* arr, int n, int k);
};

int main(){
    
    int n;
    cout<<"Enter number of elements in array: ";
    cin>>n;

    solution sl;
    int* arr = sl.make_arr(n);

    int k;
    cout<<"Enter length of subarray: ";
    cin>>k;

    int* ans = sl.max_k(arr,n,k);

    sl.disp_arr(ans,n-k+1);
    return 0;
}

int* basic::make_arr(int n){
    int* arr = new int [n];
    cout<<"Enter elements: ";
    for(int i=0; i<n; ++i){
        cin>>arr[i];
    }
    return arr;
}

void basic::disp_arr(int* arr , int n){
    for(int i=0; i<n; ++i){
        cout<<arr[i]<<" ";
    }
    return ;
}

int* solution::max_k(int* arr, int n, int k){

    int* ans = new int [n-k+1];
    deque<int> dq;

    for(int i=0; i < k; ++i){
        
        while(!dq.empty() && arr[i] >= arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);

    }

    for(int i=k ;i< n;++i){
        ans[i-k] = arr[dq.front()];

        while(!dq.empty() && dq.front() <= i-k){
            dq.pop_front();
        }

        while(!dq.empty() && arr[i] >= arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans[n-k] = arr[dq.front()];
    
    return ans;
}