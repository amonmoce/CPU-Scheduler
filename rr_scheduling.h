#ifndef RR_SCHEDULING_H
#define RR_SCHEDULING_H

#include "cpu_scheduler.h"

void rr_scheduling(struct process *processes, int number_processes){
    int clock = 0, i = 0, j = 0, k = 0;
    scheduled_processes = number_processes;
    Scheduled_Process p;

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
          }
          else{
            p.end = p.start + processes[i].burst_time;
            processes[i].burst_time = 0;
          }

          if(processes[i].burst_time == 0)
            average_turnaround_time += p.end - processes->arrival_time;
          clock = p.end;
          gantt[j++] = p;
            i++;
        }
        else
          i++;
      }
      int check_burst = 0, real_burst, real_arrival;
      for(int current=scheduled_processes - 1, previous = current-1; current >= 0; current--, previous--){
        check_burst += gantt[current].end - gantt[current].start;
        if(gantt[current].scheduled_process_name != gantt[previous].scheduled_process_name){
          for(int m=0; m<number_processes; m++){
            //cout<<real_burst<<endl;
            if(gantt[current].scheduled_process_name == processes[m].name)
              real_burst = processes[m].burst_time + time_quantum;
              real_arrival = processes[m].arrival_time;
          }
          //cout<<real_burst<<endl;
          if(check_burst == real_burst){
            average_waiting_time += gantt[current].start - real_arrival;
            //cout<<average_waiting_time<<gantt[current].start<<endl;
          }
          else{
            int n = current;
            while(gantt[n--].scheduled_process_name != gantt[current].scheduled_process_name) ;
            average_waiting_time += gantt[current].start - gantt[n].end - real_arrival;
            //cout<<average_waiting_time<<endl;
          }
          check_burst = 0;
        }
      }
      average_waiting_time /=number_processes;
      average_turnaround_time/=number_processes;
}



#endif
