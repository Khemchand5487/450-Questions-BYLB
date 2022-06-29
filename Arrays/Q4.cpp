// Sort an array of 0s, 1s and 2s

void sort012(int a[], int n)
    {
        int zero=0, ones=0, twos=n-1;
        while(ones<=twos) {
            if(a[ones]==0) swap(a[zero++], a[ones++]);
            else if(a[ones]==2) swap(a[ones], a[twos--]);
            else ones++;
        }
    }
