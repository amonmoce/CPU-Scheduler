#ifndef CPU_SCHEDULER_H
#define CPU_SCHEDULER_H

#include<string>
using namespace std;
typedef struct scheduled_process{
  string scheduled_process_name;
  int start,end;
}Scheduled_Process;

void fcfs_scheduling( struct process *, int );
void rr_scheduling( int );

#endif
