#pragma once

#include "common.hpp"

POLYBAR_NS

namespace file_util {
  /**
   * RAII file wrapper
   */
  class file_ptr {
   public:
    explicit file_ptr(const string& path, const string& mode = "a+") : m_path(string(path)), m_mode(string(mode)) {
      m_ptr = fopen(m_path.c_str(), m_mode.c_str());
    }

    ~file_ptr();

    file_ptr(const file_ptr& o) = delete;
    file_ptr& operator=(const file_ptr& o) = delete;

    operator bool();

    FILE* operator()();

   protected:
    FILE* m_ptr = nullptr;
    string m_path;
    string m_mode;
  };

  bool exists(const string& filename);
  string get_contents(const string& filename);
  void set_block(int fd);
  void set_nonblock(int fd);
  bool is_fifo(string filename);
}

POLYBAR_NS_END
