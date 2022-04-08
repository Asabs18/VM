#include <cstdint>
#include "../../include/token.hpp"
#include "../include/token.hpp"

// static MunitResult
// create_terminal_token(const MunitParameter params[], void* data) {
//     // Arrange
//     token_t token(tokens_t::ms_local);
//     // Act
//     bool b = token.is_token();
//     // Assert
//     munit_assert_true(b);

//     return MUNIT_OK;
// }
// static MunitResult
// create_number_token(const MunitParameter params[], void* data) {
//     // Arrange
//     token_t token({ number_t{1234} }, 0, 0);
//     // Act
//     bool b = token.is_number();
//     // Assert
//     munit_assert_true(b);

//     return MUNIT_OK;
// }
// static MunitResult
// create_label_token(const MunitParameter params[], void* data) {
//     // Arrange
//     token_t token({ label_t{"label_t"} }, 0, 0);
//     // Act
//     bool b = token.is_label();
//     // Assert
//     munit_assert_true(b);

//     return MUNIT_OK;
// }
// static MunitResult
// cast_terminal_token(const MunitParameter params[], void* data) {
//     // Arrange
//     token_t token(tokens_t::ms_local, 0, 0);
//     // Act
//     tokens_t terminal = token;
//     // Assert
//     munit_assert(terminal == tokens_t::ms_local);

//     return MUNIT_OK;
// }
// static MunitResult
// invalid_cast_number_token(const MunitParameter params[], void* data) {
//     // Arrange
//     token_t token({ number_t{1234} }, 0, 0);
//     tokens_t terminal = tokens_t::ts_number;
//     // Act
//     try {
//         terminal = token;
//     }
//      catch(...) {
//     }
//     // Assert
//     munit_assert(terminal == tokens_t::ts_number);
//     return MUNIT_OK;
// }
// static MunitResult
// get_terminal_token(const MunitParameter params[], void* data) {
//     // Arrange
//     token_t token(tokens_t::ms_local, 0, 0);
//     // Act
//     const tokens_t* terminal = token.get_token();
//     // Assert
//     munit_assert(*terminal == tokens_t::ms_local);

//     return MUNIT_OK;
// }
// static MunitResult
// get_invalid_number_token(const MunitParameter params[], void* data) {
//     // Arrange
//     token_t token({ number_t{1234}}, 0, 0);
//     const tokens_t* terminal = reinterpret_cast<const tokens_t*>((intptr_t)0xDEADBEEF);
//     // Act
//       terminal = token.get_token();
//     // Assert
//       munit_assert_ptr_equal(terminal, nullptr);

//     return MUNIT_OK;
// }

//declares the test suite to run each test in this file
MunitTest token_t_tests[] = {
    // munit_ex_register_test(create_terminal_token, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
    // munit_ex_register_test(create_number_token, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
    // munit_ex_register_test(create_label_token, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
    // munit_ex_register_test(cast_terminal_token, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
    // munit_ex_register_test(invalid_cast_number_token, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
    // munit_ex_register_test(get_terminal_token, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
    // munit_ex_register_test(get_invalid_number_token, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};
