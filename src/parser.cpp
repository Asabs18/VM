#include "../include/parser.hpp"
#include <string>
#include <iostream> 
#include <fstream>   
#include <vector>
#include <sstream>
#include <algorithm>
#include <cassert>


#define TOKEN(prefix, token)        \
    { #token, tokens_t::prefix##_##token }

instruction_t* parser_t::parse(std::vector<token_t*> token){
    switch(token){
        case 
    }

    return nullptr;
}


//======================= Tokenizer =========================


#define LETTER_COUNT 8

void print(std::vector <char> const &a) {
   std::cout << "The vector elements are : ";

   for(int i=0; i < a.size(); i++)
   std::cout << a.at(i) << ' ';
}

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

std::string readLastWord(std::vector<std::string> nameVector){
    std::string lastWord = "None";
    if (nameVector.size() > 0){
        lastWord = nameVector[nameVector.size() - 1];
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

bool isSpace(unsigned char c) {
	return (c == ' ' || c == '\n' || c == '\r' ||
		c == '\t' || c == '\v' || c == '\f');
}

std::string parser_t::tokenizer_t::readNextWord(std::stringstream& file){
    char c;
    int letterCount = 0;
    std::vector<char> wordVector = {' ',' ',' ',' ',' ',' ',' ',' '};
    
    while (file.get(c)){
        if(letterCount == LETTER_COUNT || isSpace(c)){
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

std::vector<token_t*> parser_t::tokenizer_t::tokenize(){
    std::stringstream file("push pop sub add function fn sub 10 15");
    std::string word = readNextWord(file);
    std::vector<std::string> nameVector = {};
    std::vector<token_t*> tokenVector = {};

    bool run = true;
    while (run) {
        if (file.eof()){ run = false; }
        // if(isValidToken(word)){
        //     nameVector.resize(nameVector.size() + 1);
        //     nameVector[nameVector.size() - 1] = word;
        //     tokenVector.resize(nameVector.size());
        //     auto it = reserved_instruction_terminal_map.find(word); 
        //     assert(it != reserved_instruction_terminal_map.end());
        //     tokens_t t = it->second;
        //     tokenVector[tokenVector.size() - 1] = new token_t(t);
        //     std::cout << "Token Added: " + word + "\n";
        // }
        // else if(isNumber(word) == false){
        //     if(isFnName(word, readLastWord(nameVector))){
        //         nameVector.resize(nameVector.size() + 1);
        //         nameVector[nameVector.size() - 1] = word;
        //         tokenVector.resize(nameVector.size());
        //         std::cout << "Function Name Added: " + word + "\n";

        //         nameVector.resize(nameVector.size() + 1);
        //         nameVector[nameVector.size() - 1] = word;
        //         tokenVector.resize(nameVector.size());
        //         auto it = reserved_instruction_terminal_map.find(word); 
        //         assert(it != reserved_instruction_terminal_map.end());
        //         tokens_t t = it->second;
        //         tokenVector[tokenVector.size() - 1] = new token_t(t);
        //         std::cout << "Token Added: " + word + "\n";
        //     }
        //     else{
        //         nameVector[nameVector.size() - 1] = word;
        //         std::cout << "Label Added: " + word + "\n";
        //     }
        // }
        // else {
        //     nameVector[nameVector.size() - 1] = word;
        //     std::cout << "Number Added: " + word + "\n";
        // }

        tokenVector.resize(tokenVector.size() + 1);
        auto it = reserved_instruction_terminal_map.find(word); 
        if (it != reserved_instruction_terminal_map.end()){
            tokens_t t = it->second;
            tokenVector[tokenVector.size() - 1] = new token_t(t);
            std::cout << "Token Added: " + word + "\n";
        }
        word = readNextWord(file);
        word.erase(std::remove_if(word.begin(), word.end(), isSpace), word.end());
    }
    return tokenVector;
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