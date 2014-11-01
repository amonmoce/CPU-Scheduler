#include "cpu_scheduler.h"
//#include "data_processing.h"
#include<iostream>

int main(){
  const string filename = "testdata/testdata5.txt";
  string stats;

  if(file_exist(filename))
    text_to_array(filename);

  get_data();

  if(algorithm == "FCFS"){
    sort_arrival_time();
    fcfs_scheduling(file_processes, process_count);
    stats = create_stats_string(process_count);
    cout<<stats;
  }

  if(algorithm == "RR"){
    sort_arrival_time();
    rr_scheduling(file_processes, process_count);
    stats = create_stats_string(scheduled_processes);
    cout<<stats;
    //cout<<scheduled_processes<<endl;
    //for(int i=0; i<scheduled_processes; i++)
      //cout<<gantt[i].scheduled_process_name<<endl;
  }

  if(algorithm == "SRTF"){
    //srtf_scheduling(file_processes, process_count);
    sort_arrival_and_burst_time();
    for(int i=0; i<process_count; i++)
      cout<<file_processes[i].name<<endl;
  }

  //write_in_the_file();

  return 0;
}
