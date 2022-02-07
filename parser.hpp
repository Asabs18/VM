#pragma once
#include "lookup.hpp"
#include "token.hpp"

struct instruction_t {
    tokens_t    token;    
};
class parser_t {
private:
    using parser_value = std::variant<instruction_t, eof_t>;
    parser_value _value;
    size_t _line_number;
    size_t _char_index;
public:
    parser_t(parser_value value, size_t line_number, size_t char_index)
        : _value(value), _line_number(line_number), _char_index(char_index) {};
    
public:
    // TODO: Iterators?
    instruction_t cbegin();
    instruction_t cend();
    // TODO: Remove TEST ONLY implementation.
    parser_t(std::string file_name) {};
    parser_t(std::ifstream file_stream);
    parser_t(std::stringstream string_stream);
<<<<<<< HEAD:parser.hpp

    token_t cbegin();
    token_t cend();
=======
>>>>>>> origin/master:include/parser.hpp
    //! The `Big `5`.
    parser_t() = delete;
    parser_t(const parser_t&) = delete;
    parser_t& operator=(const parser_t&) = delete;
    parser_t(parser_t&&) = delete;
    parser_t& operator=(parser_t&&) = delete;
    virtual ~parser_t() = default;
    
    private:
    class tokenizer_t {
<<<<<<< HEAD:parser.hpp
    tokenizer_t(std::ifstream file_stream);
    tokenizer_t(std::stringstream string_stream);
    
    terminals_t tokenize();
    // //! The `Big `5`.
    tokenizer_t() = delete;
    tokenizer_t(const tokenizer_t&) = delete;
    tokenizer_t& operator=(const tokenizer_t&) = delete;
    tokenizer_t(tokenizer_t&&) = delete;
    tokenizer_t& operator=(tokenizer_t&&) = delete;
    virtual ~tokenizer_t() = delete;
    };
};

struct function_t
{
    function_name_t name;
    number_t n_locals;
};

struct call_t {
    function_name_t name;
    number_t n_arguments;
};
=======
        tokenizer_t(std::ifstream file_stream);
        tokenizer_t(std::stringstream string_stream);
>>>>>>> origin/master:include/parser.hpp

        // TODO: Iterators?
        token_t cbegin();
        token_t cend();
        //! TODO: Implement using:
        //  1) string comparison
        //  2) [std::stoi, std::stol, std::stoll - cppreference.com](https://en.cppreference.com/w/cpp/string/basic_string/stol)
        //      - lexical analysis by tokenizer (valid integer)
        //      - semantic analysis done by parser_t (valid number - positive, range)
        //  3) [Regular expressions library - cppreference.com](https://en.cppreference.com/w/cpp/regex)
        //      - symbols: `labels` and `function names`
        tokens_t tokenize();
        // //! The `Big `5`.
        tokenizer_t() = delete;
        tokenizer_t(const tokenizer_t&) = delete;
        tokenizer_t& operator=(const tokenizer_t&) = delete;
        tokenizer_t(tokenizer_t&&) = delete;
        tokenizer_t& operator=(tokenizer_t&&) = delete;
        virtual ~tokenizer_t() = delete;
    };
};
    // MS_TOKENS_TABLE(DEFINE_TOKEN)                   \
    // AL_TOKENS_TABLE(DEFINE_TOKEN)                   \
    // MA_TOKENS_TABLE(DEFINE_TOKEN)                   \
    // BC_TOKENS_TABLE(DEFINE_TOKEN)                   \
    // FC_TOKENS_TABLE(DEFINE_TOKEN)                   \
    // TS_TOKENS_TABLE(DEFINE_TOKEN)
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
//
struct memory_segment_t {
    static const stork::lookup<std::string_view,  tokens_t> reserved_memory_segment_terminal_map;
};
<<<<<<< HEAD:parser.hpp

struct memory_segment_t
{
    // const stork::lookup<std::string_view,  terminals_t> reserved_memory_segment_terminal_map {
=======
//
struct memory_segment_index_t : number_t {
>>>>>>> origin/master:include/parser.hpp
};
// AL instructions
struct al_instruction_t : instruction_t {
};
// MA instructions
struct ma_instructions_t : instruction_t {
    memory_segment_t memory_segment;
    memory_segment_index_t index;
};
// BC instructions ()
struct bc_t : instruction_t {
    label_t label;
};
// FC instructions
struct function_instruction_t {
    function_name_t name;
    number_t number;    // locals or arguments;
};