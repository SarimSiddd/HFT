//
// Created by Muhammad Sarim Siddiqui on 18/10/2023.
//

#ifndef HFTBOT__THREAD_UTILS_H_
#define HFTBOT__THREAD_UTILS_H_

#pragma once
#include <iostream>
#include <atomic>
#include <thread>
#include <unistd.h>
#include <sys/syscall.h>

template<typename T, typename ... A>
inline auto createAndStartThread(int core_id, std::string &name, T &&func, A &&...args) noexcept {
  std::atomic<bool> running, failed = false;
  auto thread_body = [&] {
    if (core_id >= 0){ //&& !setThreadCore(core_id)) {
      std::cerr << "Failed to set core affinity for " << name << " " << pthread_self() << " to " << core_id
                << std::endl;
      failed = true;
      return;
    }

  std::cout << "Set core affinity for " << name << " " << pthread_self() << " to " << core_id << std::endl;
  running = true;

  std::forward<T>(func)((std::forward<A>(args))...);

  };

  auto t = new std::thread(thread_body);

  while (!running && !failed)
  {
    using namespace std::literals::chrono_literals;
    std::this_thread::sleep_for(1s);
  }

  if (failed)
  {
    t->join();
    delete t;
    t = nullptr;
  }

  return t;
}


//Create OSX specific implementation here:
/*inline auto setThreadCore(int core_id)
{
  cpu_set_t cpuset;
  CPU_ZERO(&cpuset);
  CPU_SET(core_id, cpuset);
  return (pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset));
}*/

#endif //HFTBOT__THREAD_UTILS_H_
