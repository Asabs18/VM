#include "../include/parser.hpp"
#include <string>
//
#define TERMINAL(prefix, terminal)        \
    { #terminal, tokens_t::prefix##_##terminal }

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