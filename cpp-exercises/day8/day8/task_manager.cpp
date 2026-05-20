#include <iostream>
#include <format>
#include <vector>
#include <cctype>
#include <fstream>
#include "json.hpp"
#include "task_manager.hpp"



bool TaskManager::Load(const std::string& file_name) {
	Clear();
	m_file_name = file_name;
	std::ifstream fin(file_name);
	if (!fin) return false;
	nlohmann::json data;
	try {
		fin >> data;
	}
	catch (const nlohmann::json::parse_error& e)
	{
		// output exception information
		std::cout << "message: " << e.what() << '\n'
			<< "exception id: " << e.id << '\n'
			<< "byte position of error: " << e.byte << std::endl;
		return false;
	}
	auto tasks = data["tasks"];
	m_tasks.reserve(tasks.size());
	Task temp_task;
	for (auto task : tasks) {
		temp_task.task = task["task"];
		temp_task.done = task["done"];
		temp_task.time = task["time"];
		if (temp_task.done) m_last_done_index++;
		m_tasks.push_back(temp_task);
	}
	return true;
}

void to_json(nlohmann::json& j, const Task& t) {
	j = nlohmann::json{
		{"task", t.task},
		{"done", t.done},
		{"time", t.time}
	};
}

void from_json(const nlohmann::json& j, Task& t) {
	j.at("task").get_to(t.task);
	j.at("done").get_to(t.done);
	j.at("time").get_to(t.time);
}

bool TaskManager::Save() {
	std::ofstream fout(m_file_name);
	nlohmann::json json_tasks;
	json_tasks["tasks"] = m_tasks;
	fout << json_tasks.dump(4);
	return true;
}
void TaskManager::AddTask(std::string& task) {
	Task temp;
	temp.done = false;
	temp.task = task;
	auto now = std::chrono::system_clock::now();
	auto floor = std::chrono::floor<std::chrono::seconds>(now);
	temp.time = std::format("{:%Y-%m-%d %H:%M:%S}", floor);
	m_tasks.emplace_back(temp);
}
int TaskManager::RmTask(const std::string& task) {
	int targets{};
	size_t target_index{};
	for (int i = 0; i < m_tasks.size();i++) {
		if (m_tasks[i].task == task) {
			if (m_tasks[i].done) {
				m_last_done_index--;
			}
			m_tasks.erase(m_tasks.begin() + i);
			return 1;
		}
		if (m_tasks[i].task.find(task) != std::string::npos) {
			target_index = i;
			targets++;
		}
	}
	if (targets == 1) {
		m_tasks.erase(m_tasks.begin() + target_index);
	}
	return targets;
}

bool TaskManager::RmTask(int index)
{
	if (index < 0 || index >= m_tasks.size()) {
		return false;
	}
	if (m_tasks[index].done) {
		m_last_done_index--;
	}
	m_tasks.erase(m_tasks.begin() + index);
	return true;
}

int TaskManager::Done(const std::string& task) {
	int targets{};
	size_t target_index{};
	for (int i = 0; i < m_tasks.size();i++) {
		if (m_tasks[i].task == task) {
			if (!m_tasks[target_index].done) {
				m_tasks[i].done = true;
				std::swap(m_tasks[target_index], m_tasks[m_last_done_index]);
				m_last_done_index++;
			}
			return 1;
		}
		if (m_tasks[i].task.find(task) != std::string::npos) {

			target_index = i;
			targets++;
		}
	}
	if (targets == 1) {
		if (!m_tasks[target_index].done) {
			m_tasks[target_index].done = true;
			std::swap(m_tasks[target_index], m_tasks[m_last_done_index]);
			m_last_done_index++;
		}
	}
	return targets;
}

bool TaskManager::Done(int index)
{
	if (index < 0 || index >= m_tasks.size()) {
		return false;
	}
	if (!m_tasks[index].done) {
		m_tasks[index].done = true;
		std::swap(m_tasks[index], m_tasks[m_last_done_index]);
		m_last_done_index++;
	}
	return true;
}

