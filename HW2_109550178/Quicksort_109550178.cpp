#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <ctime>
#include <fstream>

# define INF 0x3f3f3f3f

using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[],int start,int end){
	//i is use to count the position where pivot should be placed 
	int pivot = a[end];
	int i = start-1;	
	for(int j=start; j <= end-1; j++){
		if(a[j]<pivot){
			i++;
			swap(&a[i],&a[j]);
		}
	}

	//let pivot swap to right position
	swap(&a[i+1],&a[end]);
	return i+1;
}

void quickSort(int a[],int start,int end){
	int pi;		//pi
	if(start<end){
		pi = partition(a,start,end);
		quickSort(a,start,pi-1);
		quickSort(a,pi+1,end);
	}
}

void printArray(int a[],int size){
	for(int i=0;i<size;i++){
		cout << a[i] <<" ";
	}
	cout << endl;
	//cout << size << " numbers in total " <<endl <<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
	int num,count=0;
	double start,end,duration, mintime=INF, maxtime = 0;
	std::vector<double> time;
	double total_time=0;

	while(cin>>num && num!=0){
		int *arr = new int[num];
		
		for(int i=0;i<num;i++){
			cin >> arr[i];
			if(arr[i] == -999999){
				cout << endl << "now = " << i <<endl;
			}
		}

		start = clock();
		//cout <<start << endl;
		quickSort(arr,0,num-1);
		end = clock();
		//cout <<end << endl;
		
		cout << endl << endl << endl; 
		printArray(arr,num);
		cout << endl << endl << endl; 
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