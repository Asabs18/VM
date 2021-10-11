#include "../../include/token.hpp"
#include "../include/token.hpp"

static MunitResult
create_terminal_token(const MunitParameter params[], void* data) {
	//Arrange
	token_t token(terminals_t::ms_local, 0, 0);
	//Act
	bool b = token.is_terminal();
	//Assert
	munit_assert_true(b);

	return MUNIT_OK;
}
static MunitResult
create_number_token(const MunitParameter params[], void* data) {
	//Arrange
	token_t token({ number_t{1234} }, 0, 0);
	//Act
	bool b = token.is_number();
	//Assert
	munit_assert_true(b);

	return MUNIT_OK;
}
static MunitResult
create_label_token(const MunitParameter params[], void* data) {
	//Arrange
	token_t token({ label_t{"label_t"} }, 0, 0);
	//Act
	bool b = token.is_label();
	//Assert
	munit_assert_true(b);

	return MUNIT_OK;
}
static MunitResult
cast_terminal_token(const MunitParameter params[], void* data) {
	//Arrange
	token_t token(terminals_t::ms_local, 0, 0);
	//Act
	terminals_t terminal = token;
	//Assert
	munit_assert(terminal == terminals_t::ms_local);

	return MUNIT_OK;
}
static MunitResult
invalid_cast_number_token(const MunitParameter params[], void* data) {
	//Arrange
	token_t token({ number_t{1234} }, 0, 0);
	terminals_t terminal = terminals_t::ts_number;
	//Act
	try {
		terminal = token;
	}
	 catch(...) {
	}
	//Assert
	munit_assert(terminal == terminals_t::ts_number);
	return MUNIT_OK;
}

//declares the test suite to run each test in this file
MunitTest token_t_tests[] = {
	munit_ex_register_test(create_terminal_token, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(create_number_token, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(create_label_token, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(cast_terminal_token, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	munit_ex_register_test(invalid_cast_number_token, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};
