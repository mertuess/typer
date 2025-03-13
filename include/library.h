#ifndef LIBRARY_H
#define LIBRARY_H

#include <chrono>
#include <random>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <filesystem>

namespace typer{
		class Library{
		private:
				Library();
				/// @brief List of all available words
				static std::vector<std::string> allWords;
				/// @brief Get one random word from all words list
				/// @param end The ending character that ends the returned word
				static std::string _getRandomWord(char end=' ');
		public:
				/// @brief Getting a string consisting of a single repeated word
				/// @param lenght Count of the words in string
				static std::string GetOneWordExpression(unsigned short lenght);
				/// @brief Getting a string of multiple random words
				/// @param lenght Count of the works in string
				static std::string GetExpression(unsigned short lenght);
				static void LoadWords();
		};
}

#endif // LIBRARY_H
