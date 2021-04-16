/*
    Given certain digits, find k numbers in increasing order such that they contain only these digits;
*/

#include<iostream>
#include<string>
#include<queue>
using namespace std;

class solution{
    public:
        void n_print(string* arr , int n, int k);

        string* makearr(int n);
};

int main(){

    int n;
    cout<<"Enter number of digits: ";
    cin>>n;
    
    solution sl;
    string* arr = sl.makearr(n);

    int k;
    cout<<"Enter number of numbers to print: ";
    cin>>k;

    sl.n_print(arr, n ,k);

    return 0;
}

string* solution::makearr(int n){
    cout<<"Enter digits: ";
    string* arr = new string [n];
    for(int i=0; i<n; ++i){
        cin>>arr[i];
    }
    return arr;
}

void solution::n_print(string* arr, int n, int k){

    queue<string> q;
    
    for(int i=0;i<n;++i){
        q.push(arr[i]);
    }

    string r;
    for(int i=0;i<k;++i){
        r=q.front();
        q.pop();
        cout<<r<<" ";
        for(int i=0;i<n;++i){
            q.push(r+arr[i]);
        }
    }

    return ;
}