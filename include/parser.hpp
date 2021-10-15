#pragma once
#include <string_view>
#include "lookup.hpp"
#include "token.hpp"

extern const stork::lookup<std::string_view, terminals_t> reserved_memory_segment_terminal_map;
extern const stork::lookup<std::string_view, terminals_t> reserved_instruction_terminal_map;

class parser_t {
    public:
    // TODO: Remove TEST ONLY implementation.
    parser_t(std::string file_name) {};
    parser_t(std::ifstream file_stream);
    parser_t(std::stringstream string_stream);

    // TODO: Iterators?
    token_t cbegin();
    token_t cend();
    //! The `Big `5`.
    parser_t() = delete;
    parser_t(const parser_t&) = delete;
    parser_t& operator=(const parser_t&) = delete;
    parser_t(parser_t&&) = delete;
    parser_t& operator=(parser_t&&) = delete;
    virtual ~parser_t() = default;
    
    private:
    class tokenizer_t {
    tokenizer_t(std::ifstream file_stream);
    tokenizer_t(std::stringstream string_stream);
    //! TODO: Implement using:
    //  1) string comparison
    //  2) [std::stoi, std::stol, std::stoll - cppreference.com](https://en.cppreference.com/w/cpp/string/basic_string/stol)
    //      - lexical analysis by tokenizer (valid integer)
    //      - semantic analysis done by parser_t (valid number - positive, range)
    //  3) [Regular expressions library - cppreference.com](https://en.cppreference.com/w/cpp/regex)
    //      - symbols: `labels` and `function names`
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

struct goto_t
{
    label_t label;
};

struct if_goto_t
{
    label_t label;
};

struct memory_segment_t
{
    // const stork::lookup<std::string_view,  terminals_t> reserved_memory_segment_terminal_map {
    // TODO: enumerate
};

struct memory_segment_index_t : number_t
{
};

struct push_t
{
    memory_segment_t memory_segment;
    memory_segment_index_t index;
};

struct pop_t
{
    memory_segment_t memory_segment;
    memory_segment_index_t index;
};
