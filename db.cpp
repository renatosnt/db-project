#include <iostream>
#include <string>
#include <cstring>

#include "InputBuffer.hpp"
#include "Statement.hpp"
#include "MetaCommand.hpp"

void print_prompt() { std::cout << "db > "; }

int main(int argc, char* argv[]) {

  InputBuffer* input_buffer = new InputBuffer();
  
  while(true) {

    print_prompt();
    input_buffer->read_input();


    /* HANDLE METACOMMANDS*/
    if (input_buffer->buffer.at(0) == '.') {
      switch (MetaCommand::do_meta_command(input_buffer)) {
        case (META_COMMAND_SUCCESS):
          continue;
        case (META_COMMAND_UNRECOGNIZED_COMMAND):
          std::cout << "Unrecognized command " << std::endl; 
          continue;
      }
    }

    /* HANDLE STATEMENTS*/
    Statement statement;
    switch (statement.prepare_statement(input_buffer)) {
      case (PREPARE_SUCCESS):
        break;
      case (PREPARE_UNRECOGNIZED_STATEMENT):
        std::cout << "Unrecognized keyword at start of \"" << input_buffer->buffer << "\"" << std::endl;
        continue;
    }

    /* EXECUTES STATEMENTS*/

    statement.execute_statement();
    std::cout << "Executed" << std::endl;

    

  }
}