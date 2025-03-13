#include "../include/library.h"
#include <iostream>

namespace typer{
		std::vector<std::string> Library::allWords = {  };

		std::string Library::_getRandomWord(char end){
				// Initialize random engine
				static auto rng = std::default_random_engine{};
				// Set random engine seed by current time
				rng.seed(std::chrono::system_clock::now().time_since_epoch().count());
				// Shuffle all words list
				std::shuffle(std::begin(allWords), std::end(allWords), rng);
				// Init new string for current word
				std::string new_string = allWords[0];
				// Return first random word
				return new_string.append(1, end);
		}

		std::string Library::GetOneWordExpression(unsigned short lenght){
				std::string result; // Initialize result string
				std::string word = _getRandomWord(); // Get the random word
				for(unsigned short i = 0; i < lenght; ++i){
						result.append(word); // Append result string by random word
				}
				return result; // Return it
		}

		std::string Library::GetExpression(unsigned short lenght){
				std::string result; // Initialize result string
				for(unsigned short i = 0; i < lenght; ++i){
						result.append(_getRandomWord()); // Append result string by random word
				}
				return result; // Return it
		}

		void Library::LoadWords(){
				const char* homeDir = getenv("HOME");
				std::string path = std::string(homeDir) + "/.config/Typer/words.txt";
				std::ifstream file_stream(path);
				std::string line;
				while(std::getline(file_stream, line)){
						allWords.push_back(line);
				}
				file_stream.close();
		}
}
