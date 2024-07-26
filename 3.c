#include <stdio.h> 
void fcfs(int processes[], int n, int arrival_time[], int burst_time[]) 
{ 
int waiting_time[n], turnaround_time[n],C_Time[n]; 
int total_waiting_time = 0, total_turnaround_time = 0; 
C_Time[0] = burst_time[0];
for (int i = 1; i < n; i++) 
{ 
C_Time[i] = C_Time[i-1] + burst_time[i]; 
} 
// Calculate turnaround time for each process 
for (int i = 0; i < n; i++) { 
turnaround_time[i] = C_Time[i] - arrival_time[i]; 
total_turnaround_time += turnaround_time[i]; 
} 
// Calculate waiting time for each process 
for (int i = 0; i < n; i++) { 
printf("Process\tAT\tBT\tCT\tTAT\tWT\n"); 
waiting_time[i] = turnaround_time[i] - burst_time[i]; 
total_waiting_time += waiting_time[i]; 
} 
// Print process details    
for (int i = 0; i < n; i++) { 
printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], arrival_time[i], burst_time[i], 
C_Time[i], turnaround_time[i],waiting_time[i]); 
} 
// Print average waiting time and average turnaround time 
printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / n); 
printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n); 
} 
int main() { 
int n; 
// Input number of processes 
printf("Enter the number of processes: "); 
scanf("%d", &n); 
int processes[n], arrival_time[n], burst_time[n]; 
// Input arrival time and burst time for each process 
for (int i = 0; i < n; i++) { 
printf("Enter arrival time for process %d: ", i + 1); 
scanf("%d", &arrival_time[i]); 
printf("Enter burst time for process %d: ", i + 1); 
        scanf("%d", &burst_time[i]); 
 
        processes[i] = i + 1; 
    } 
 
    // Call FCFS scheduling function 
    fcfs(processes, n, arrival_time, burst_time); 
 
    return 0; 
} 