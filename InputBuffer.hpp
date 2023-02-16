#pragma once
#include <iostream>
#include <string>

class InputBuffer {
  public: 
    std::string buffer;
    size_t buffer_length;
    ssize_t input_length;

    InputBuffer() {
      buffer = "";
      buffer_length = 0;
      input_length = 0;
    }

    void read_input() {
      std::getline(std::cin, buffer);
      input_length = sizeof(buffer);
      // if () {
      //   std::cout << "Error reading input" << std::endl;
      //   exit(EXIT_FAILURE);
      // }
    }
};