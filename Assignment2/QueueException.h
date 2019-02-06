#include <stdexcept>
#include <string>
using namespace std;

#ifndef QUEUEXCEPTION_H
#define QUEUEXCEPTION_H

class QueueException : public logic_error
{
public:
   QueueException(const string& message = "")
      : logic_error(message.c_str())
   {}  // end constructor
};
#endif// end QueueException
