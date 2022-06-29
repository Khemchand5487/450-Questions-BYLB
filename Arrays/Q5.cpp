// Move all negative numbers to beginning and positive to end with constant extra space

#include <bits/stdc++.h>

using namespace std;

void moveNegative(int arr[], int n) {
    
    int i=0, j=0;
    while(j<n) {
        if(arr[j]<0) {
            swap(arr[i++], arr[j]);
        }
        j++;
    }
}

int main() {
	int n; cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	
	moveNegative(arr, n);
	
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	cout<<endl;
	
	return 0;
}
