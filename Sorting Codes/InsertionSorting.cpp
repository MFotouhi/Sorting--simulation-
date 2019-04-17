#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
  
/*Insertion Sort Function*/
void insertionSort(unsigned int arr[], unsigned int arr_length) 
{ 
     long int i;
     long int j;
     long int key;
     
    for (i = 1; i < arr_length; i++) 
    { 
        key = arr[i]; 
        j = i-1; 

        /*The displacement of the element with a lower value
         to the corresponding place with the lowest possible index */

        while (j >= 0 && arr[j] > key) 
        { 
            arr[j + 1] = arr[j]; // Moving elements with values greater than the representative to the next house
            j = j - 1; 
        } 

        arr[j + 1] = key;  // Element with a lower value moving to the corresponding place with the lowest index 
    }   
} 