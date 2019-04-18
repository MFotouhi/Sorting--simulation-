clear all
close all
clc
%/////////////////////////////////////// Load Captured Datas (Copy in this directory from Simulation Results file)
load InsertionSort_MemoryUsage.mat
load BubbleSort_MemoryUsage.mat
load SelectionSort_MemoryUsage.mat
load MergeSort_MemoryUsage.mat

Shuffle_Percent= [0 25 50 75 100];
%/////////////////////////////////////// Plot Graphs
plot (Shuffle_Percent,insertionSort_MemoryUsage,'r');
hold on
plot (Shuffle_Percent,bubbleSort_MemoryUsage,'b');
hold on
plot (Shuffle_Percent,selectionSort_MemoryUsage,'m');
hold on
plot (Shuffle_Percent,mergeSort_MemoryUsage,'g');

title('Dataset Model:Real 2(Connect)')
xlabel('Shuffle Percent')
ylabel('Memory Usage(Byte)')
legend('Insertion Sort','Bubble Sort','Selection Sort','Merge Sort');
