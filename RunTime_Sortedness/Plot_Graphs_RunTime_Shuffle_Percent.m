clear all
close all
clc
% ///////////////////////////////////////insertionSort 
mex insertionSort.cpp
pause(.0001)
insertionSort();
insertionSort_Shuffle_Percent_RunTime_ms = ans;
save InsertionSort_RunTime_Shuffle_Percent.mat insertionSort_Shuffle_Percent_RunTime_ms
disp(string('insertionSort finished'));
% ///////////////////////////////////////bubbleSort
mex bubbleSort.cpp
pause(.0001)
bubbleSort();
bubbleSort_Shuffle_Percent_RunTime_ms = ans;
save BubbleSort_RunTime_Shuffle_Percent.mat bubbleSort_Shuffle_Percent_RunTime_ms
disp(string('bubbleSort finished'));
% ///////////////////////////////////////selectionSort
mex selectionSort.cpp
pause(.0001)
selectionSort();
selectionSort_Shuffle_Percent_RunTime_ms = ans;
save SelectionSort_RunTime_Shuffle_Percent.mat selectionSort_Shuffle_Percent_RunTime_ms
disp(string('selectionSort finished'));
% ///////////////////////////////////////quickSort
mex quickSort.cpp
pause(.0001)
quickSort();
quickSort_Shuffle_Percent_RunTime_ms = ans;
save QuickSort_RunTime_Shuffle_Percent.mat quickSort_Shuffle_Percent_RunTime_ms
disp(string('quickSort finished'));
% ///////////////////////////////////////mergeSort
mex mergeSort.cpp
pause(.0001)
mergeSort();
mergeSort_Shuffle_Percent_RunTime_ms = ans;
save MergeSort_RunTime_Shuffle_Percent.mat mergeSort_Shuffle_Percent_RunTime_ms
disp(string('mergeSort finished'));
%/////////////////////////////////////// Load Captured Datas (Copy in this directory from Simulation Results file)
% load InsertionSort_RunTime_Shuffle_Percent.mat
% load BubbleSort_RunTime_Shuffle_Percent.mat
% load SelectionSort_RunTime_Shuffle_Percent.mat
% load QuickSort_RunTime_Shuffle_Percent.mat
% load MergeSort_RunTime_Shuffle_Percent.mat
% /////////////////////////////////////// Plot Graphs
Shuffle_Percent= [0 25 50 75 100];
plot (Shuffle_Percent,insertionSort_Shuffle_Percent_RunTime_ms(2,:),'r');
hold on
plot (Shuffle_Percent,bubbleSort_Shuffle_Percent_RunTime_ms(2,:),'b');
hold on
plot (Shuffle_Percent,selectionSort_Shuffle_Percent_RunTime_ms(2,:),'m');
hold on
plot (Shuffle_Percent,quickSort_Shuffle_Percent_RunTime_ms(2,:),'-*');
hold on
plot (Shuffle_Percent,mergeSort_Shuffle_Percent_RunTime_ms(2,:),'g');

title('Dataset Model:Synth 2')
xlabel('Percent of Shuffle')
ylabel('Run Time (in ms)')
legend('Insertion Sort','Bubble Sort','Selection Sort','Quick Sort','Merge Sort');
