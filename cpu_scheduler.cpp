#include "cpu_scheduler.h"
//#include "data_processing.h"
#include<iostream>

int main(){
  const string filename = "testdata/testdata1.txt";
  string stats;

  if(file_exist(filename))
    text_to_array(filename);

  get_data();

  if(algorithm == "FCFS"){
    sort_arrival_time();
    fcfs_scheduling(file_processes, process_count);
    stats = create_stats_string();
    cout<<stats;
  }
  if(algorithm == "SRTF"){

  }
  if(algorithm == "RR"){
    //rr_scheduling(process_count);
  }

  //write_in_the_file();

  return 0;
}
