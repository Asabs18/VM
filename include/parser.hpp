#pragma once
#include "lookup.hpp"
#include "token.hpp"
#include <string>

struct instruction_t {
    string instruction;
    virtual ~instruction_t() = default;
};

class parser_t {
    private:
        using parser_value = std::variant<instruction_t, eof_t>;
        parser_value _value;
        size_t _line_number;
        size_t _char_index;

        class tokenizer_t {
            tokenizer_t(std::ifstream file_stream);
            tokenizer_t(std::stringstream string_stream);
            
            terminals_t tokenize();
        };

        //string advance();

    public:
        parser_t(std::string file_name) {};
        parser_t(std::ifstream file_stream);
        parser_t(std::stringstream string_stream);
    
        //The Big 5:
        parser_t() = delete;
        parser_t(const parser_t&) = delete;
        parser_t& operator=(const parser_t&) = delete;
        parser_t(parser_t&&) = delete;
        parser_t& operator=(parser_t&&) = delete;
        virtual ~parser_t() = default;
        
        instruction_t& parse();
};

struct memory_segment_t
{
    // const stork::lookup<std::string_view,  terminals_t> reserved_memory_segment_terminal_map {
};

// AL instructions
struct al_instruction_t : instruction_t {
};

// MA instructions
struct ma_instructions_t : public instruction_t {
    memory_segment_t memory_segment;
    memory_segment_index_t index;
};

// BC instructions 
struct bc_t : instruction_t {
    label_t label;
};

// FC instructions
struct function_instruction_t {
    function_name_t name;
    number_t number;    // locals or arguments;
};