#include <iostream>
#include "thread_utils.h"

void print();
template<typename T, typename ... A>
void print(T&& first, A &&...args);
void doSomeWork(int);


int main() {


  std::cout << "Hello, World!" << std::endl;
  std::string T1 = "Worker1";
  std::string T2 = "Worker2";
  auto t1 = createAndStartThread(-2, (std::string &) "T1", doSomeWork, 5);
  auto t2 = createAndStartThread(-1, T2, doSomeWork, 5);

  std::cout << "Main thread waiting for threads to finish bullshit" << std::endl;
  t1->join();
  t2->join();
  std::cout << "main exiting " << std::endl;
  return 0;
}

void inline print ()
{
  std::cout << std::endl;
}


template<typename T, typename ... A>
void inline print(T&& first, A &&...args)
{
  std::cout << std::forward<T>(first) << std::endl;
  print(std::forward<A>(args)...);

}

void inline doSomeWork(int dummy)
{
  print(std::this_thread::get_id(), "Hello", 10, 20, 50.5, "shabablalbals");
  using namespace std::literals::chrono_literals;
  std::this_thread::sleep_for(5s);
  print(std::this_thread::get_id(), " has finished execution");

}



