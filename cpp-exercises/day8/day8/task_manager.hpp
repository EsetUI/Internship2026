#pragma once
#include <chrono>
#include <iostream>
#include <vector>
#include <variant>

using parse_argument = std::variant<int, std::string>;

struct Task {
	std::string time;
	std::string task;
	bool done = false;
};

class TaskManager {
	std::vector<Task> m_tasks;
	std::string m_file_name;
	size_t m_last_done_index{};

	std::vector<parse_argument> ParseInput(const std::string&);
	void PrintHelp();
public:
	TaskManager() = default;
	~TaskManager() = default;
	void List(bool);
	bool Load(const std::string&);
	bool Save();
	void AddTask(std::string&);
	int RmTask(const std::string&);
	bool RmTask(int);
	int Done(const std::string&);
	bool Done(int);
	int Run();
	void Clear();
};


