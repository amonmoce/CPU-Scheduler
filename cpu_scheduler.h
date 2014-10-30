#ifndef CPU_SCHEDULER_H
#define CPU_SCHEDULER_H

#include "data_processing.h"
#include <iostream>
typedef struct scheduled_process{
  string scheduled_process_name;
  int start,end;
}Scheduled_Process;
Scheduled_Process gantt[max_number_of_processes];
float average_waiting_time = 0, average_turnaround_time = 0;

void fcfs_scheduling(struct process *processes, int number_processes){
  int clock = 0;
  Scheduled_Process p;
  for(int i=0; i<number_processes; i++){
    cout<<average_waiting_time<<endl;
    p.scheduled_process_name = processes->name;
    if (clock >= processes->arrival_time)
      p.start = clock;
    else
      p.start = processes->arrival_time;
    p.end = p.start + processes->burst_time;
    average_turnaround_time += p.end - processes->arrival_time;
    average_waiting_time += p.start - processes->arrival_time;
    clock = p.end;
    gantt[i] = p;
    processes++;
  }
  average_waiting_time/=number_processes;
  average_turnaround_time/=number_processes;
}

string create_stats_string(){
  string gantt_data;
  for(int i=0; i<process_count; i++){
    gantt_data.append(gantt[i].scheduled_process_name);
    gantt_data.append("\t");
    gantt_data.append(to_string(gantt[i].start));
    gantt_data.append("-");
    gantt_data.append(to_string(gantt[i].end));
    gantt_data.append("\n");
  }
  gantt_data.append("Average Waiting Time: ");
  gantt_data.append(to_string(average_waiting_time));
  gantt_data.append("\n");
  gantt_data.append("Average Turnaround Time: ");
  gantt_data.append(to_string(average_turnaround_time));
  gantt_data.append("\n");
  return gantt_data;
}
#endif
