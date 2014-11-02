#ifndef SRTF_SCHEDULING_H
#define SRTF_SCHEDULING_H

#include "cpu_scheduler.h"

void srtf_scheduling(struct process *processes, int number_processes){
  int clock, i = 0, j = 0, old, next = 0, start = 0, burt_time_total = 0, scheduled_processes = 0;
  int process_end[max_number_of_processes];
  Scheduled_Process p;

  for(int l=0; l<number_processes; l++)
    burt_time_total += processes[l].burst_time;

  for(clock = 0; clock <= burt_time_total; clock++){
    //cout<<next<<endl;
      old = next;
      for(int m = 0; m < number_processes; m++)
        if(processes[m].burst_time != 0 ){
          next = m;
          break;
        }
      for(int n = 0; n < number_processes; n++){
        if(processes[n].burst_time != 0)
          if(processes[n].burst_time < processes[next].burst_time
            && processes[n].arrival_time <= clock ){
              next = n;
              start = processes[next].burst_time;
            }

      }

      if(old != next || clock == 0){
        processes[next].burst_time--;
        start = processes[old].burst_time - start;
        //clock = processes[next].burst_time;
        p.start = clock;
        if(clock != 0)
          process_end[j++] = clock;
        p.scheduled_process_name = processes[next].name;
        gantt[scheduled_processes++] = p;
      }
      else{
        processes[next].burst_time--;
      }

      if(clock == burt_time_total)
        process_end[j++] = clock;
  }
  for(int k=0; k<j;k++)
    gantt[k].end = process_end[k];
    
  srft_stats = create_stats_string(scheduled_processes);

}

#endif
