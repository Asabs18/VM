#include "../include/token.hpp"

static MunitResult
token_test(const MunitParameter params[], void* data) {
	//Arrange
	munit_assert(data == NULL);
	munit_assert(data == nullptr);
	//Act

	//Assert
	munit_assert_true(true);

	return MUNIT_OK;
}


//declares the test suite to run each test in this file
MunitTest token_tests[] = {
	munit_ex_register_test(token_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};
