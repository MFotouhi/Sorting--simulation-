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
 
/*Bubble Sort Function*/
void bubbleSort(unsigned int arr[], unsigned int arr_length) 
{ 
   int i, j; 
   bool swapped; 
   for (i = 0; i < arr_length-1; i++) 
   { 
     swapped = false; 
     for (j = 0; j < arr_length-i-1; j++) 
     {  /* Replacing the elements location
           with a greater amount and lower
           index with lower element value
           and higher index at each stage */
           // Starting from the beginning of the array
        if (arr[j] > arr[j+1]) 
        { 
           swap(&arr[j], &arr[j+1]); 
           swapped = true; 
        } 
     } 
  
     // IF no two elements were swapped by inner loop, then break 
     if (swapped == false) 
        break; 
   } 
} 

