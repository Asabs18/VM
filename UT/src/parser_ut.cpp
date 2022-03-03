#include "../../include/parser.hpp"
#include "../include/parser.hpp"
#include "../../src/token.cpp"
// [dynamic_cast conversion - cppreference.com](https://en.cppreference.com/w/cpp/language/dynamic_cast)
static MunitResult
parseIdentifiesMaCommandsCorrectly(const MunitParameter params[], void* data) {
    // Arrange
    parser_t* parser = new parser_t(" pop local 1 ");
    // Act
    // try {
        ma_instructions_t instruction = dynamic_cast<ma_instructions_t&>(parser->parse());
    // } catch (std::bad_cast) { };
    // Assert
    munit_assert_true(instruction.instruction == "pop" && instruction.memory_segment == "local" && instruction.index == 1);
    return MUNIT_OK;
}

static MunitResult
parseIdentifiesAlCommandsCorrectly(const MunitParameter params[], void* data) {
    // Arrange
    parser_t* parser = new parser_t(" add ");
    // Act
    instruction_t instruction = parser->parse();
    // Assert
    munit_assert_true(instruction.instruction == "add");
    return MUNIT_OK;
}

static MunitResult
parseIdentifiesBrCommandsCorrectly(const MunitParameter params[], void* data) {
    // Arrange
    parser_t* parser = new parser_t(" goto LOOP ");
    // Act
    instruction_t instruction = parser->parse();
    // Assert
    munit_assert_true(instruction.instruction == "goto" && instruction.label = "LOOP");
    return MUNIT_OK;
}

static MunitResult
parseIdentifiesFnCommandsCorrectly(const MunitParameter params[], void* data) {
    // Arrange
    parser_t* parser = new parser_t(" function func var1 var2 ");
    // Act
    instruction_t instruction = parser->parse();
    // Assert
    munit_assert_true(instruction.instruction == "function" && instruction.name == "func" && instruction.number == 2);
    return MUNIT_OK;
}

//declares the test suite to run each test in this file
MunitTest parser_t_tests[] = {
    munit_ex_register_test(parseIdentifiesMaCommandsCorrectly, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
    munit_ex_register_test(parseIdentifiesAlCommandsCorrectly, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
    munit_ex_register_test(parseIdentifiesBrCommandsCorrectly, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
    munit_ex_register_test(parseIdentifiesFnCommandsCorrectly, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL),
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};