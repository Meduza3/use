#include "compiler.h"

int Compiler::validate(std::string code){
    std::istringstream iss(code);
    std::vector<std::string> words(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());
    for(size_t i = 0; i < words.size(); i++){
        if(words[i] == "MOVE") {
            if(words[i+1] != "X" && words[i+1] != "Y" && words[i+1] != "Z"){
                return -5;
            }
            try {
                double value = std::stod(words[i+2]);
                i++;
                i++;
            } catch (std::invalid_argument const &e) {
                return -1;
            } catch (std::out_of_range const &e) {
                return -2;
            }
        } else if(words[i] == "PUNCH") {
            //Do nothing
        } else if(words[i] == "PRINT") {
            if(words[i+1] == "POS"){
                i++;
            } else {
                return -3;
            }

        } else {
            return -10;
        }
    }
    return 1;
};