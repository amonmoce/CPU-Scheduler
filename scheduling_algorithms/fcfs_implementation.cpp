#include "../cpu_scheduler.h"
#include<iostream>
using namespace std;
void fcfs_scheduling(struct process *processes, int number_processes){
  for(int i=0; i<number_processes; i++){

    cout<<processes->name<<endl;
    processes++;
  }
}
