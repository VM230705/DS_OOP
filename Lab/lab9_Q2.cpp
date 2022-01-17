#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int *x, int *y);

class MinHeap
{
public:
	int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
    // Constructor
    MinHeap(int capacity);
  
    // to heapify a subtree with the root at given index
    void MinHeapify(int );
  
    int parent(int i) { return (i-1)/2; }
  
    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
  
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
  
    // to extract the root which is the minimum element
    int extractMin();
  
    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val);
  
    // Returns the minimum key (key at root) from min heap
    int getMin() { return harr[0]; }
    
    // Inserts a new key 'k'
    void insert(int k);
};

MinHeap::MinHeap(int capacity){
	this->heap_size = 0;
	this->capacity = capacity;
	harr = new int[capacity];
}

// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
  
// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
   
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
  
    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
  
    return root;
}

void MinHeap::insert(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
  
    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
  
    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i]){
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
  
// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int num,n;
	std::vector<int> cost;
	while(true){
	    cin >> num;
	    if(num>=2){
			MinHeap*h = new MinHeap(num);
			for(int i=0; i<num ; i++){
				cin >> n;
				h->insert(n);
			}
			int siz = h->heap_size;
			int sum =0;
			for(int j=0;j<siz;j++){
				sum += h->extractMin();
				if(j!=0){
					cost.push_back(sum);
				}
			}
		}
		else{
			break;
		}

		int total=0;
		for(int i =0; i<cost.size() ; i++){
			total += cost[i];
		}
		cout << total <<endl;
		cost.clear();
	}

	

    return 0;
}
