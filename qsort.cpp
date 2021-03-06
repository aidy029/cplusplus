#include <iostream>
#include <string>
using namespace std;
void qsort(int x[],int l,int u){
 if(l<u ){
  int m=l;	
  int t=x[l];
  int i=l+1;
  while(i<=u){
    if(x[i]<t){
      m=m+1;
      swap(x[m],x[i]);
    }
    i=i+1;
  }
  swap(x[l],x[m]);
  qsort(x,l,m-1);
  qsort(x,m+1,u);
 }
}

void insert_sort(int arr[],int len){
	for(int i=1;i<len;i++){
		int t = arr[i];
		int j = i - 1;
		while(arr[j]>t){
			swap(arr[j+1],arr[j]);
			j--;
		}
	}
}

int main(){
    int arr[7] = {4,1,5,2,6,8,23};
    qsort(arr,0,6);
	for(int i=0;i<7;i++){
		cout << arr[i] <<" ";
	}
}