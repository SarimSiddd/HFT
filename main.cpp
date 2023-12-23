#include <iostream>
#include "thread_utils.h"
#include "mem_pool.h"
#include "lf_queue.h"
#include "logging.h"

using namespace Common;
int main(int, char **) {

  int Integer = 69;
  std::string x = "Sample String";
  double d = 9999;

  Logger logger("logger_example.log");
  logger.log("Writing some dummy data for you bozos %s, %s, %s", Integer, x, d);

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




