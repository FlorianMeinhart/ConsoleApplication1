#pragma once
#include <iostream>
#include <string.h>

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

//void printHelloWorld()
//{
//  std::cout << "Hello, world!" << std::endl;
//}

class CPrintHelloWorld
{
public:
  void operator()() const
  {
    std::cout << "Hello, world! " << __FILENAME__ << std::endl;
  }
  void Show();
};