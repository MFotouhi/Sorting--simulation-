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

unsigned int input_arr_0[20000];
unsigned int input_arr_25[20000];
unsigned int input_arr_50[20000];
unsigned int input_arr_75[20000];
unsigned int input_arr_100[20000];

 void swap(unsigned int xp[],unsigned int ypp[]) 
{ 
    unsigned int temp = *xp; 
    *xp = *ypp; 
    *ypp = temp; 
} 
 
void merge(unsigned int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}


/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(unsigned int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}


void mexFunction( int nlhs, mxArray *plhs[],
        int nrhs, const mxArray*prhs[] )
        
{
    unsigned int  counter = 0;
    FILE *fp;
    char str[2000000];
    
    char* filename = "C:\\Sorting Project\\Code\\RunTime_Sortedness\\Dataset2_Rand_Sorted.txt";
    
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
    unsigned int j = 0;
    unsigned int data_size ;
    
    double *Shuffle_Percent_RunTime;
    yp = mxCreateDoubleMatrix( 2, 5, mxREAL);
    Shuffle_Percent_RunTime = mxGetPr(yp);
    
    data_size = 20000;

    int Shuffle_Percent;
    int Mont_Carlo_Num = 5;
    for(int Mcount =0;Mcount<Mont_Carlo_Num;Mcount++){
        printf("MontCarlo Count = %d\r\n",Mcount);

   ///////////////////////////////////////////  Shuffle Percent = 0
    Shuffle_Percent = 0;
    for(co=0;co<data_size;co++){
        input_arr_0[co] = input_arr[co]; 
    }
    
    for (co = 0;co <(Shuffle_Percent*data_size/100/2 );co++){
    j = round(Shuffle_Percent*data_size/100)-co;
    swap(&input_arr_0[co],&input_arr_0[j]);
    }
    
    start = clock();
    mergeSort(input_arr_0,0,data_size-1); 
    end = clock(); 
    
   // Calculation RunTime
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   Shuffle_Percent_RunTime[0] = Shuffle_Percent_RunTime[0]+Shuffle_Percent;
   Shuffle_Percent_RunTime[1] =Shuffle_Percent_RunTime[1]+ cpu_time_used*1000;
   printf( "\n Shuffle_Percent = %d\n", Shuffle_Percent );
   printf( "\n RunTime = %f sec\n", cpu_time_used );
   printf( "/////////////////////////\n");
       ///////////////////////////////////////////  Shuffle Percent = 25
   Shuffle_Percent =25;
    for(co=0;co<data_size;co++){
        input_arr_25[co] = input_arr[co]; 
    }

    for (co = 0;co < (Shuffle_Percent*data_size/100/2)-1;co++){
    j = round(Shuffle_Percent*data_size/100)-co;
    swap(&input_arr_25[co],&input_arr_25[j]);
    }

    start = clock();
    mergeSort(input_arr_25,0,data_size-1); 
    end = clock(); 
    
   // Calculation RunTime
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   Shuffle_Percent_RunTime[2] = Shuffle_Percent_RunTime[2]+Shuffle_Percent ;
   Shuffle_Percent_RunTime[3] =Shuffle_Percent_RunTime[3]+ cpu_time_used*1000;
   printf( "\n Shuffle_Percent = %d\n", Shuffle_Percent );
   printf( "\n RunTime = %f sec\n", cpu_time_used );
   printf( "/////////////////////////\n");
       ///////////////////////////////////////////  Shuffle Percent = 50
   Shuffle_Percent = 50;
    for(co=0;co<data_size;co++){
        input_arr_50[co] = input_arr[co]; 
    }
    
     for (co = 0;co < (Shuffle_Percent*data_size/100/2)-1;co++){
    j = round(Shuffle_Percent*data_size/100)-co;
    swap(&input_arr_50[co],&input_arr_50[j]);
    }
   
    start = clock();
    mergeSort(input_arr_50,0,data_size-1); 
    end = clock(); 
    
   // Calculation RunTime
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   Shuffle_Percent_RunTime[4] =Shuffle_Percent_RunTime[4]+Shuffle_Percent;
   Shuffle_Percent_RunTime[5] =Shuffle_Percent_RunTime[5]+ cpu_time_used*1000;
   printf( "\n Shuffle_Percent = %d\n", Shuffle_Percent );
   printf( "\n RunTime = %f sec\n", cpu_time_used );
   printf( "/////////////////////////\n");
       ///////////////////////////////////////////  Shuffle Percent = 75
   Shuffle_Percent = 75;
    for(co=0;co<data_size;co++){
        input_arr_75[co] = input_arr[co]; 
    }
    for (co = 0;co < (Shuffle_Percent*data_size/100/2)-1;co++){
    j = round(Shuffle_Percent*data_size/100)-co;
    swap(&input_arr_75[co],&input_arr_75[j]);
    }
   
    start = clock();
    mergeSort(input_arr_75,0,data_size-1); 
    end = clock(); 
    
   // Calculation RunTime
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   Shuffle_Percent_RunTime[6] =Shuffle_Percent_RunTime[6]+Shuffle_Percent;
   Shuffle_Percent_RunTime[7] =Shuffle_Percent_RunTime[7]+ cpu_time_used*1000;
   printf( "\n Shuffle_Percent = %d\n", Shuffle_Percent );
   printf( "\n RunTime = %f sec\n", cpu_time_used );
   printf( "/////////////////////////\n");
       ///////////////////////////////////////////  Shuffle Percent = 100
   Shuffle_Percent = 100;
    for(co=0;co<data_size;co++){
        input_arr_100[co] = input_arr[co]; 
    }
   
    for (co = 0;co < (Shuffle_Percent*data_size/100/2)-1;co++){
    j = round(Shuffle_Percent*data_size/100)-co;
    swap(&input_arr_100[co],&input_arr_100[j]);
    }
   
    
    start = clock();
    mergeSort(input_arr_100,0,data_size-1); 
    end = clock(); 
    
   // Calculation RunTime
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   Shuffle_Percent_RunTime[8] =Shuffle_Percent_RunTime[8]+Shuffle_Percent;
   Shuffle_Percent_RunTime[9] =Shuffle_Percent_RunTime[9]+ cpu_time_used*1000;
   printf( "\n Shuffle_Percent = %d\n", Shuffle_Percent );
   printf( "\n RunTime = %f sec\n", cpu_time_used );
   printf( "/////////////////////////\n");
    }
    
   for(int j =0;j<10;j++){
       Shuffle_Percent_RunTime[j] = Shuffle_Percent_RunTime[j]/Mont_Carlo_Num;
        }

     
    return;
    
}





