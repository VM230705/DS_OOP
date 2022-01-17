#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <ctime>

# define INF 0x3f3f3f3f


using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    // Create temp arrays
    int L[n1], R[n2];
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    // Merge the temp arrays back into arr[left..right]
    // Initial index of first subarray
    int i = 0;
    // Initial index of second subarray
    int j = 0; 
    // Initial index of merged subarray
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int left ,int right){
    int mid;
    if(left<right){
        mid = (left+right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

void printArray(int a[],int size){
    for(int i=0;i<size;i++){
        cout << a[i] <<" ";
    }
    cout << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int num,count=0;
    double start,end,duration, mintime = INF, maxtime = 0;
    std::vector<double> time;
    double total_time=0;

    while(cin>>num && num!=0){
        int *arr = new int[num];
        for(int i=0;i<num;i++){
            cin >> arr[i];
        }
        start = clock();
        //cout <<start << endl;

        mergeSort(arr,0,num-1);
        end = clock();
        //cout <<end << endl;

        //cout << endl << endl << endl; 
        printArray(arr,num);
        //cout << endl << endl << endl; 
        duration = (end - start) / CLOCKS_PER_SEC;
        //cout << duration << endl;

        if(duration<mintime && duration>0){
            mintime = duration;
        }
        if(duration>maxtime){
            maxtime = duration;
        }
        if(duration!=0){
            total_time += duration;
            count++;
        }
        time.push_back(duration); 
    }
    //cout << "Average time = " << total_time/count << endl;
    //cout << "Fastest time = " << mintime << endl;
    //cout << "Slowest time = " << maxtime << endl;

    return 0;
}