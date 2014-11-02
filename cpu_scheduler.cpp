#include "fcfs_scheduling.h"
#include "rr_scheduling.h"
#include "srtf_scheduling.h"
//#include "data_processing.h"
#include<iostream>

int main(){
  //const string filename = "testdata/testdata6.txt";
  string filename;
  string stats;
//while(1){
  cout<<"Type the location of the file ";
  cin>>filename;

  if(file_exist(filename))
    text_to_array(filename);
  else
    cout<<"This file does not exist"<<endl;

  get_data();

  if(algorithm == "FCFS"){
    sort_arrival_time();
    fcfs_scheduling(file_processes, process_count);
    stats = create_stats_string(process_count);
    //cout<<stats;
    write_in_the_file("0116251.txt", stats);
  }

  if(algorithm == "RR"){
    sort_arrival_time();
    rr_scheduling(file_processes, process_count);
    stats = create_stats_string(scheduled_processes);
    //cout<<stats;
    write_in_the_file("0116251.txt", stats);
    //cout<<scheduled_processes<<endl;
    //for(int i=0; i<scheduled_processes; i++)
      //cout<<gantt[i].scheduled_process_name<<endl;
  }

  if(algorithm == "SRTF"){
    sort_arrival_and_burst_time();
    srtf_scheduling(file_processes, process_count);
    //cout<<srft_stats;
    write_in_the_file("0116251.txt", srft_stats);
    //for(int i=0; i<scheduled_processes; i++)
      //cout<<gantt[i].scheduled_process_name<<endl;
  }

  //write_in_the_file();
//}
  return 0;
}
