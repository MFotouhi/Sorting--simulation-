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
    quickSort(input_arr_0,0,data_size-1); 
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
    quickSort(input_arr_25,0,data_size-1); 
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
    quickSort(input_arr_50,0,data_size-1); 
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
    quickSort(input_arr_75,0,data_size-1); 
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
    quickSort(input_arr_100,0,data_size-1); 
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





