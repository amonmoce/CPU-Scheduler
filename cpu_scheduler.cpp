//#include "cpu_scheduler.h"
#include "data_processing.h"
#include<iostream>
using namespace std;
typedef struct scheduled_process{
  string scheduled_process_name;
  int start,end;
}Scheduled_Process;
Scheduled_Process gantt[max_number_of_processes];
void fcfs_scheduling(struct process *processes, int number_processes);
int main(){
  const string filename = "testdata/testdata2.txt";

  if(file_exist(filename))
    text_to_array(filename);

  get_data();

  if(algorithm == "FCFS"){
    //D'abord sort fileprocess selon le arrival time
    fcfs_scheduling(file_processes, process_count);
  }
  if(algorithm == "SRTF"){

  }
  if(algorithm == "RR"){
    //rr_scheduling(process_count);
  }
//  cout<<algorithm<<endl;
  //for(int i=0; i<process_count;i++){
    //cout<<file_processes[i].name<<endl;
    //cout<<file_processes[i].arrival_time<<endl;
    //cout<<file_processes[i].burst_time<<endl;

  //}
  //write_in_the_file();

  return 0;
}

void fcfs_scheduling(struct process *processes, int number_processes){
  int clock = 0;
  float average_waiting_time = 0, average_turnaround_time = 0;
  Scheduled_Process p;
  for(int i=0; i<number_processes; i++){
    //average_waiting_time += clock;
    p.scheduled_process_name = processes->name;
    if (clock >= processes->arrival_time)
      p.start = clock;
    else
      p.start = processes->arrival_time;
    p.end = p.start + processes->burst_time;
    average_turnaround_time += p.end - processes->arrival_time;
    average_waiting_time += p.start - processes->arrival_time;
    cout<<p.scheduled_process_name<<"\t"<<p.start<<"-"<<p.end<<endl;
    clock = p.end;
    gantt[i] = p;
    processes++;
  }
  average_waiting_time/=number_processes;
  average_turnaround_time/=number_processes;
  cout<<average_waiting_time<<" "<<average_turnaround_time<<endl;
}
