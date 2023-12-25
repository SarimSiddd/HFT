//
// Created by Muhammad Sarim Siddiqui on 25/12/2023.
//

#ifndef HFTBOT__TCP_SOCKET_H_
#define HFTBOT__TCP_SOCKET_H_

#include "logging.h"
#include "socket_utils.h"
#include "time_utils.h"
#include <functional>

constexpr size_t TCPBufferSize = 64 * 1024 * 1024;

namespace Common {

struct TCPSocket {

  int fd_ = -1;
  char * send_buffer_ = nullptr;
  size_t next_send_valid_index_ = 0;
  char * rcv_buffer_ = nullptr;
  size_t next_rcv_valid_index_ = 0;
  bool send_disconnected_ = false;
  bool rcv_disconnected_ = false;
  struct sockaddr_in inInAddr;
  std::function<void(TCPSocket *s, Nanos rx_time)> recv_callback_;
  std::string time_str_;
  Logger &logger_;

  auto defaultRecvCallback(TCPSocket *socket, Nanos rx_time) noexcept {
    logger_.log("%:% %() % TCPSocket::defaultRecvCallback() socket:% len:% rx:%\n", __FILE__, __LINE__, __FUNCTION__, Common::getCurrentTimeStr(&time_str_), socket->fd_, socket->next_rcv_valid_index_, rx_time);
  }

  explicit TCPSocket(Logger &logger): logger_(logger) {
    send_buffer_ = new char[TCPBufferSize];
    rcv_buffer_ = new char[TCPBufferSize];
    recv_callback_ = [this](auto socket, auto rx_time) {
      defaultRecvCallback(socket, rx_time);
    };
  }

    auto destroy() noexcept -> void {
      close(fd_);
      fd_ = -1;
    }

    ~TCPSocket(){
      destroy();
      delete [] send_buffer_;
      send_buffer_ = nullptr;
      delete [] rcv_buffer_;
      rcv_buffer_ = nullptr;
    }

    int connect(const std::string &ip, const std::string &iface, int port, bool is_listening);
    void send(const void *data, size_t len) noexcept;
    bool sendAndRecv() noexcept;


    // Deleted default, copy & move constructors and assignment-operators.
    TCPSocket() = delete;
    TCPSocket(const TCPSocket &) = delete;
    TCPSocket(const TCPSocket &&) = delete;
    TCPSocket &operator=(const TCPSocket &) = delete;
    TCPSocket &operator=(const TCPSocket &&) = delete;
};
}// namespace Common

#endif//HFTBOT__TCP_SOCKET_H_
