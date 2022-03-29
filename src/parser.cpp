#include "../include/parser.hpp"
#include <string>
//
#define TERMINAL(prefix, terminal)        \
    { #terminal, tokens_t::prefix##_##terminal }

instruction_t* parser_t::parse(){
    // size_t line_number = stream.line_number();
    // size_t char_index = stream.char_index();
    // int currentChar = stream();
    switch(getCharType(currentChar)){
        case getCharType(currentChar)::eof:
            return {oef(), line_number, char_index};    
        case getCharType(currentChar)::space:
            continue;
        case currentChar == '/' && getNextChar(stream) == '/': 
            skipComment();
        case currentChar == 'p':
            switch(NEXTCHAR):
                case NEXTCHAR == 'o':
                    Its pop
                case NEXTCHAR == 'u':
                    Its push    
    }
}

const stork::lookup<std::string_view,  tokens_t> memory_segment_t::reserved_memory_segment_terminal_map {
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