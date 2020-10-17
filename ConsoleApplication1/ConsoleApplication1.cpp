// ConsoleApplication1.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <future>
#include <memory>
#include "SimpleFunctions.h"

static std::mutex s_mutex;


static bool AddThreadNum(std::shared_ptr<std::vector<size_t>> numVec, size_t threadNum)
{
  for (size_t count = 0; count < 4; count++)
  {
    //srand(time(NULL));
    //std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000));
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    //std::lock_guard<std::mutex> lock(s_mutex);
    std::unique_lock<std::mutex> lock(s_mutex);
    numVec->emplace_back(threadNum);

    //std::cout << threadNum << ". thread added number" << std::endl;
    if (threadNum == 1)
    {
      std::cout << "Hey, this is thread 1" << std::endl;
    }
    else if (threadNum == 2)
    {
      std::cout << "Hey, this is thread 2" << std::endl;
    }
    else if (threadNum == 3)
    {
      std::cout << "Hey, this is thread 3" << std::endl;
    }
    lock.unlock();
  }
  return true;
}


void threadMain()
{
  CPrintHelloWorld printHelloWorld;
  /*size_t count = 0;
  while(count < 10000)
  {
    printHelloWorld();
  }*/

  std::shared_ptr<std::vector<size_t>> threadNumVec = std::make_shared<std::vector<size_t>>();
  std::vector<std::future<bool>> futures;
  
  for (size_t count = 0; count < 3; count++) 
  {
    futures.push_back(std::async(std::launch::async, AddThreadNum, threadNumVec, count + 1));
  }

  auto now = std::chrono::system_clock::now();
  //auto timeToWait_s = std::chrono::seconds(5);

  for (auto& future : futures)
  {
    if (future.valid())
    {
      future.wait();
      //future.wait_until(now + timeToWait_s);
    }
  }

  std::cout << "\nElements in vector:" << std::endl;
  for (const auto& element : *threadNumVec)
  {
    std::cout << element << std::endl;
  }

  std::cout << "\nFinished!\n";
}


int main()
{
  //threadMain();
  CPrintHelloWorld obj;
  obj();
  obj.Show();

  //do something here
  system("dir");
  
  //just added another comment

  //an yet another comment

  //comment for branch

}
