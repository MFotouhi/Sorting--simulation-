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

/*Selection Sort Function*/
void selectionSort(unsigned int arr[],unsigned int arr_length) 
{ 
   long int i, j, min_idx; 
    /* Find the minimum amount in the remaining array
       and place it at the beginning of the array */
    for (i = 0; i < arr_length-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < arr_length; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; // finding Minimum element array value
        swap(&arr[min_idx], &arr[i]); 
    } 
} 



