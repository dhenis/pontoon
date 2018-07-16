#include "File.h"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>     // for time
#include <fstream>
#include <sstream>
#include <new>
#include <iomanip>
#include <sstream>


File::File()
{

  setStartTimeReadable();
  setStartTime();

}
// get Current time with for file name format
std::string File::getTime()
{
  // -- time ---
    srand(time(0));  // initialize seed "randomly"

    auto t = time(nullptr);
    auto tm = *localtime(&t);

    std::ostringstream oss;

    oss << std::put_time(&tm, "%y%m%d_%H%M");

    auto str_time_start = oss.str();
    // ---time----

    return str_time_start;


}

// get current time with readable format in the txt file
std::string File::getTimeReadable()
{
  // -- time ---
    srand(time(0));  // initialize seed "randomly"

    auto t = time(nullptr);
    auto tm = *localtime(&t);

    std::ostringstream oss;

    oss << std::put_time(&tm, "%H:%M %d-%b-%Y");

    auto str_time_start = oss.str();
    // ---time----

    return str_time_start;

}
//
void File::insertHistory(const std::string &x)
{

    history.emplace_back(x);

}

int File::getSizeHistory()
{

  return history.size();

}


std::string File::getStartTime() const
{

  return start_time;


}

void File::setStartTime()
{

  start_time = getTime();

}

std::string File::getStartTimeReadable() const
{

  return start_time_readble;


}

void File::setStartTimeReadable()
{

  start_time_readble = getTimeReadable();

}


std::string File::getEndTimeReadable() const
{

  return end_time_readble;


}

void File::setEndTimeReadable()
{

  end_time_readble = getTimeReadable();

}

template <typename T>
T File::countWon(){

  int total = 0;

  for (std::vector<std::string>::iterator itt = history.begin(); itt != history.end(); ++itt)
  if((*itt) == "won")
  {

    total ++;

  }

  return total;

}

template <typename T>
 T File::countLost(){

  int total = 0;

  for (std::vector<std::string>::iterator itt = history.begin(); itt != history.end(); ++itt)
  if((*itt) == "lost")
  {

    total ++;

  }

  return total;

}


void File::createFile()
{
  try // cacth the error while error to open the file
  {

    std::string inputFile = "log/"+start_time+".txt";
    //string myStr = a;
    std::ofstream myStream(inputFile);

    myStream.exceptions ( std::ifstream::eofbit | std::ifstream::failbit | std::ifstream::badbit );
    if(myStream.is_open())
    {

      int lost = countLost<int>();
      int win =  countWon<int>();

      myStream <<"Game Started at: "<<start_time_readble<<std::endl;
      myStream <<"Game Finished at: "<<end_time_readble<<std::endl;
      myStream <<"Rounds: "<< getSizeHistory()<<std::endl;
      myStream <<"Won: "<< win<<std::endl;
      myStream <<"Lost: "<< lost<<std::endl;
      myStream <<"-- "<<std::endl;
      int ii =1;
      for (std::vector<std::string>::iterator it2 = history.begin(); it2 != history.end(); ++it2)
      {

        myStream <<"Round "<<ii<<": "<< *it2<<"."<<std::endl;
        ii++;

      }

    }

  }
  catch(std::exception const& e)
  {

      std::cerr << "Error, cannot create a new file : "<< e.what() << '\n';

  }
}
