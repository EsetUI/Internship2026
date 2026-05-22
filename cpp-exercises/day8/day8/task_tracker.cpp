#include "task_manager.hpp"
#include <string>
#include <sstream>
#include <format>

int main(int argc, char* argv[]) {
	TaskManager manager;
	if (argc > 1) {
		manager.Load(argv[1]);
	}
	while (true) {
		try {
			manager.Run();
		}
		catch (const std::runtime_error& e) {
			std::cout << e.what();
		}
		catch (int end) {
			if (end == 0) return 0;
		}
	}
	
}
