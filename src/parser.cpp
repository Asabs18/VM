#include "../include/parser.hpp"
#include <string>
#include <iostream> 
#include <fstream>   
#include <vector>
#include <sstream>


#define TOKEN(prefix, token)        \
    { #token, tokens_t::prefix##_##token }

instruction_t* parser_t::parse(){
    return nullptr;
}



//======================= Tokenizer =========================


#define LETTER_COUNT 8

bool isValidTokenMA(std::string word){
    bool isValidToken = false;
    if(word.compare("push") == 0 || word.compare("pop") == 0){
        isValidToken = true;
    }
    return isValidToken;
}

bool isValidTokenAL(std::string word){
    bool isValidToken = false;
    if( word.compare("add") == 0 || word.compare("sub") ==  0 || word.compare("neg") == 0 ||
        word.compare("eq")  == 0 || word.compare("gt")  ==  0 || word.compare("lt")  == 0 ||
        word.compare("and") == 0 || word.compare("or")  ==  0 || word.compare("not") == 0){
        isValidToken = true;
    }
    return isValidToken;
}

bool isValidTokenBR(std::string word){
    bool isValidToken = false;
    if(word.compare("label") == 0 || word.compare("goto") == 0 || word.compare("if-goto") == 0){
        isValidToken = true;
    }
    return isValidToken;
}

bool isValidTokenFN(std::string word){
    bool isValidToken = false;
    if(word.compare("function") == 0 || word.compare("call") == 0 || word.compare("return") == 0){
        isValidToken = true;
    }
    return isValidToken;
}

bool isValidToken(std::string word){
    bool isValidToken = false;
    if(isValidTokenMA(word) || isValidTokenAL(word) || isValidTokenBR(word) || isValidTokenFN(word)){
        isValidToken = true;
    }
    return isValidToken;
}


bool isNumber(const std::string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

std::string readLastWord(std::vector<std::string> tokenVector){
    std::string lastWord = "None";
    if (tokenVector.size() > 0){
        lastWord = tokenVector[tokenVector.size() - 1];
    }
    return lastWord; 
}

bool isFnName(std::string word, std::string lastWord){
    bool isFnName = false;
    if(lastWord.compare("function") == 0){
        isFnName = true;
    }
    return isFnName;
}

std::string readNextWord(std::stringstream& file){
    char c;
    int letterCount = 0;
    std::vector<char> wordVector = {' ',' ',' ',' ',' ',' ',' ',' '};
    
    while (file.get(c)){
        if(c == ' ' || letterCount == LETTER_COUNT){
            wordVector.resize(letterCount);
            break;
        }
        else{
            wordVector[letterCount] = c;
            letterCount++;
        }
    }

    std::string wordString(wordVector.begin(), wordVector.end());
  
    return wordString; 
}

void print(std::vector <std::string> const &a) {
   std::cout << "The vector elements are : ";

   for(int i=0; i < a.size(); i++)
   std::cout << a.at(i) << ' ';
}


token_t* parser_t::tokenizer_t::tokenize(){
    std::stringstream file("push pop sub add function fn sub 10 15");
    std::vector<std::string> tokenVector = {};
    std::string word = readNextWord(file);
    while (!file.eof()) {
        if(isValidToken(word)){
            //token = new token_t(tokens_t, lineNum, charNum);
            tokenVector.resize(tokenVector.size() + 1);
            tokenVector[tokenVector.size() - 1] = word;
            std::cout << "Token Added: " + word + "\n";
        }
        else if(isNumber(word) == false){
            if(isFnName(word, readLastWord(tokenVector))){
                //token = new token_t(function_name_t, lineNum, charNum);
                tokenVector[tokenVector.size() - 1] = word;
                std::cout << "Function Name Added: " + word + "\n";
            }
            else{
                //token = new token_t(label_t, lineNum, charNum);
                tokenVector[tokenVector.size() - 1] = word;
                std::cout << "Label Added: " + word + "\n";
            }
        }
        else {
            //token = new token_t(number_t, lineNum, charNum);
            tokenVector[tokenVector.size() - 1] = word;
            std::cout << "Number Added: " + word + "\n";
        }
        word = readNextWord(file);
    }
    return 0;
}


// const stork::lookup<std::string_view,  tokens_t> memory_segment_t::reserved_memory_segment_terminal_map {
// // Memory Segments: ms_*
//     TOKEN(ms, local),
//     TOKEN(ms, argument),
//     TOKEN(ms, this),
//     TOKEN(ms, that),
//     TOKEN(ms, constant),
//     TOKEN(ms, static),
//     TOKEN(ms, pointer),
//     TOKEN(ms, temp),
// };