#include <cassert>
#include <cstdint>

#include "../include/token.hpp"
//
#define TERMINAL(prefix, terminal)        \
    { #terminal, terminals_t::DEFINE_TERMINAL(prefix, terminal) }
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
// }