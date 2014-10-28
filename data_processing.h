#ifndef TEXT_PROCESSING_H
#define TEXT_PROCESSING_H
  #include <fstream>
  #include<string>
  using namespace std;

  const int max_number_of_words = 100;
  const int max_number_of_processes = 20;
  int word_count = 0, process_count = 0;
  string words[max_number_of_words], algorithm;
  typedef struct process{
    string name;
    int arrival_time, burst_time;
  }Process;
  Process file_processes[max_number_of_processes];

  bool file_exist(string filename){
    ifstream datafile;
    datafile.open(filename);
    if(datafile.is_open())
      return true;
    else
      return false;
  }

  void text_to_array(string filename){
    ifstream datafile;
    datafile.open(filename);
    if(datafile.is_open()){
      while(!datafile.eof()){
          datafile >> words[word_count++];
      }
    }
  }

  void get_data(){
    Process p;
    int i, time_quantum;
    algorithm = words[2];
    if(algorithm == "RR"){
      i=4;
      time_quantum = stoi(words[3]);
    }
    else
      i=3;
    for(int j=0; i<word_count; i++, j++){
        if(j==7){
          file_processes[process_count++] = p;
          j=0;
        }
        if(j==0 )
          p.name = words[i];
        if(j==3)
          p.arrival_time = stoi(words[i]);
        if(j==6)
          p.burst_time = stoi(words[i]);
    }
  }

  void write_in_the_file(){

  //  cout<<"wrote in the file"<<endl;

  }

#endif
