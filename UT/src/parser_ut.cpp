#include "../../include/parser.hpp"
#include "../include/parser.hpp"
#include "../../src/token.cpp"


static MunitResult
tokenize_returns_expected_val(const MunitParameter params[], void* data) {
	return MUNIT_SKIP;
}

static MunitResult
tokenize_invalid_input_returns_err1(const MunitParameter params[], void* data) {
	// terminals_t output = parser_t::tokenizer_t::tokenize();
    // munit_assert_true(output == ???);
    // MUNIT_OK;
}

static MunitResult
tokenize_invalid_input_returns_err2(const MunitParameter params[], void* data) {
	return MUNIT_SKIP;
}

static MunitResult
tokenize_invalid_input_returns_err3(const MunitParameter params[], void* data) {
	return MUNIT_SKIP;
}

static MunitResult
get_line_number_returns_correct_line(const MunitParameter params[], void* data) {
	// size_t lineNum = get_line_number();
    // munit_assert_int(lineNum, ==, ???)
    // MUNIT_OK;
}

static MunitResult
get_char_index_returns_correct_index(const MunitParameter params[], void* data) {
	// size_t charIndex = get_char_index();
    // munit_assert_int(charIndex, ==, ???)
    // MUNIT_OK;
}

static MunitResult
is_terminal_valid_input_returns_true(const MunitParameter params[], void* data) {
	return MUNIT_SKIP;
}

static MunitResult
is_terminal_invalid_input_returns_false(const MunitParameter params[], void* data) {
	return MUNIT_SKIP;
}

static MunitResult
is_number_valid_input_returns_true(const MunitParameter params[], void* data) {
	return MUNIT_SKIP;
}

static MunitResult
is_number_invalid_input_returns_false(const MunitParameter params[], void* data) {
	return MUNIT_SKIP;
}

static MunitResult
is_label_valid_input_returns_true(const MunitParameter params[], void* data) {
	return MUNIT_SKIP;
}

static MunitResult
is_label_invalid_input_returns_false(const MunitParameter params[], void* data) {
	return MUNIT_SKIP;
}

MunitTest parser_t_tests[] = {
	munit_ex_register_test(tokenize_returns_expected_val, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(tokenize_invalid_input_returns_err1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(tokenize_invalid_input_returns_err2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(tokenize_invalid_input_returns_err3, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(get_line_number_returns_correct_line, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(get_char_index_returns_correct_index, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(is_terminal_valid_input_returns_true, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(is_terminal_invalid_input_returns_false, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
    munit_ex_register_test(is_number_valid_input_returns_true, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(is_number_invalid_input_returns_false, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
    munit_ex_register_test(is_label_valid_input_returns_true, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(is_label_invalid_input_returns_false, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};