// Kth smallest element 

int partition(int arr[], int l, int r, int pivot) {
    int i=l, j=l;

    for(i=l;i<r;i++) {
        if(arr[i]==pivot) {
            swap(arr[i], arr[r]);
            break;
        }
    }

    i= l;
    while(j<r) {
        if(arr[j]<=arr[r]) {
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
    swap(arr[i], arr[r]);
    return i;
}

int getMedian(int arr[], int n) {
    sort(arr, arr+n);
    return arr[n/2];
}

int kthSmallest(int arr[], int l, int r, int k) {

    int i, n=r-l+1;
    int median[(n+4)/5];
    for(i=0; i<n/5;i++) {
        median[i] = getMedian(arr+l+i*5, 5);
    }

    if(i*5<n) {
        median[i] = getMedian(arr+l+i*5, n%5);
        i++;
    }

    int medOfMed = (i==1)?median[i-1]: kthSmallest(median, 0, i-1, i/2); // i/2 is just to find median of median array

    int pos = partition(arr, l, r, medOfMed);

    if(pos+1 == k) return arr[pos];
    else if(pos+1 < k) return kthSmallest(arr, pos+1, r, k);
    else return kthSmallest(arr, l, pos-1, k);

}
