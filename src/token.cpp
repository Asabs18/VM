#include <cassert>
#include <cstdint>
#include <fstream>
#include <iostream>

#include "../include/token.hpp"
// HACK: Not sure what do here given (a) x-macroed tokens, and, (b) design of symbol table
#define TERMINAL(prefix, terminal)        \
    { #terminal, tokens_t::prefix##_##terminal }
//
const stork::lookup<std::string_view, tokens_t> reserved_instruction_terminal_map {
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

<<<<<<< HEAD
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
              return "error" //change to throw and exception or raise error
          }
        default:
          stream.putback(character);
          return "error" //change to throw and exception or raise error
      }
    }
    return terminals_t::fc_return;
=======
// <<<<<<< HEAD


tokens_t parser_t::tokenizer_t::tokenize(){
//   vector<char> characters = stream; //Not sure how this will work
//   vector<char>::iterator ptr;
//   for(ptr = characters.begin(); ptr < characters.end(); ptr++){
//         size_t line_number = stream.line_number();
//       size_t char_index = stream.char_index();
//         int currentChar = stream();
//         switch(getCharType(currentChar)){
//             case getCharType(currentChar)::eof:
//                 return {oef(), line_number, char_index};    
//             case getCharType(currentChar)::space:
//                 continue;
//             case currentChar == '/' && getNextChar(stream) == '/': 
//                 skipComment();
//             case currentChar == 'p':
//                 switch(NEXTCHAR):
//                     case NEXTCHAR == 'o':
//                         Its pop
//                     case NEXTCHAR == 'u':
//                         Its push    
//         }
//     }
    return tokens_t::fc_return;
// =======
// enum wordType { eof, space, alpha, num, punct };
// terminals_t parser_t::tokenizer_t::tokenize(){
//     int length = 0; //TBD
//     char* buffer = new char [length];
//     while(true){
//       char character = stream.read(buffer, 1);
//       switch(getCharType(character)){
//         case eof:
//           return {eof(), lineNum, charIndex}
//         case space:
//           continue;
//         case alphanum:
//           stream.putback(character);
//           return fetchToken(fetchFullString()); //make member function so you dont have to pass in stream
//         case num:
//           stream.putback(character);
//           return fetchToken(fetchFullNumber()); 
//         case punct:
//           switch(character) {
//             case '/':
//               if(stream.peek() == '/'){
//                 stream.putback(character);
//                 skipComment();
//               }
//             default:
//               return "error" //change to thorw and exception or raise error
//           }
//         default:
//           stream.putback(character);
//           return "error" //change to thorw and exception or raise error
//       }
//     }
//     return terminals_t::fc_return;
// >>>>>>> f93e1f39245bbde390f9c1b0a9b108a130bf274f
>>>>>>> origin/master
}
