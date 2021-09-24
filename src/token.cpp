#include <cassert>
#include <string>

#include "../include/token.hpp"
//  [chapter 7 lecture.pdf - Google Drive](https://drive.google.com/file/d/19fe1PeGnggDHymu4LlVY08KmDdhMVRpm/view)
//
// [Replacing text macros - cppreference.com](https://en.cppreference.com/w/c/preprocessor/replace)
//  Search for: ""
#define RESERVED_TOKEN(prefix, token)               \
    prefix_##token
//
enum struct reserved_tokens {
    //
    // Memory Segments:
    //  Slide 63
    //TODO: remove block comments?
    /*
        local
        argument
        this
        that
        constant
        static
        pointer
        temp
    */
    RESERVED_TOKEN(ms, local),
    RESERVED_TOKEN(ms, argument),
    RESERVED_TOKEN(ms, this),
    RESERVED_TOKEN(ms, that),
    RESERVED_TOKEN(ms, constant),
    RESERVED_TOKEN(ms, static),
    RESERVED_TOKEN(ms, pointer),
    RESERVED_TOKEN(ms, temp),
    //
    // Arithmetic / Logical commands
    //  Slide 82
    /*
        add
        sub
        neg
        eq
        get
        lt
        and
        or
        not
    */
    RESERVED_TOKEN(al, add),
    RESERVED_TOKEN(al, sub),
    RESERVED_TOKEN(al, neg),
    RESERVED_TOKEN(al, eq),
    RESERVED_TOKEN(al, get),
    RESERVED_TOKEN(al, lt),
    RESERVED_TOKEN(al, and),
    RESERVED_TOKEN(al, or),
    RESERVED_TOKEN(al, not),
    //
    // Memory access commands
    //  Slide 82
    /*
        pop
        push
    */
    RESERVED_TOKEN(ma, pop),
    RESERVED_TOKEN(ma, push),
    //
    // Branching commands
    //  Slide 82
    /*
        label
        goto
        if-goto
    */
    RESERVED_TOKEN(bc, label),
    RESERVED_TOKEN(bc, goto),
    RESERVED_TOKEN(bc, if_goto),    // if-goto
    //
    // Function commands
    //  Slide 82
    /*
        function
        call
        return
    */
    RESERVED_TOKEN(fc, function),
    RESERVED_TOKEN(fc, call),
    RESERVED_TOKEN(fc, return)
};
//
#define TOKEN(prefix, token)        \
    { #token, reserved_tokens::RESERVED_TOKEN(prefix, token) }
//
const stork::lookup<std::string_view, reserved_tokens> reserved_memory_segment_token_map {
  // Memory Segments: ms_*
    TOKEN(ms, local),
    TOKEN(ms, argument),
    TOKEN(ms, this),
    TOKEN(ms, that),
    TOKEN(ms, constant),
    TOKEN(ms, static),
    TOKEN(ms, pointer),
    TOKEN(ms, temp),
};
//
const stork::lookup<std::string_view, reserved_tokens> reserved_instruction_token_map {
    // Arithmetic / Logic Commands: al_*
    TOKEN(al, add),
    TOKEN(al, sub),
    TOKEN(al, neg),
    TOKEN(al, eq),
    TOKEN(al, get),
    TOKEN(al, lt),
    TOKEN(al, and),
    TOKEN(al, or),
    TOKEN(al, not),
    // Memory access commands: ma_*
    TOKEN(ma, pop),
    TOKEN(ma, push),
    // Branching commands: bc_*
    TOKEN(bc, label),
    TOKEN(bc, goto),
    TOKEN(bc, if_goto),    // if-goto
    // Function commands: fc_*
    TOKEN(fc, function),
    TOKEN(fc, call),
    TOKEN(fc, return)
};