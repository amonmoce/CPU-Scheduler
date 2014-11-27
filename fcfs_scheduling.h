#ifndef FCFS_SCHEDULING_H
#define FCFS_SCHEDULING_H

#include "cpu_scheduler.h"

void fcfs_scheduling(struct process *processes, int number_processes){
  int clock_time = 0, done_process_num = 0, smallest_arrival;
  Scheduled_Process p;
  
  while(done_process_num != number_processes){
    if(processes->arrival_time > clock_time)
      clock_time=processes->arrival_time+processes->burst_time;
    else
      clock_time+=processes->burst_time;
    average_waiting_time+=clock_time-processes->arrival_time-processes->burst_time;
    average_turnaround_time+=clock_time-processes->arrival_time;

    p.scheduled_process_name = processes->name;
    p.start = clock_time - processes->burst_time;
    p.end = clock_time;

    gantt[done_process_num++] = p;
    processes++;
  }
  average_waiting_time/=number_processes;
  average_turnaround_time/=number_processes;
}


#endif
