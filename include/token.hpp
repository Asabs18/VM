#pragma once
#include <string>
#include <variant>
#include "lookup.hpp"
// [chapter 7 lecture.pdf - Google Drive](https://drive.google.com/file/d/19fe1PeGnggDHymu4LlVY08KmDdhMVRpm/view)
// Memory Segments:
//     - Slide 63
// Arithmetic / Logical commands
// Memory access commands
// Branching commands
// Function commands
//     - Slide 82
// Other Terminal Symbols:
//     - number (number_t)
//    - symbol (symbol_t)

// [Replacing text macros - cppreference.com](https://en.cppreference.com/w/c/preprocessor/replace)
//  Search for: ""
#define TOKENS_TABLE(DEFINE_TOKEN)                  \
    DEFINE_TOKEN(ms, local, local)                  \
    DEFINE_TOKEN(ms, argument, argument)            \
    DEFINE_TOKEN(ms, this, this)                    \
    DEFINE_TOKEN(ms, that, that)                    \
    DEFINE_TOKEN(ms, constant, constant)            \
    DEFINE_TOKEN(ms, static, static)                \
    DEFINE_TOKEN(ms, pointer, pointer)              \
    DEFINE_TOKEN(ms, temp, temp)                    \
    DEFINE_TOKEN(al, add, add)                      \
    DEFINE_TOKEN(al, sub, sub)                      \
    DEFINE_TOKEN(al, neg, neg)                      \
    DEFINE_TOKEN(al, eq, eq)                        \
    DEFINE_TOKEN(al, get, get)                      \
    DEFINE_TOKEN(al, lt, lt)                        \
    DEFINE_TOKEN(al, and, and)                      \
    DEFINE_TOKEN(al, or, or )                       \
    DEFINE_TOKEN(al, not, not)                      \
    DEFINE_TOKEN(ma, pop, pop)                      \
    DEFINE_TOKEN(ma, push, push)                    \
    DEFINE_TOKEN(bc, label, label)                  \
    DEFINE_TOKEN(bc, goto, goto)                    \
    DEFINE_TOKEN(bc, if_goto, if-goto)              \
    DEFINE_TOKEN(fc, function, function)            \
    DEFINE_TOKEN(fc, call, call)                    \
    DEFINE_TOKEN(fc, return, return)                \
    DEFINE_TOKEN(ts, number, "D")                   \
    DEFINE_TOKEN(ts, symbol, "regex")

#define DEFINE_ENUM(category, token, pattern)  \
    category##_##token,

enum class tokens_t {
    TOKENS_TABLE(DEFINE_ENUM)
};
typedef tokens_t terminals_t;
#define EXPAND_AS_STRUCT(a,b,c) unsigned char a##_##b;
typedef struct{
    TOKENS_TABLE(EXPAND_AS_STRUCT)
} size_struct_t ;

#define NUM_STATES      sizeof(size_struct_t)
// namespace VM {

typedef uint16_t memory_t;
// namespace VM {
// token types
extern const stork::lookup<std::string_view, terminals_t> reserved_memory_segment_terminal_map;
extern const stork::lookup<std::string_view, terminals_t> reserved_instruction_terminal_map;
struct number_t {
    memory_t value;
};
// Book: 6.2.1 Syntax Conventions and File Formats
//  "Constants and Symbols Constants must be non-negative and are written in decimal notation. A user-
//  defined symbol can be any sequence of letters, digits, underscore (_), dot (.), dollar sign ($), and colon (:)
//  that does not begin with a digit."t
struct symbol_t {
    std::string name;
};

// Book: 8.2.1 Program Flow Commands
//  "Only labeled locations can be jumped to from other parts of the program. The scope of the label is the
//  function in which it is defined. The label is an arbitrary string composed of any sequence of letters, digits,
//  underscore (_), dot (.), and colon (:) that does not begin with a digit."
struct label_t : symbol_t {
};

// Book: 8.2.2 Function Calling Commands
//  "A function has a symbolic name that is used globally to call it. The function name is an arbitrary string
//  A function has a symbolic name that is used globally to call it. The function name is an arbitrary string
//  composed of any sequence of letters, digits, underscore (_), dot (.), and colon (:) that does not begin with
//  a digit. (We expect that a method bar in class Foo in some high-level language will be translated by the
//  compiler to a VM function named Foo.bar). The scope of the function name is global: All functions in all
//  files are seen by each other and may call each other using the function name."
struct function_name_t : symbol_t {
};

struct eof_t {
};

class token_t {
private:
    using token_value = std::variant<terminals_t, number_t, label_t, function_name_t, eof_t>;
    token_value _value;
    size_t _line_number;
    size_t _char_index;
public:
    token_t(token_value value, size_t line_number, size_t char_index)
        : _value(value), _line_number(line_number), _char_index(char_index) {};

    bool is_terminal() const { return std::holds_alternative<terminals_t>(_value); };
    bool is_number() const { return std::holds_alternative<number_t>(_value); };
    bool is_label() const { return std::holds_alternative<label_t>(_value); };

    operator terminals_t() const { return std::get<terminals_t>(_value); };
    operator memory_t() const { return std::get<number_t>(_value).value; };
    operator std::string() const { return std::get<label_t>(_value).name; };

    const terminals_t* get_terminal() const { return is_terminal() ? std::get_if<terminals_t>(&_value) : nullptr; };
    const memory_t* get_number() const { return is_number() ? &std::get_if<number_t>(&_value)->value : nullptr; };
    const std::string* get_label() const { return is_label() ? &std::get_if<label_t>(&_value)->name : nullptr; };

    size_t get_line_number() const;
    size_t get_char_index() const;
};
// }