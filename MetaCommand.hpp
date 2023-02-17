#pragma once
#include "InputBuffer.hpp"

enum MetaCommandResult {
  META_COMMAND_SUCCESS,
  META_COMMAND_UNRECOGNIZED_COMMAND
};

class MetaCommand {
  public:
    static MetaCommandResult do_meta_command(InputBuffer* input_buffer);
};


MetaCommandResult MetaCommand::do_meta_command(InputBuffer* input_buffer) {
  if (input_buffer->buffer == ".exit") {
    exit(EXIT_SUCCESS);
  } else {
    return META_COMMAND_UNRECOGNIZED_COMMAND;
  }
}
