clear all
close all
clc
% % %///////////////////////////////////////insertionSort 
% mex insertionSort.cpp
% pause(.0001)
% 
% insertionSort();
% insertionSort_DataSize_RunTime_ms = ans;
% save InsertionSort_RunTime_DataSize.mat insertionSort_DataSize_RunTime_ms
% disp(string('insertionSort finished'));
% % ///////////////////////////////////////bubbleSort
% mex bubbleSort.cpp
% pause(.0001)
% 
% bubbleSort();
% bubbleSort_DataSize_RunTime_ms = ans;
% save BubbleSort_RunTime_DataSize.mat bubbleSort_DataSize_RunTime_ms
% disp(string('bubbleSort finished'));
% % ///////////////////////////////////////selectionSort
% mex selectionSort.cpp
% pause(.0001)
% 
% selectionSort();
% selectionSort_DataSize_RunTime_ms = ans;
% save SelectionSort_RunTime_DataSize.mat selectionSort_DataSize_RunTime_ms
% disp(string('selectionSort finished'));
% % ///////////////////////////////////////quickSort
% mex quickSort.cpp
% pause(.0001)
% 
% quickSort();
% quickSort_DataSize_RunTime_ms = ans;
% save QuickSort_RunTime_DataSize.mat quickSort_DataSize_RunTime_ms
% disp(string('quickSort finished'));
% % ///////////////////////////////////////mergeSort
% mex mergeSort.cpp
% pause(.0001)
% 
% mergeSort();
% mergeSort_DataSize_RunTime_ms = ans;
% save MergeSort_RunTime_DataSize.mat mergeSort_DataSize_RunTime_ms
% disp(string('mergeSort finished'));
%/////////////////////////////////////// Load Captured Datas (Copy in this directory from Simulation Results file)
load InsertionSort_RunTime_DataSize.mat
load BubbleSort_RunTime_DataSize.mat
load SelectionSort_RunTime_DataSize.mat
load QuickSort_RunTime_DataSize.mat
load MergeSort_RunTime_DataSize.mat
% /////////////////////////////////////// Plot Graphs
data_size= [1000 10000 20000 30000 50000];
plot (data_size,insertionSort_DataSize_RunTime_ms(2,:),'r');
hold on
plot (data_size,bubbleSort_DataSize_RunTime_ms(2,:),'b');
hold on
plot (data_size,selectionSort_DataSize_RunTime_ms(2,:),'m');
hold on
plot (data_size,quickSort_DataSize_RunTime_ms(2,:),'-*');
hold on
plot (data_size,mergeSort_DataSize_RunTime_ms(2,:),'g');

title('Dataset Model:Synth 1')
xlabel('Data Size')
ylabel('Run Time (in ms)')
legend('Insertion Sort','Bubble Sort','Selection Sort','Quick Sort','Merge Sort');


