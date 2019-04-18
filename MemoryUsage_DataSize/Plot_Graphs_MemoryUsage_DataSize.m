clear all
close all
clc
%/////////////////////////////////////// Load Captured Datas (Copy in this directory from Simulation Results file)
load InsertionSort_MemoryUsage.mat
load BubbleSort_MemoryUsage.mat
load SelectionSort_MemoryUsage.mat
load QuickSort_MemoryUsage.mat
load MergeSort_MemoryUsage.mat

data_size= [1000 10000 20000 30000];
%/////////////////////////////////////// Plot Graphs
plot (data_size,insertionSort_MemoryUsage,'r');
hold on
plot (data_size,bubbleSort_MemoryUsage,'b');
hold on
plot (data_size,selectionSort_MemoryUsage,'m');
hold on
plot (data_size,quickSort_MemoryUsage,'-*');
hold on
plot (data_size,mergeSort_MemoryUsage,'g');

title('Dataset Model:Real 2(Connect)')
xlabel('Data Size')
ylabel('Memory Usage(Byte)')
legend('Insertion Sort','Bubble Sort','Selection Sort','Quick Sort','Merge Sort');

