/*
    N queues in a array;
*/

#include<iostream>
using namespace std;

class nqueue{
    public:
        int* arr;
        int* next;
        int* ft;
        int* end;
        int size,number,freefront;

        void push(int sn,int element);
        void pop(int sn);
        int front(int sn);
        void disp();

        nqueue(int n, int k); 
        ~nqueue(); 
};

int main(){

    int n,k;
    cout<<"Enter total number of elements and number of queues: ";
    cin>>n>>k;
    char ch;
    int sn,x;
    nqueue nq(n,k);
    do{
        cout<<"\nEnter 1 for push\n2 for pop\n3 for front element\n4 for display\n5 for exit\n";
        cin>>ch;
        switch(ch){
            case '1':
                cout<<"Enter stack number and element to be pushed: ";
                cin>>sn>>x;
                nq.push(sn-1,x);
                break;
            
            case '2':
                cout<<"Enter stack number: ";
                cin>>sn;
                nq.pop(sn-1);
                break;
            
            case '3':
                cout<<"Enter stack number: ";
                cin>>sn;
                cout<<"Front element of stack "<<sn<<" is "<<nq.front(sn-1);
                break;
            
            case '4':
                nq.disp();
                break;
        }
    }while(ch!='5');


    return 0;
}

nqueue::nqueue(int n, int k):size(n),number(k),freefront(0){
    arr = new int [size];
    next = new int [size];
    ft = new int [number];
    end = new int [number];

    for(int i=0;i<size;++i){
        arr[i] = -1;
        next[i] = i+1;
    }
    next[size-1] = -1;
    for(int i=0;i<number;++i){
        ft[i] = -1;
        end[i] = -1;
    }
    
}

void nqueue::push(int sn,int element){
    int fr=freefront;
    arr[fr]=element;
    freefront = next[freefront];
    if(ft[sn] == -1){
        ft[sn] = fr;
        end[sn] = fr;
    }
    else{
        next[end[sn]] = fr;
        end[sn] = fr;
    }
    next[fr] = -1;
}

void nqueue::pop(int sn){
    if(ft[sn] == -1){
        return ;
    }

    int temp = ft[sn];
    arr[temp] = -1;
    ft[sn] = next[temp];
    next[temp] = freefront;
    freefront = temp;
    if(ft[sn] == -1){
        end[sn] = -1;
    }
    return ;

}

int nqueue::front(int sn){
    return arr[ft[sn]];
}

void nqueue::disp(){
    for(int i=0;i<size;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<size;++i){
        cout<<next[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<number;++i){
        cout<<ft[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<number;++i){
        cout<<end[i]<<" ";
    }
}

nqueue::~nqueue(){
    delete [] arr;
    delete [] next;
    delete [] ft;
    delete [] end;
}
