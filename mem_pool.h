//
// Created by Muhammad Sarim Siddiqui on 24/10/2023.
//

#ifndef HFTBOT__MEM_POOL_H_
#define HFTBOT__MEM_POOL_H_

#include <cstdint>
#include <vector>
#include <string>
#include "macros.h"

namespace  Common {
  template <typename T>
      class MemPool final {

       public:
        explicit MemPool(std::size_t num_elems) : store_(num_elems, {T(), true}){
          ASSERT(reinterpret_cast<const ObjectBlock *>
                 (&(store_[0].object_)) == &(store_[0]), "T object should be first member of ObjectBlock.");
        }

        template <typename... A>
        T * allocate (A... args) noexcept
        {
          auto obj_block = &store_[next_free_index];
          ASSERT(obj_block->is_free_, "Object block is not free at index: " + std::to_string(next_free_index));
          T * ret = &(obj_block->object_);
          ret = new (ret) T(args...); //placement new
          obj_block->is_free_ = false;
          updateNextFreeIndex();
          return ret;
        }

        auto deallocate (const T* elem) noexcept
        {
          const auto elem_index = reinterpret_cast<const ObjectBlock*>(elem) - &store_[0];
          ASSERT(elem_index >= 0 && static_cast<size_t>(elem_index) < store_.size(), "Element being deallocated does not belong to this Memory pool.");
          ASSERT(!store_[elem_index].is_free_, "Expected in-use ObjectBlock at index:" + std::to_string (elem_index));
          store_[elem_index].is_free_ = true;

        }

        MemPool() = delete;
        MemPool(const MemPool&) = delete;
        MemPool(const MemPool&&) = delete;
        MemPool& operator=(const MemPool&) = delete;
        MemPool& operator=(const MemPool&&) = delete;

       private:
        struct ObjectBlock {
          T object_;
          bool is_free_ = true;
        };

        auto updateNextFreeIndex()
        {
          const auto initial_free_index = next_free_index;

          while(!store_[next_free_index].is_free_)
          {
            ++next_free_index;
            if (UNLIKELY(next_free_index == store_.size()))
            {
              next_free_index = 0;
            }
            if (UNLIKELY(next_free_index == initial_free_index))
            {
              ASSERT(initial_free_index != next_free_index, "Memory pool out of space");
            }

          }
        }


        std::vector<ObjectBlock> store_;
        size_t next_free_index = 0;
      };
}

#endif //HFTBOT__MEM_POOL_H_
