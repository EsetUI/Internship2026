#include "task_manager.hpp"
#include <string>
#include <sstream>
#include <format>

int main(int argc, char* argv[]) {
	TaskManager manager;
	if (argc > 1) {
		manager.Load(argv[1]);
	}
	manager.Run();
}
