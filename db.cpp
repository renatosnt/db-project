#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "InputBuffer.hpp"


void print_prompt() { std::cout << "db > "; }


int main(int argc, char* argv[]) {
  
  InputBuffer* input_buffer = new InputBuffer();

  while(true) {
    print_prompt();
    input_buffer->read_input();

    if (input_buffer->buffer == ".exit") {
      exit(EXIT_SUCCESS);
    } else {
      std::cout << "Unrecognized command " <<  input_buffer->input_length << std::endl;
    }

  }
}