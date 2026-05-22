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

	std::vector<std::string> Tokenize(const std::string&);
	std::vector<std::string> ParseInput(const std::string&);
	void List(bool);
	
	bool Save();
	int SearchForTask(const std::string&,int option);
	void AddTask(const std::string&);
	int RmTask(const std::string&);
	bool RmTask(int);
	int Done(const std::string&);
	bool Done(int);
	void PrintHelp();
	void Clear();
public:
	TaskManager() = default;
	~TaskManager() = default;
	bool Load(const std::string&);
	int Run();
	
};


