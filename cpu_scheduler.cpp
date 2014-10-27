//#include "cpu_scheduler.h"
#include "text_processing.h"
#include<fstream>
#include<iostream>
using namespace std;
int main(){
  const string filename = "testdata/testdata1.txt";

  if(file_exist(filename))
    text_to_array(filename);


  typedef struct process{
    string name;
    int arrival_time, burst_time;
  }Process;

//  for(int i=0; i<word_count; i++)
  //  cout<<words[i];

  //write_in_the_file();

  return 0;
}
