#pragma once
// TODO: add header guard
#include "lookup.hpp"

enum struct reserved_tokens;
extern const stork::lookup<std::string_view, reserved_tokens> reserved_memory_segment_token_map;
extern const stork::lookup<std::string_view, reserved_tokens> reserved_instruction_token_map;
