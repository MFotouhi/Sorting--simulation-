#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
            
/*Swap Function*/
 void swap(unsigned int *xp,unsigned int *yp) 
{ 
   unsigned int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (unsigned int arr[],unsigned int low,unsigned int high) 
{ 
   unsigned int pivot = arr[high];    // pivot 
   unsigned int i = (low - 1);  // Index of smaller element 
  
    for (unsigned int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
 /*Quick Sort Function*/
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(unsigned int arr[],unsigned int low,unsigned int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
      unsigned int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}
