//
// Created by Muhammad Sarim Siddiqui on 24/10/2023.
//

#ifndef HFTBOT__MACROS_H_
#define HFTBOT__MACROS_H_

#define LIKELY(x) __builtin_expect(!!(x), 1)
#define UNLIKELY(x) __builtin_expect(!!(x), 0)

inline auto ASSERT(bool cond, const std::string& msg)
noexcept {
  if(UNLIKELY(!cond)) {
    std::cerr << msg << std::endl;
    exit(EXIT_FAILURE);
  }
}
inline auto FATAL(const std::string& msg) noexcept {
  std::cerr << msg << std::endl;
  exit(EXIT_FAILURE);
}

#endif //HFTBOT__MACROS_H_
