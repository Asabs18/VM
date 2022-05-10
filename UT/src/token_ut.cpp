#include <cstdint>
#include <sstream>
#include "../../include/parser.hpp"
#include "../../include/token.hpp"
#include "../include/token.hpp"

static MunitResult
tokenizeReturnsCorrectToken1(const MunitParameter params[], void* data) {
    //Arrange
	std::stringstream file("push pop sub add function fn sub 10 15");
	//parser_t parser = new parser_t(file); //HACK: PARSER_BROKEN 
	 
	//Act
	//token_t token = tokenizer->tokenize();

	//Assert
	//munit_assert(token.get_token() == TOKEN(ma, push, push));
    return MUNIT_SKIP;
}


//declares the test suite to run each test in this file
MunitTest token_t_tests[] = {
    // munit_ex_register_test(create_terminal_token, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};
