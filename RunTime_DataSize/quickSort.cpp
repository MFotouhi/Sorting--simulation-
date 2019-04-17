/*=================================================================
 *
 * YPRIME.C	Sample .MEX file corresponding to YPRIME.M
 *	        Solves simple 3 body orbit problem
 *
 * The calling syntax is:
 *
 *		[yp] = yprime(t, y)
 *
 *  You may also want to look at the corresponding M-code, yprime.m.
 *
 * This is a MEX-file for MATLAB.
 * Copyright 1984-2011 The MathWorks, Inc.
 *
 *=================================================================*/
#include <math.h>
#include "mex.h"

#include <stdio.h>
#include <string.h>
#include <time.h>

#include <unistd.h>
#include <stdlib.h>

#define	yp  plhs[0]

clock_t  start,end;

double cpu_time_used;
unsigned int input_arr[1020000];

unsigned int input_arr_1000[1000];
unsigned int input_arr_10000[10000];
unsigned int input_arr_20000[20000];
unsigned int input_arr_30000[30000];
unsigned int input_arr_50000[50000];

 void swap(unsigned int xp[],unsigned int ypp[]) 
{ 
    unsigned int temp = *xp; 
    *xp = *ypp; 
    *ypp = temp; 
} 
 
int partition (unsigned int arr[], unsigned int low, unsigned int high) 
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


void mexFunction( int nlhs, mxArray *plhs[],
        int nrhs, const mxArray*prhs[] )
        
{
    unsigned int  counter = 0;
    FILE *fp;
    char str[2000000];
    
    char* filename = "C:\\Sorting Project\\Code\\RunTime_DataSize\\Dataset2_Rand.txt";
    
    fp = fopen(filename, "r");
    unsigned int array_length =0;
   
    while (fscanf(fp, "%s", str)!=EOF){
        array_length = array_length+1;
    }
    printf("array_length = %d\r\n",array_length);
    
    fp = fopen(filename, "r");
    for(unsigned int i=0;i<array_length;i++){
        fscanf(fp, "%s", str);
        input_arr[counter] = atoi(str);
        counter=counter+1;
        
    }
    fclose(fp);
    unsigned int co = 0;
    unsigned int data_size ;
    
    double *DataSize_RunTime;
    yp = mxCreateDoubleMatrix( 2, 5, mxREAL);
    DataSize_RunTime = mxGetPr(yp);
    
    int Mont_Carlo_Num = 5;
    for(int Mcount =0;Mcount<Mont_Carlo_Num;Mcount++){
   ///////////////////////////////////////////  Data Size=1000
    data_size = 1000;
    for(co=0;co<data_size;co++){
        input_arr_1000[co] = input_arr[co]; 
    }
    
    start = clock();
    quickSort(input_arr_1000,0,data_size-1); 
    end = clock(); 
    
   // Calculation RunTime
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   DataSize_RunTime[0] =DataSize_RunTime[0]+ data_size;
   DataSize_RunTime[1] =DataSize_RunTime[1]+ cpu_time_used*1000;
   printf( "\n Data Size = %d\n", data_size );
   printf( "\n RunTime = %f sec\n", cpu_time_used );
   printf( "/////////////////////////\n");
       ///////////////////////////////////////////  Data Size=10000
    data_size = 10000;
    for(co=0;co<data_size;co++){
        input_arr_10000[co] = input_arr[co]; 
    }
    
    start = clock();
    quickSort(input_arr_10000,0,data_size-1); 
    end = clock(); 
    
   // Calculation RunTime
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   DataSize_RunTime[2] =DataSize_RunTime[2]+ data_size;
   DataSize_RunTime[3] =DataSize_RunTime[3]+ cpu_time_used*1000;
   printf( "\n Data Size = %d\n", data_size );
   printf( "\n RunTime = %f sec\n", cpu_time_used );
   printf( "/////////////////////////\n");
     ///////////////////////////////////////////  Data Size=20000
     data_size = 20000;
    for(co=0;co<data_size;co++){
        input_arr_20000[co] = input_arr[co]; 
    }

    start = clock();
    quickSort(input_arr_20000,0,data_size-1); 
    end = clock(); 

   // Calculation RunTime
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   DataSize_RunTime[4] =DataSize_RunTime[4]+ data_size;
   DataSize_RunTime[5] =DataSize_RunTime[5]+ cpu_time_used*1000;
   printf( "\n Data Size = %d\n", data_size );
   printf( "\n RunTime = %f sec\n", cpu_time_used );
   printf( "/////////////////////////\n");
       ///////////////////////////////////////////  Data Size=30000
    data_size = 30000;
    for(co=0;co<data_size;co++){
        input_arr_30000[co] = input_arr[co]; 
    }
    
    start = clock();
    quickSort(input_arr_30000,0,data_size-1); 
    end = clock(); 
    
   // Calculation RunTime
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   DataSize_RunTime[6] =DataSize_RunTime[6]+ data_size;
   DataSize_RunTime[7] =DataSize_RunTime[7]+ cpu_time_used*1000;
   printf( "\n Data Size = %d\n", data_size );
   printf( "\n RunTime = %f sec\n", cpu_time_used );
   printf( "/////////////////////////\n");
       ///////////////////////////////////////////  Data Size=50000
    data_size = 50000;
    for(co=0;co<data_size;co++){
        input_arr_50000[co] = input_arr[co]; 
    }
    
    start = clock();
    quickSort(input_arr_50000,0,data_size-1); 
    end = clock(); 
    
   // Calculation RunTime
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   DataSize_RunTime[8] =DataSize_RunTime[8]+ data_size;
   DataSize_RunTime[9] =DataSize_RunTime[9]+ cpu_time_used*1000;
   printf( "\n Data Size = %d\n", data_size );
   printf( "\n RunTime = %f sec\n", cpu_time_used );
   printf( "/////////////////////////\n");
    }
    
   for(int j =0;j<10;j++){
       DataSize_RunTime[j] = DataSize_RunTime[j]/Mont_Carlo_Num;
        }

     
    return;
    
}





