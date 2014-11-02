#ifndef SRTF_SCHEDULING_H
#define SRTF_SCHEDULING_H

#include "cpu_scheduler.h"

void srtf_scheduling(struct process *processes, int number_processes){
  int clock = 0, i = 0, j = 0, preempted_processes = 0, scheduled_processes = number_processes;
  Scheduled_Process p;
  struct process *preempted;
  /*while(i != scheduled_processes){
    //if(preempted_processes == 0){
      int next = i + 1;
      p.scheduled_process_name = processes[i].name;
      if (clock >= processes[i].arrival_time)
        p.start = clock;
      else
        p.start = processes[i].arrival_time;
      if(processes[next].arrival_time < processes[i].burst_time){
        if(processes[i].burst_time > processes[next].burst_time){
          p.end = p.start + processes[next].arrival_time;
          processes[i].burst_time -= processes[next].arrival_time;
          preempted[preempted_processes++] = processes[i++];
          scheduled_processes++;
        }
        else{
          preempted[preempted_processes++] = processes[next];
          scheduled_processes++;
          i+=2;
        }
      }
      else{
          p.end = p.start + processes[next].burst_time;
          processes[next].burst_time = 0;
          i++;
      }
    }
    else{
      for(int l=0; l<preempted_processes; l++){
          if(preempted[l].burst_time < processes[i].burst_time){

          }
      }
    }
  clock = p.end;
  gantt[j++] = p;

}*/
}

#endif
