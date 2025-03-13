#include "../include/typer.h"

namespace typer{
		Typer::Typer() : currentString(""), pos(0), errors(0){
				initscr(); // Init ncurses
				cbreak();
				noecho();
				keypad(stdscr, TRUE);
				start_color();
				init_pair(1, COLOR_WHITE, COLOR_BLACK);
				init_pair(2, COLOR_YELLOW, COLOR_BLACK);
				init_pair(3, COLOR_GREEN, COLOR_BLACK);
				init_pair(4, COLOR_RED, COLOR_BLACK);
		}

		void Typer::StartMainCycle(){
				bool exit_flag = false;
				while(true){
						if(exit_flag) break;
						clear();
						mvprintw(0, 0, "%s", NULL);
						currentString = Library::GetExpression(5);
						attron(COLOR_PAIR(1));
						mvprintw(0, 0, "%s", currentString.c_str());
						move(0, 0);
						while(true){
								char c = getch();
								if(c == 27){
										exit_flag = true;
										break;
								}
								if(c == 7){
										if(pos <= 0) continue;
										--pos;
										attron(COLOR_PAIR(1));
										if((char)mvinch(0, pos) != currentString[pos]) errors--;
										mvprintw(0, pos, "%c", currentString[pos]);
										mvprintw(1, 0, "Errors: %d", errors);
										move(0, pos);
										refresh();
										continue;
								}
								if(pos == currentString.size()-1){
										if(errors <= 0) break;
										continue;
								}
								if(c == currentString[pos]){ attron(COLOR_PAIR(2)); }
								else{ attron(COLOR_PAIR(4)); errors++; }
								mvprintw(1, 0, "Errors: %d", errors);
								mvprintw(0, pos, "%c", c);
								pos++;
								refresh();
						}
						pos = 0;
						errors = 0;
				}
				endwin();
		}
}
