#ifndef TEXT_PROCESSING_H
#define TEXT_PROCESSING_H
  #include <fstream>
  using namespace std;

  const int max_number_of_words = 100;
  int word_count = 0;
  string words[max_number_of_words];

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


  void write_in_the_file(){

  //  cout<<"wrote in the file"<<endl;

  }

#endif
