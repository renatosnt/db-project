#pragma once

#include <cstdint>
#include <cstdio>

#include "InputBuffer.hpp"

#define COLUMN_USERNAME_SIZE 32 // varchar(32)
#define COLUMN_EMAIL_SIZE 255 // varchar(255)

typedef struct {
  uint32_t id; // fixed width int
  char username[COLUMN_USERNAME_SIZE];
  char email[COLUMN_EMAIL_SIZE];
} Row;


enum StatementType {
  STATEMENT_INSERT, 
  STATEMENT_SELECT
};

enum PrepareResult { 
  PREPARE_SUCCESS,
  PREPARE_UNRECOGNIZED_STATEMENT 
};

class Statement {
  public:
    StatementType type;
    Row row_to_insert;

    PrepareResult prepare_statement(InputBuffer* input_buffer);
    void execute_statement();
};


/*
  Set type of statement, if it is a valid one.
  Return if the prepartion stage was a success or not.
*/
PrepareResult Statement::prepare_statement(InputBuffer* input_buffer) {

  if ((input_buffer->buffer).substr(0, 6) == "insert") {
    type = STATEMENT_INSERT;
    
    int args_assigned = sscanf(&input_buffer->buffer, "insert %d %s %s", row_to_insert.id, row_to_insert.username, row_to_insert.email);

    std::cout << input_buffer->buffer << " teste ";
    return PREPARE_SUCCESS;
  }


  if ((input_buffer->buffer).substr(0, 6) == "select") {
    type = STATEMENT_SELECT;
    return PREPARE_SUCCESS;
  }

  return PREPARE_UNRECOGNIZED_STATEMENT;
}


/*
  Executes the statement accordingly with the type of it
*/
void Statement::execute_statement() {
  switch (type) {
    case (STATEMENT_INSERT):
      std::cout << "This is an insert" << std::endl;
      break;
    case (STATEMENT_SELECT):
      std::cout << "This is a select" << std::endl;
      break;
  }
}