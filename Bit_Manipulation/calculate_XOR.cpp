//calculate xor of the numbers from 1 to a given integer n

#include<iostream>
using namespace std;
int calculateXor(int n){
    if(n==1) return 1;
    else if(n%4==0) return n;
    else if(n%4==1) return 1;
    else if(n%4==2) return n+1;
    else return 0;
    
}
// int main(){
//     int n;
//     cout<<"Enter a integer:";
//     cin>>n;
//     cout<<"The Xor of the numbers upto "<<n<<" is: "<<calculateXor(n);
// }

//calculate xor of the numbers in a given range from L to R

// int main(){
//     int start,end;
//     cout<<"Enter the starting and ending number: ";
//     cin>>start>>end;
//     int Xorr=calculateXor(start-1)^calculateXor(end);
//     cout<<"The xor of the numbers from "<<start<<" to "<<end<<" is:"<<Xorr;
// }