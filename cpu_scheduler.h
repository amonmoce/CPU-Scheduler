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
