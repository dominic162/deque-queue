
//doubly ended queue

#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> dq;
    auto it=dq.begin();
    it=dq.insert(it,5,4);
    while(it!=dq.end()){
        cout<<*it<<" ";
        it++;
    }


    return 0;
}