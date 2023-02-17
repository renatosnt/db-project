#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "InputBuffer.hpp"
#include <typeinfo>
#include <cstring>

enum MetaCommandResult {
  META_COMMAND_SUCCESS,
  META_COMMAND_UNRECOGNIZED_COMMAND
};

enum PrepareResult { 
  PREPARE_SUCCESS, 
  PREPARE_UNRECOGNIZED_STATEMENT 
};

enum StatementType {
  STATEMENT_INSERT, 
  STATEMENT_SELECT
};

typedef struct {
  StatementType type;
} Statement;


void print_prompt() { std::cout << "db > "; }

MetaCommandResult do_meta_command(InputBuffer* input_buffer) {
  if (input_buffer->buffer == ".exit") {
    exit(EXIT_SUCCESS);
  } else {
    return META_COMMAND_UNRECOGNIZED_COMMAND;
  }
}

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement) {

  if ((input_buffer->buffer).substr(0, 6) == "insert") {
    statement->type = STATEMENT_INSERT;
    return PREPARE_SUCCESS;
  }


  if ((input_buffer->buffer).substr(0, 6) == "select") {
    statement->type = STATEMENT_SELECT;
    return PREPARE_SUCCESS;
  }

  return PREPARE_UNRECOGNIZED_STATEMENT;
}

void execute_statement(Statement* statement) {
  switch (statement->type) {
    case (STATEMENT_INSERT):
      std::cout << "This is an insert" << std::endl;
      break;
    case (STATEMENT_SELECT):
      std::cout << "This is a select" << std::endl;
      break;
  }
}


int main(int argc, char* argv[]) {

  InputBuffer* input_buffer = new InputBuffer();

  while(true) {
    print_prompt();
    input_buffer->read_input();
    std::string buffer = input_buffer->buffer;


    if (buffer.at(0) == '.') {
      switch (do_meta_command(input_buffer)) {
        case (META_COMMAND_SUCCESS):
          continue;
        case (META_COMMAND_UNRECOGNIZED_COMMAND):
          std::cout << "Unrecognized command " << std::endl; 
          continue;
      }
    }

    Statement statement;
    switch (prepare_statement(input_buffer, &statement)) {
      case (PREPARE_SUCCESS):
        break;
      case (PREPARE_UNRECOGNIZED_STATEMENT):
        std::cout << "Unrecognized keyword at start of \"" << buffer << "\"" << std::endl;
        continue;
    }

    execute_statement(&statement);
    std::cout << "Executed" << std::endl;

    

  }
}