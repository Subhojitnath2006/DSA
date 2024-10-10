#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){

    //implement pq using max heap
    priority_queue<int> pq;

    //inserting elements into priority queue
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(1);
    //printing the top element
    cout<<pq.top()<<endl;

    //delete elements from pq
    pq.pop();

    //printing the pq elements
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }

    //implement pq using min heap
    priority_queue<int,vector<int>,greater<int>> pq2;

    //inserting elements into priority queue
    pq2.push(10);
    pq2.push(30);
    pq2.push(20);
    pq2.push(5);
    pq2.push(1);
    //printing the top element
    cout<<pq2.top()<<endl;

    //delete elements from pq
    pq2.pop();

    //printing the pq elements
    while(!pq2.empty()){
        cout<<pq2.top()<<" ";
        pq2.pop();
    }
    return 0;
}
