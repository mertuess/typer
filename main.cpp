#include "./include/typer.h"

int main (int argc, char *argv[]) {
		typer::Library::LoadWords();
		typer::Typer t;
		t.StartMainCycle();
		return 0;
}
