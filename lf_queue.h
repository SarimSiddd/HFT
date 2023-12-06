//
// Created by Muhammad Sarim Siddiqui on 31/10/2023.
//

#ifndef HFTBOT__LF_QUEUE_H_
#define HFTBOT__LF_QUEUE_H_

#include <iostream>
#include <vector>
#include <atomic>
#include <string>
#include "macros.h"

namespace Common
{
template <typename T>
  class LFQueue final{
   public:
    LFQueue(size_t num_elements_) :store_(num_elements_, T()){

    }

    LFQueue() = delete;
    LFQueue(const LFQueue&) = delete;
    LFQueue(const LFQueue&&) = delete;
    LFQueue& operator=(const LFQueue&) = delete;
    LFQueue& operator=(const LFQueue&&) = delete;

    auto getNextToWriteTo() noexcept
    {
      return &store_[next_write_index_];
    }

    auto updateWriteIndex() noexcept
    {
      //Loop around:
      next_write_index_ = (next_write_index_ + 1) % store_.size();
      num_elements_++;
    }

    auto getNextToRead() const noexcept -> const T*
    {
      return (next_read_index_ == next_write_index_) ? nullptr : &store_[next_read_index_];
    }

    auto  updateReadIndex() noexcept
    {
      next_read_index_ = (next_read_index_ + 1) % store_.size();
      ASSERT(num_elements_ != 0, "Read an invalid element in:" + std::to_string(reinterpret_cast<long>(pthread_self())));
      num_elements_--;
    }

    auto size() const noexcept{
      return num_elements_.load();
    }



   private:
    std::vector<T> store_;
    std::atomic<size_t> next_read_index_ = {0};
    std::atomic<size_t> next_write_index_ = {0};
    std::atomic<size_t> num_elements_ = {0};

  };

}



#endif //HFTBOT__LF_QUEUE_H_
