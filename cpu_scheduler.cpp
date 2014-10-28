//#include "cpu_scheduler.h"
#include "data_processing.h"
#include<iostream>
#include<string>
using namespace std;
int main(){
  const string filename = "testdata/testdata1.txt";

  if(file_exist(filename))
    text_to_array(filename);

  get_data();

  if(algorithm == "FCFS"){

  }
  if(algorithm == "SRTF"){

  }
  if(algorithm == "RR"){

  }
  cout<<algorithm<<endl;
  for(int i=0; i<process_count;i++){
    cout<<file_processes[i].name<<endl;
    cout<<file_processes[i].arrival_time<<endl;
    cout<<file_processes[i].burst_time<<endl;

  }
  //write_in_the_file();

  return 0;
}
