#ifndef SRTF_SCHEDULING_H
#define SRTF_SCHEDULING_H

#include "cpu_scheduler.h"

void srtf_scheduling(struct process *processes, int number_processes){
  int clock, i = 0, j = 0, old, next = 0, burt_time_total = 0, scheduled_processes = number_processes;
  Scheduled_Process p;

  for(int l=0; l<number_processes; l++)
    burt_time_total = processes[l].burst_time;

  for(clock = 0; clock < burt_time_total; clock++){
      old = next;
      for(int m = 0; m < number_processes; m++)
        if(processes[m].burst_time == 0 ){
          next = m;
          break;
        }
      for(int n = 0; n < number_processes; n++){
        if(processes[n].burst_time != 0)
          if(processes[n].burst_time < processes[next].burst_time
            && processes[n].arrival_time <= clock)
      }

      next =

  }

}

#endif
