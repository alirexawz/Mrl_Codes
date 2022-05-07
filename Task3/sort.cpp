#include <iostream>

using namespace std;

void Bubble_sort(int *array,int size);
void insertion_sort(int *array,int size);
void mergeSort(int *array, int  begin, int  end);
void merge(int *array, int  left, int  mid, int  right);
void quickSort(int *array, int low, int high);
int partition (int *array, int low, int high);
void swap(int* a, int* b);
void printArray(int *arr , int size);

int main()
{
    int *array,size,choice;
    int number;
	cout<<"Enter the size of array : ";cin>>size;
	array = new int[size];
	cout<<"Randomly Enter "<<size<<" Number : \n";
	for(int i=0;i<size;i++){
		cin>>number;
		array[i] = number;
	}
    cout<<"Which sort do you want?"<<endl;
    cout<<"Bubble sort=1 ,insertion_sort=2,Merge sort=3,quickSort=4"<<endl;
    cin >>choice;
    switch (choice)
    {
    case 1:
        Bubble_sort(array,size);
        break;
    case 2:
       insertion_sort(array,size);
        break;

    case 3:
       mergeSort(array,0,size);
    case 4:
       quickSort(array,0,size-1);
    default:
          break;
    }
    	
    for (auto i = 0; i < size; i++)
        cout <<array[i] << " ";   
}


void Bubble_sort(int *array,int size){
    int tmp;
	for(int i=0;i<size-1;i++)
		for(int j=0;j<size-1;j++)
			if(array[j]>array[j+1]){
				tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
			}

            
}
void insertion_sort(int *array,int size)
{
    int tmp;
    for (int i = 1; i < size; i++)
    {
        tmp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > tmp){
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = tmp;
    }

}
void mergeSort(int *array, int  begin, int  end)
{
    if (begin >= end)
        return; // Returns recursively
  
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
void merge(int *array, int  left, int  mid, int  right)
{
    int  subArrayOne = mid - left + 1;
    int  subArrayTwo = right - mid;

    int *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
  
    
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
  
    int indexOfSubArrayOne = 0, 
        indexOfSubArrayTwo = 0; 
    int indexOfMergedArray = left; 
  
  
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int *arr, int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1); 
 
    for (int j = low; j <= high - 1; j++)
    {
       
        if (arr[j] < pivot)
        {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(int *arr , int size)
{
    for (auto i = 0; i <= size; i++)
        cout <<arr[i] << " ";
}
