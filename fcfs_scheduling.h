#ifndef FCFS_SCHEDULING_H
#define FCFS_SCHEDULING_H

#include "cpu_scheduler.h"

void fcfs_scheduling(struct process *processes, int number_processes){
  int clock_time = 0, done_process_num = 0, smallest_arrival;
  Scheduled_Process p;

  //Doing Mine from inspiration
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
  //End Doing Mine

  /*
  for(int i=0; i<number_processes; i++){
    p.scheduled_process_name = processes->name;
    if (clock >= processes->arrival_time)
      p.start = clock;
    else
      p.start = processes->arrival_time;
    p.end = p.start + processes->burst_time;
    average_turnaround_time += p.end - processes->arrival_time;
    //if (clock >= processes->arrival_time)
      average_waiting_time += p.start - processes->arrival_time;
    //else
      //average_waiting_time += p.start;
    clock = p.end;
    gantt[i] = p;
    processes++;
  }
  average_waiting_time/=number_processes;
  average_turnaround_time/=number_processes;

  */
}


#endif
