#include <iostream>
#include "thread_utils.h"
#include "mem_pool.h"
#include "lf_queue.h"
#include "logging.h"

void print();
template<typename T, typename ... A>
void print(T&& first, A &&...args);
void doSomeWork(int);

struct MyStruct {
  int d_[3];
};
using namespace Common;
auto consumeFunction(LFQueue<MyStruct>* lfq) {
  using namespace std::literals::chrono_literals;
  std::this_thread::sleep_for(5s);
  while(lfq->size()) {
    const auto d = lfq->getNextToRead();
    lfq->updateReadIndex();
    std::cout << "consumeFunction read elem:" << d->d_[0]
              << "," << d->d_[1] << "," << d->d_[2] << " lfq-size:"
              <<lfq->size() << std::endl;
    std::this_thread::sleep_for(1s);
  }
  std::cout << "consumeFunction exiting." << std::endl;
}
int main(int, char **) {
  LFQueue<MyStruct> lfq(20);
  auto ct = createAndStartThread(-1, "WhackThing", consumeFunction, &lfq);
  for(auto i = 0; i < 50; ++i) {
    const MyStruct d{i, i * 10, i * 100};
    *(lfq.getNextToWriteTo()) = d;
    lfq.updateWriteIndex();
    std::cout << "main constructed elem:" << d.d_[0] << ","
              << d.d_[1] << "," << d.d_[2] << " lfq-size:" <<
              lfq.size() << std::endl;
    using namespace std::literals::chrono_literals;
    std::this_thread::sleep_for(1s);
  }
  ct->join();
  std::cout << "main exiting." << std::endl;
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



