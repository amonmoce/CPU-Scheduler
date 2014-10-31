#ifndef CPU_SCHEDULER_H
#define CPU_SCHEDULER_H

#include "data_processing.h"
//A enlever plus tard
#include <iostream>
typedef struct scheduled_process{
  string scheduled_process_name;
  int start,end;
}Scheduled_Process;
Scheduled_Process gantt[max_number_of_processes];
float average_waiting_time = 0, average_turnaround_time = 0;
int scheduled_processes;

void fcfs_scheduling(struct process *processes, int number_processes){
  int clock = 0;
  Scheduled_Process p;
  for(int i=0; i<number_processes; i++){
    p.scheduled_process_name = processes->name;
    if (clock >= processes->arrival_time)
      p.start = clock;
    else
      p.start = processes->arrival_time;
    p.end = p.start + processes->burst_time;
    average_turnaround_time += p.end - processes->arrival_time;
    if (clock >= processes->arrival_time)
      average_waiting_time += p.start - processes->arrival_time;
    else
      average_waiting_time += p.start;
    clock = p.end;
    gantt[i] = p;
    processes++;
  }
  average_waiting_time/=number_processes;
  average_turnaround_time/=number_processes;
}

void rr_scheduling(struct process *processes, int number_processes){
    int clock = 0, i = 0, j = 0, k = 0;
    scheduled_processes = number_processes;
    Scheduled_Process p;
    string rescheduling_process_name[max_number_of_processes];
    int rescheduling_process_end[max_number_of_processes];
    int rescheduling_process_arrival[max_number_of_processes];
      while(i != scheduled_processes){
        if(processes[i].burst_time != 0){
          p.scheduled_process_name = processes[i].name;
          if (clock >= processes[i].arrival_time)
            p.start = clock;
          else
            p.start = processes[i].arrival_time;
          if(processes[i].burst_time > time_quantum){
            p.end = p.start + time_quantum;
            processes[i].burst_time -= time_quantum;
            processes[scheduled_processes++] = processes[i];
            rescheduling_process_name[k++] = processes[i].name;
            rescheduling_process_end[k++] = p.end;
            rescheduling_process_arrival[k++] = processes[i].arrival_time;
          }
          else{
            p.end = p.start + processes[i].burst_time;
            processes[i].burst_time = 0;
          }

          if(processes[i].burst_time == 0)
          average_turnaround_time += p.end - processes->arrival_time;
          if (clock >= processes->arrival_time)
            average_waiting_time += p.start - processes->arrival_time;
          //else
          //  average_waiting_time += p.start;
          clock = p.end;
          gantt[j++] = p;
            i++;
        }
        else
          i++;
      }
      average_turnaround_time/=number_processes;
}

void srtf_scheduling(struct process *processes, int number_processes){

}

bool string_exist(string *namelist, int length, string wanted){
  for(int i=0; i<length; i++)
    if(namelist[i] == wanted){
      return true;
      break;
    }
    else
      return false;
}

string create_stats_string(int gantt_processes){
  string gantt_data;
  //Use of setprecision for the number of decimal for floating point outputs
  //Use of function to know if there is a floating point output or not
  //like taking the value, get its integer and make (value - its integer)
  //if the result is 0.000 then it's not a floating point output
  for(int i=0; i<gantt_processes; i++){
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
