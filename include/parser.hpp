#pragma once
#include <string_view>
#include "lookup.hpp"
#include "token.hpp"

extern const stork::lookup<std::string_view, terminals_t> reserved_memory_segment_terminal_map;
extern const stork::lookup<std::string_view, terminals_t> reserved_instruction_terminal_map;

class parser {
    // .ctor(file_name)
    // .ctor(stream)
    // .ctor(string)
    //
    // iterators returns` parser tokens` below?
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
