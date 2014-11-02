#ifndef SRTF_SCHEDULING_H
#define SRTF_SCHEDULING_H

#include "cpu_scheduler.h"

void srtf_scheduling(struct process *processes, int number_processes){
  int clock = 0, i = 0, j = 0, rescheduling = number_processes;
  int preempted_processes = 0, scheduled_processes = number_processes, next, choice_indice;
  int smallest_burst_time_preempted = 0;
  bool on_preempted = false;
  Scheduled_Process p;
  Process preempted_list[max_number_of_processes], dispatch;
  while(i != number_processes){
    //if(preempted_processes == 0){
      cout<<processes[i].name<<" "<<processes[i].burst_time<<endl;
      if (clock >= processes[i].arrival_time){
        if(preempted_processes !=0 && processes[i].burst_time != 0){
          //if there is one or more preempted processes
          for(int m=0; m<preempted_processes; m++){
              if(preempted_list[m].burst_time < preempted_list[smallest_burst_time_preempted].burst_time)
                smallest_burst_time_preempted = m;
            }
            //cout<<"preempted"<<" "<<smallest_burst_time_preempted<<endl;
          if(preempted_list[smallest_burst_time_preempted].burst_time < processes[i].burst_time)
            on_preempted = true;
          p.start = clock;
        }
        else{//if not
          p.start = clock;
        }
      }
      else
        p.start = processes[i].arrival_time;

      if(!on_preempted){
      next = i + 1;
      p.scheduled_process_name = processes[i].name;

      if(processes[next].arrival_time < processes[i].burst_time){
        if(processes[i].burst_time > processes[next].burst_time){
          p.end = p.start + processes[next].arrival_time;
          processes[i].burst_time -= processes[next].arrival_time;
          preempted_list[preempted_processes++] = processes[i++];
          scheduled_processes++;
        }
        else{
          p.end = p.start + processes[i].burst_time;
          processes[i++].burst_time = 0;
        }
      }
      else{
          p.end = p.start + processes[i].burst_time;
          processes[i++].burst_time = 0;
      }
   }
   else{

     
   }
   clock = p.end;
   gantt[j] = p;
   cout<<gantt[j++].scheduled_process_name<<endl;
    //else{

    //  i++;
    /*  if(processes[i].arrival_time > clock){
         for(int l=0; l<scheduled_processes; l++){
           if(processes[l].arrival_time < clock
             && processes[l].burst_time != 0){

                 for(int n=0; n<scheduled_processes; n++)
                 if(processes[n].arrival_time < clock
                   && processes[n].burst_time != 0){
                   if(processes[n].burst_time < processes[l].burst_time)
                       smallest_burst_time_preempted = n;
                       //cout<<processes[n].burst_time<<endl;
                 }
             }
         }
      }
      cout<<smallest_burst_time_preempted<<endl;
      if(processes[i].arrival_time == clock){
         choice_indice = smallest_burst_time_preempted(processes, clock);

          if(choice_indice <= processes[i].burst_time){
              rescheduling = choice_indice;
               next = i;
              preempted_processes--;
          }
          else{
            rescheduling = i;
            i++;
            if(i < scheduled_processes - 1)
               next = i + 1;
          }

      }
      //cout<<choice_indice<<endl;
        p.scheduled_process_name = processes[rescheduling].name;

        if (clock >= processes[rescheduling].arrival_time)
          p.start = clock;
        else
          p.start = processes[rescheduling].arrival_time;

        if(processes[next].arrival_time < processes[rescheduling].burst_time){
          if(processes[rescheduling].burst_time > processes[next].burst_time){
            p.end = p.start + processes[next].arrival_time;
            processes[rescheduling].burst_time -= processes[next].arrival_time;
            processes[scheduled_processes++] = processes[rescheduling];
            preempted_processes++;
          }
          else{
            p.end = p.start + processes[rescheduling].burst_time;
            processes[rescheduling].burst_time = 0;
          }
        }
        else{
            p.end = p.start + processes[rescheduling].burst_time;
            processes[rescheduling].burst_time = 0;
        }

      }
      //i++;
    clock = p.end;
    //gantt[j++] = p;
    cout<<p.scheduled_process_name<<" "<<i<<" "<<clock
        <<endl;*/

//}
//cout<<p.scheduled_process_name<<endl;
  }

}

#endif
