#include <cstdint>
#include "../../include/parser.hpp"
#include "../include/parser.hpp"

static MunitResult
create_terminal_token(const MunitParameter params[], void* data) {
    // Arrange
    token_t token(tokens_t::ms_local, 0, 0);
    // Act
    bool b = token.is_token();
    // Assert
    munit_assert_true(b);

    return MUNIT_SKIP;
}
static MunitResult
create_number_token(const MunitParameter params[], void* data) {
    // Arrange
    token_t token({ number_t{1234} }, 0, 0);
    // Act
    bool b = token.is_number();
    // Assert
    munit_assert_true(b);

    return MUNIT_SKIP;
}
static MunitResult
create_label_token(const MunitParameter params[], void* data) {
    // Arrange
    token_t token({ label_t{"label_t"} }, 0, 0);
    // Act
    bool b = token.is_label();
    // Assert
    munit_assert_true(b);

    return MUNIT_SKIP;
}
static MunitResult
cast_terminal_token(const MunitParameter params[], void* data) {
    // Arrange
    token_t token(tokens_t::ms_local, 0, 0);
    // Act
    tokens_t terminal = token;
    // Assert
    munit_assert(terminal == tokens_t::ms_local);

    return MUNIT_SKIP;
}
static MunitResult
invalid_cast_number_token(const MunitParameter params[], void* data) {
    // Arrange
    token_t token({ number_t{1234} }, 0, 0);
    tokens_t terminal = tokens_t::ts_number;
    // Act
    try {
        terminal = token;
    }
     catch(...) {
    }
    // Assert
    munit_assert(terminal == tokens_t::ts_number);
    return MUNIT_SKIP;
}
static MunitResult
get_terminal_token(const MunitParameter params[], void* data) {
    // Arrange
    token_t token(tokens_t::ms_local, 0, 0);
    // Act
    const tokens_t* terminal = token.get_token();
    // Assert
    munit_assert(*terminal == tokens_t::ms_local);

    return MUNIT_SKIP;
}
static MunitResult
get_invalid_number_token(const MunitParameter params[], void* data) {
    // Arrange
    token_t token({ number_t{1234} }, 0, 0);
    const tokens_t* terminal = reinterpret_cast<const tokens_t*>((intptr_t)0xDEADBEEF);
    // Act
      terminal = token.get_token();
    // Assert
      munit_assert_ptr_equal(terminal, nullptr);

    return MUNIT_SKIP;
}
// *****
#define EXPAND_MS_TOKEN_AS_STRING(category, token, pattern)        \
    #token,

#define EXPAND_MS_TOKEN_AS_ENUM(category, token, pattern)        \
    tokens_t::ms##_##token,

static char* ms_tokens_string_params[] = {
      MS_TOKENS_TABLE(EXPAND_MS_TOKEN_AS_STRING)
      NULL
};

static MunitParameterEnum validate_reserved_memory_segment_terminal_params[] = {
  { "ms_tokens_string_params", ms_tokens_string_params },
  { NULL, NULL },
};

static void*
setup_memory_segments(const MunitParameter params[], void* user_data) {
    static tokens_t ms_tokens[] = {
      MS_TOKENS_TABLE(EXPAND_MS_TOKEN_AS_ENUM)
      tokens_t::ts_null
    };
    return ms_tokens;
}
static MunitResult
validate_reserved_memory_segment_terminal(const MunitParameter params[], void* data) {
    // Arrange
    const tokens_t* ms_tokens = (const tokens_t*) data;
    const char* ms_tokens_string_param = munit_parameters_get(params, "ms_tokens_string_params");
    // Act
    auto sut = memory_segment_t::reserved_memory_segment_terminal_map.find(ms_tokens_string_param);
    // Assert
    MunitResult result = MunitResult::MUNIT_FAIL;
    for (size_t i = 0; ms_tokens[i] != tokens_t::ts_null; i++) {
        if(sut->second == ms_tokens[i]) {
            result = MunitResult::MUNIT_OK;
            break;
        }
    }
    return result;
}

//declares the test suite to run each test in this file
MunitTest parser_t_tests[] = {
    munit_ex_register_test(create_terminal_token, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
    munit_ex_register_test(create_number_token, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
    munit_ex_register_test(create_label_token, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
    munit_ex_register_test(cast_terminal_token, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
    munit_ex_register_test(invalid_cast_number_token, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
    munit_ex_register_test(get_terminal_token, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
    munit_ex_register_test(get_invalid_number_token, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
    munit_ex_register_test(validate_reserved_memory_segment_terminal, setup_memory_segments, NULL, MUNIT_TEST_OPTION_NONE, validate_reserved_memory_segment_terminal_params),
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};