int TaskManager::Run() {
	while (true) {
		std::cout << "task_tacker:";
		std::string raw_input;
		std::getline(std::cin, raw_input);
		auto input = ParseInput(raw_input);
		int temp_i{};
		char temp_c{};
		std::string command = std::get<std::string>(input[0]);
		std::string task = std::get<std::string>(input[1]);
		auto ptr_i = std::get_if<int>(&input[2]);
		auto ptr_s = std::get_if<std::string>(&input[2]);

		if (command == "quit") {
			std::cout << "Save before quit?(y/n):";
			try {
				std::cin >> temp_c;
				if (temp_c == 'y') {
					Save();
					std::cout << "File was saved succesfully\n";
				}
			}
			catch(const std::exception &e){
				std::cout << "Issue was found file was not saved";
			}
			return 0;
			
		}
		else if (command == "list") {
			if (!ptr_s) {
				List(false);
			}
			else if(*ptr_s == "--time"){
				List(true);
			}
			else {
				List(false);
			}
			
		}
		else if (command == "add") {
			AddTask(task);
			std::cout << "Task was added succesfully \n";
		}
		else if (command == "rm") {
			if (ptr_i) {
				temp_i = RmTask(*ptr_i);
			}
			else {
				temp_i = RmTask(task);
			}
			if (temp_i == 1) {
				std::cout << "Task was removed succesfully\n";
			}
			else if (temp_i == 0) {
				std::cout << "Task not found\n";
			}
			else {
				std::cout << std::format("There are {} tasks with this task\n", temp_i);
			}
		}
		else if (command == "done") {
			if (ptr_i) {
				temp_i = Done(*ptr_i);
			}
			else {
				temp_i = Done(task);
			}
			if (temp_i == 1) {
				std::cout << "Task was marked as done succesfully\n";
			}
			else if (temp_i == 0) {
				std::cout << "Task not found\n";
			}
			else {
				std::cout << std::format("There are {} tasks with this task\n", temp_i);
			}
		}
		else if (command == "save") {
			if (Save()) {
				std::cout << "File was saved succesfully\n";
			}
			else {
				std::cout << "Issue was found file could not be saved\n";
			}
		}
		else if (command == "load") {
			if (Load(task)) {
				std::cout << "File was loaded succesfully\n";
				m_file_name = task;
			}
			else {
				std::cout << "Issue was found file could not be loaded\n";
			}
		}
		else if (command == "help") {
			PrintHelp();
		}
	}
}

void TaskManager::Clear() {
	m_tasks.clear();
	m_tasks.shrink_to_fit();
}



void TaskManager::List(bool time) {
	std::cout << "\033[42mCompleted:\033[0m\n";
	for (size_t i = 0; i < m_last_done_index;i++) {
		if (time) {
			std::cout << std::format("{}: {}", i, m_tasks[i].time);
			std::cout << std::format("-> {}{}{}\n", "\033[32m", m_tasks[i].task, "\033[0m");
		}
		else {
			std::cout << std::format("{}-> {}{}{}\n",i, "\033[32m", m_tasks[i].task, "\033[0m");
		}
	}
	std::cout << "\033[41mNot completed:\033[0m\n";
	for (size_t i = m_last_done_index; i < m_tasks.size();i++) {
		if (time) {
			std::cout << std::format("{}: {}", i, m_tasks[i].time);
			std::cout << std::format("-> {}{}{}\n", "\033[31m", m_tasks[i].task, "\033[0m");
		}
		else {
			std::cout << std::format("{}-> {}{}{}\n", i, "\033[31m", m_tasks[i].task, "\033[0m");
		}
	}
}

void TaskManager::PrintHelp() {
	std::cout << "task tracket is a program for storing tasks\n";
	std::cout << "add \"task\" <--add command will put task into current tasks\n";
	std::cout << "rm index || rm \"task\" <-- rm will remove a task from current tasks\n";
	std::cout << "list --time <-- list will list all current tasks and optionaly you can print time of creation\n";
	std::cout << "quit <-- quit will quit the program\n";
	std::cout << "save <-- save will save your current task into a given json file\n";
	std::cout << "load \"file\"<-- load will replace all current tasks with tasks from given json file\n\n";
}

std::vector<parse_argument> TaskManager::ParseInput(const std::string& raw_input) {
	std::istringstream ss(raw_input);
	const std::string commands[] = { "add","rm","quit","load","save","list","done","help"};
	std::string command;
	ss >> command;
	bool valid_command = false;
	for (auto cmd : commands) {
		bool target = true;
		for (size_t i = 0; i < cmd.size() && i < command.size();i++) {
			if (cmd[i] != command[i]) {
				target = false;
				break;
			}
		}
		if (target) {
			valid_command = true;
			break;
		}
	}
	if (!valid_command) return { " " };
	
	if (raw_input.length() >= command.length()) {
		int temp_i{};
		ss.seekg(command.length());
		if (!(ss >> temp_i)) {
			ss.clear();
		}
		else {
			return { command,"",temp_i };
		}
		const std::string arguments[] = { "--time"};
		std::string temp_s;
		ss.seekg(command.length());
		if (!(ss >> temp_s)) {
			ss.clear();
		}
		else {
			for (auto arg : arguments) {
				if (arg == temp_s) {
					return { command,"",temp_s };
				}
			}
			
		}
	}

	std::string task;
	bool start = false;
	for (size_t i = command.length() - 1;i < raw_input.length();i++) {
		if (raw_input[i] == '"') {
			if (start) {
				break;
			}
			start = true;
		}
		else if (start) {
			task += raw_input[i];
		}
	}
	return { command,task,""};
}