#ifndef TEXT_PROCESSING_H
#define TEXT_PROCESSING_H
  #include <fstream>
  #include<string>
  #include<iostream>
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

    algorithm = words[2];
    for(int i=3; i<word_count; i++){
        Process p;
        p.name = words[i++];
        p.arrival_time = stoi(words[i++]);
        p.burst_time = stoi(words[i]);
        file_processes[process_count++] = p;

    }


  }

  void write_in_the_file(){

  //  cout<<"wrote in the file"<<endl;

  }

#endif
