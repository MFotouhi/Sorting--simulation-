//////////////////////////////////////////////// Memory Usage - DataSize
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <windows.h>

#include "psapi.h"
#pragma comment(Linker, "Psapi.Lib")


unsigned int input_arr[1020000];

unsigned int input_arr_1000[1000];
unsigned int input_arr_10000[10000];
unsigned int input_arr_20000[20000];
unsigned int input_arr_30000[30000];


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
    
    
    int L[n1], R[n2];
    
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    
    
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
    
    
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


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

int main(){
    
    unsigned int  counter = 0;
    FILE *fp;
    char str[1020000];
    
    char* filename = "C:\\Sorting Project\\Code\\\MemoryUsage_DataSize\\Dataset4_connect.txt";
    
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
    unsigned int MemoryUsage_DataSize[4]={0};
    
    int Mont_Carlo_Num = 1;
    
    PROCESS_MEMORY_COUNTERS_EX pmc1;
    PROCESS_MEMORY_COUNTERS_EX pmc2;
    for(int Mcount =0;Mcount<Mont_Carlo_Num;Mcount++){
        // printf("MontCarlo Count = %d\r\n",Mcount);
        ///////////////////////////////////////////////////////////////////////////////////   mergeSort
        ///////////////////////////////////////////  Data Size=1000
        data_size = 1000;
        for(co=0;co<data_size;co++){
            input_arr_1000[co] = input_arr[co];
        }
        
        GetProcessMemoryInfo(GetCurrentProcess(),(PROCESS_MEMORY_COUNTERS*) &pmc1,sizeof( pmc1 ));
        mergeSort(input_arr_1000, 0,data_size-1);
        GetProcessMemoryInfo(GetCurrentProcess(),(PROCESS_MEMORY_COUNTERS*) &pmc2,sizeof( pmc2 ));
        //printf(" Delta PrivateUsage : %d\n", pmc2.PrivateUsage - pmc1.PrivateUsage);
        
        MemoryUsage_DataSize[0] =MemoryUsage_DataSize[0]+ (pmc2.PrivateUsage - pmc1.PrivateUsage);
        ///////////////////////////////////////////  Data Size=10000
        data_size = 10000;
        for(co=0;co<data_size;co++){
            input_arr_10000[co] = input_arr[co];
        }
        
      
        mergeSort(input_arr_10000, 0,data_size-1);
        GetProcessMemoryInfo(GetCurrentProcess(),(PROCESS_MEMORY_COUNTERS*) &pmc2,sizeof( pmc2 ));
        //printf(" Delta PrivateUsage : %d\n", pmc2.PrivateUsage - pmc1.PrivateUsage);
        
        MemoryUsage_DataSize[1] =MemoryUsage_DataSize[1]+ (pmc2.PrivateUsage - pmc1.PrivateUsage);
        ///////////////////////////////////////////  Data Size=20000
        data_size = 20000;
        for(co=0;co<data_size;co++){
            input_arr_20000[co] = input_arr[co];
        }
        
        mergeSort(input_arr_20000, 0,data_size-1);
        GetProcessMemoryInfo(GetCurrentProcess(),(PROCESS_MEMORY_COUNTERS*) &pmc2,sizeof( pmc2 ));
        //printf(" Delta PrivateUsage : %d\n", pmc2.PrivateUsage - pmc1.PrivateUsage);
        
        MemoryUsage_DataSize[2] =MemoryUsage_DataSize[2]+ (pmc2.PrivateUsage - pmc1.PrivateUsage);
        ///////////////////////////////////////////  Data Size=30000
        data_size = 30000;
        for(co=0;co<data_size;co++){
            input_arr_30000[co] = input_arr[co];
        }
        
        mergeSort(input_arr_30000, 0,data_size-1);
        GetProcessMemoryInfo(GetCurrentProcess(),(PROCESS_MEMORY_COUNTERS*) &pmc2,sizeof( pmc2 ));
        //printf(" Delta PrivateUsage : %d\n", pmc2.PrivateUsage - pmc1.PrivateUsage);
        
        MemoryUsage_DataSize[3] =MemoryUsage_DataSize[3]+ (pmc2.PrivateUsage - pmc1.PrivateUsage);
        
        printf("...Merge Sorting Finished\r\n");
        
        }
        
        for(int j =0;j<4;j++){
            MemoryUsage_DataSize[j] = MemoryUsage_DataSize[j]/Mont_Carlo_Num+200000;
            printf("MemoryUsage_DataSize[%d]=%d\r\n",j, MemoryUsage_DataSize[j]);
        }
        
        
        
    
}
