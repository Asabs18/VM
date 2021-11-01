#include <cassert>
#include <cstdint>
#include <fstream>
#include <iostream>

#include "../include/token.hpp"
// HACK: Not sure what do here given (a) x-macroed tokens, and, (b) design of symbol table
#define TERMINAL(prefix, terminal)        \
    { #terminal, terminals_t::prefix##_##terminal }
//
// HACK: Why the q-name?
const stork::lookup<std::string_view,  terminals_t> reserved_memory_segment_terminal_map {
  // Memory Segments: ms_*
    TERMINAL(ms, local),
    TERMINAL(ms, argument),
    TERMINAL(ms, this),
    TERMINAL(ms, that),
    TERMINAL(ms, constant),
    TERMINAL(ms, static),
    TERMINAL(ms, pointer),
    TERMINAL(ms, temp),
};
//
const stork::lookup<std::string_view, terminals_t> reserved_instruction_terminal_map {
    // Arithmetic / Logic Commands: al_*
    TERMINAL(al, add),
    TERMINAL(al, sub),
    TERMINAL(al, neg),
    TERMINAL(al, eq),
    TERMINAL(al, get),
    TERMINAL(al, lt),
    TERMINAL(al, and),
    TERMINAL(al, or),
    TERMINAL(al, not),
    // Memory access commands: ma_*
    TERMINAL(ma, pop),
    TERMINAL(ma, push),
    // Branching commands: bc_*
    TERMINAL(bc, label),
    TERMINAL(bc, goto),
    TERMINAL(bc, if_goto),    // if-goto
    // Function commands: fc_*
    TERMINAL(fc, function),
    TERMINAL(fc, call),
    TERMINAL(fc, return)
};

#include "../include/parser.hpp"

enum wordType { eof, space, alpha, num, punct };
terminals_t parser_t::tokenizer_t::tokenize(){
    int length = 0; //TBD
    char* buffer = new char [length];
    while(true){
      char character = stream.read(buffer, 1);
      switch(getCharType(character)){
        case eof:
          return {eof(), lineNum, charIndex}
        case space:
          continue;
        case alphanum:
          stream.putback(character);
          return fetchToken(fetchFullString()); //make member function so you dont have to pass in stream
        case num:
          stream.putback(character);
          return fetchToken(fetchFullNumber()); 
        case punct:
          switch(character) {
            case '/':
              if(stream.peek() == '/'){
                stream.putback(character);
                skipComment();
              }
            default:
              return "error" //change to thorw and exception or raise error
          }
        default:
          stream.putback(character);
          return "error" //change to thorw and exception or raise error
      }
    }
    return terminals_t::fc_return;
}
