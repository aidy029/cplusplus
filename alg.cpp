#include <iostream>
#include <string>
using namespace std;
void permutation(int arr[],int s,int len){
	if(s == len){
		for(int j=0;j<len;j++){
			cout<<arr[j]
		}
		cout<<endl;
	}else{
		for(int i=s;i<len;i++){
			swap(arr[i],arr[s]);
			permutation(arr,s+1,len);
			swap(arr[i],arr[s]);
		}
	}
}

int f(int n){
	if(n <= 2) return n ;
	int x = f(n-1) + f(n-2);
	return x;
}

int main(){
    int arr[7] = {4,1,5,2,6,8,23};
    permutation(arr,0,6);
	for(int i=0;i<7;i++){
		cout << arr[i] <<" ";
	}
	cout<<f(5)<<endl;
}