#ifndef FILE_H
#define	FILE_H

#include <array>
#include <string>
#include <vector>
#include <cstdlib>   // for srand and rand
#include <ctime>     // for time
#include <fstream>
#include <sstream>

class File {
public:
  // constructor
  File();

  // destructor
  virtual ~File(){};

  // get Current time with for file name format
  std::string getTime();

  // get current time with readable format in the txt file
  std::string getTimeReadable();

  // get the size of vector
  int getSizeHistory();

  // insert history when player won or lost
  void insertHistory(const std::string &x);

  //get start time for file log name
  std::string getStartTime() const;

  // set the start_time
  void setStartTime();

  //get more readable time format. it is used in the file
  std::string getStartTimeReadable() const;

  // set the variable start_time_readble
  void setStartTimeReadable();

  //get the time readable for log file
  std::string getEndTimeReadable() const;

  //set the time readable in the log file
  void setEndTimeReadable();

  // main function to create a new file in log folder
  void createFile();

  // a function to count won
  template <typename T>
   T countWon();

  // a function to count lost
  template <typename T>
   T countLost();

private:

  std::vector<std::string> history;

  // start and end game variable
  std::string start_time;
  std::string start_time_readble;
  std::string end_time_readble;

};

#endif	/* BOARD_H */
