//
// Created by Muhammad Sarim Siddiqui on 05/11/2023.
//

#ifndef HFTBOT__LOGGING_H_
#define HFTBOT__LOGGING_H_

#include <string>
#include <fstream>
#include "macros.h"
#include "thread_utils.h"

namespace Common {
constexpr size_t LOG_QUEUE_SIZE = 8 * 1024 * 1024;

enum class LogType : uint8_t {

  CHAR = 0,
  INTEGER = 1,
  LONG_INTEGER = 2,
  LONG_LONG_INTEGER = 3,
  UNSIGNED_INTEGER = 4,
  UNSIGNED_LONG_INTEGER = 5,
  UNSIGNED_LONG_LONG_INTEGER = 6,
  FLOAT = 7,
  DOUBLE = 8
};

struct LogElement {
  LogType type_ = LogType::CHAR;
  union {
    char c;
    int i; long l; long long ll;
    unsigned u; unsigned long ul; unsigned long long ull;
    float f; double d;
  } u_;

};

class Logger final {

  explicit Logger (const std::string& file_name) : file_name_(file_name), queue_(LOG_QUEUE_SIZE)
  {
    file_.open(file_name_);
    ASSERT(file_.is_open(), "Could not open log file:" + file_name_);
    logger_thread_ = createAndStartThread(-1, "Common/Logger", [this](){
      flushQueue();
    });
    ASSERT(logger_thread_ != nullptr, "Failed to start logger thread.");
  }

 private:
  const std::string file_name_;
  std::ofstream file_;
  LFQueue<LogElement> queue_;
  std::atomic<bool> running_ = {true};
  std::thread * logger_thread_ = nullptr;

  //Flush data to Queue
  void flushQueue(){

    while (true){
      auto elem = queue_.getNextToRead();
      if (elem != nullptr){
        file_.write()
      }
    }
  }
};
}


#endif //HFTBOT__LOGGING_H_
