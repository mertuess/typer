#ifndef TYPER_H
#define TYPER_H

#include <ncurses.h>
#include "library.h"

namespace typer{
		class	Typer{
		private:
				std::string currentString;
				int pos;
				int errors;
		public:
				Typer();
				void StartMainCycle();
		};
}

#endif // TYPER_H
