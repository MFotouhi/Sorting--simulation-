//////////////////////////////////////////////// Memory Usage - Sortedness
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

void bubbleSort(unsigned int arr[], unsigned int arr_length)
{
    int i, j;
    bool swapped;
    for (i = 0; i < arr_length-1; i++)
    {
        swapped = false;
        for (j = 0; j < arr_length-i-1; j++)
        {
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


int main(){
    
    unsigned int  counter = 0;
    FILE *fp;
    char str[1020000];
    
    char* filename = "C:\\Sorting Project\\Code\\\MemoryUsage_Sortedness\\Dataset4_connect_Sorted.txt";
    
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
    unsigned int data_size=20000 ;
    long int MemoryUsage_Shuffle_Percent[5]={0};
    
    int Mont_Carlo_Num = 1;
    int Shuffle_Percent;
    
    PROCESS_MEMORY_COUNTERS_EX pmc1;
    PROCESS_MEMORY_COUNTERS_EX pmc2;
    
    
    for(int Mcount =0;Mcount<Mont_Carlo_Num;Mcount++){
         printf("MontCarlo Count = %d\r\n",Mcount);
               
        //////////////////////////////////////////////////////////////////////////////////////   bubbleSort
        ///////////////////////////////////////////  Shuffle_Percent = 0
        Shuffle_Percent = 0;
        for(co=0;co<data_size;co++){
            input_arr_0[co] = input_arr[co];
        }
        
        for (co = 0;co <(Shuffle_Percent*data_size/100/2 );co++){
            j = round(Shuffle_Percent*data_size/100)-co;
            swap(&input_arr_0[co],&input_arr_0[j]);
        }
        GetProcessMemoryInfo(GetCurrentProcess(),(PROCESS_MEMORY_COUNTERS*) &pmc1,sizeof( pmc1 ));
        bubbleSort(input_arr_0,data_size-1);
        GetProcessMemoryInfo(GetCurrentProcess(),(PROCESS_MEMORY_COUNTERS*) &pmc2,sizeof( pmc2 ));
        //printf(" Delta PrivateUsage : %d\n", pmc2.PrivateUsage - pmc1.PrivateUsage);
        
        MemoryUsage_Shuffle_Percent[0] =MemoryUsage_Shuffle_Percent[0]+ (pmc2.PrivateUsage - pmc1.PrivateUsage);
        ///////////////////////////////////////////  Shuffle_Percent = 25
        Shuffle_Percent = 25;
        for(co=0;co<data_size;co++){
            input_arr_25[co] = input_arr[co];
        }
        
        for (co = 0;co <(Shuffle_Percent*data_size/100/2 );co++){
            j = round(Shuffle_Percent*data_size/100)-co;
            swap(&input_arr_25[co],&input_arr_25[j]);
        }
        bubbleSort(input_arr_25,data_size-1);
        GetProcessMemoryInfo(GetCurrentProcess(),(PROCESS_MEMORY_COUNTERS*) &pmc2,sizeof( pmc2 ));
        //printf(" Delta PrivateUsage : %d\n", pmc2.PrivateUsage - pmc1.PrivateUsage);
        
        MemoryUsage_Shuffle_Percent[1] =MemoryUsage_Shuffle_Percent[1]+ (pmc2.PrivateUsage - pmc1.PrivateUsage);
        ///////////////////////////////////////////  Shuffle_Percent = 50;
       Shuffle_Percent = 50;
        for(co=0;co<data_size;co++){
            input_arr_50[co] = input_arr[co];
        }
        
        for (co = 0;co <(Shuffle_Percent*data_size/100/2 );co++){
            j = round(Shuffle_Percent*data_size/100)-co;
            swap(&input_arr_50[co],&input_arr_50[j]);
        }
        bubbleSort(input_arr_50,data_size-1);
        GetProcessMemoryInfo(GetCurrentProcess(),(PROCESS_MEMORY_COUNTERS*) &pmc2,sizeof( pmc2 ));
        //printf(" Delta PrivateUsage : %d\n", pmc2.PrivateUsage - pmc1.PrivateUsage);
        
        MemoryUsage_Shuffle_Percent[2] =MemoryUsage_Shuffle_Percent[2]+ (pmc2.PrivateUsage - pmc1.PrivateUsage);
        ///////////////////////////////////////////  Shuffle_Percent = 75
       Shuffle_Percent = 75;
        for(co=0;co<data_size;co++){
            input_arr_75[co] = input_arr[co];
        }
        
        for (co = 0;co <(Shuffle_Percent*data_size/100/2 );co++){
            j = round(Shuffle_Percent*data_size/100)-co;
            swap(&input_arr_75[co],&input_arr_75[j]);
        }
        bubbleSort(input_arr_75,data_size-1);
        GetProcessMemoryInfo(GetCurrentProcess(),(PROCESS_MEMORY_COUNTERS*) &pmc2,sizeof( pmc2 ));
        //printf(" Delta PrivateUsage : %d\n", pmc2.PrivateUsage - pmc1.PrivateUsage);
        
        MemoryUsage_Shuffle_Percent[3] =MemoryUsage_Shuffle_Percent[3]+ (pmc2.PrivateUsage - pmc1.PrivateUsage);
        ///////////////////////////////////////////  Shuffle_Percent = 100
       Shuffle_Percent = 100;
        for(co=0;co<data_size;co++){
            input_arr_100[co] = input_arr[co];
        }
        
        for (co = 0;co <(Shuffle_Percent*data_size/100/2 );co++){
            j = round(Shuffle_Percent*data_size/100)-co;
            swap(&input_arr_100[co],&input_arr_100[j]);
        }

        bubbleSort(input_arr_100,data_size-1);
        GetProcessMemoryInfo(GetCurrentProcess(),(PROCESS_MEMORY_COUNTERS*) &pmc2,sizeof( pmc2 ));
        //printf(" Delta PrivateUsage : %d\n", pmc2.PrivateUsage - pmc1.PrivateUsage);
        MemoryUsage_Shuffle_Percent[4] =MemoryUsage_Shuffle_Percent[4]+ (pmc2.PrivateUsage - pmc1.PrivateUsage);
        
        printf("...Bubble Sorting Finished\r\n");
        
    }
    
    for(int j =0;j<5;j++){
        MemoryUsage_Shuffle_Percent[j] = MemoryUsage_Shuffle_Percent[j]/Mont_Carlo_Num+200000;
        printf("MemoryUsage_Shuffle_Percent[%d]=%d\r\n",j, MemoryUsage_Shuffle_Percent[j]);
    }
    
    
    
}
