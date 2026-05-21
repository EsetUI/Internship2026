#include <iostream>
#include <vector>
#include <format>
#include <string>
#include <cctype>
#include "calculator.hpp"

std::vector<ch_d> Calculator::pre_process(const std::string& raw_input) {
	std::vector<ch_d> tokens;
	const std::string_view operators = "+-*/()";
	int dots{};
	for (size_t i = 0; i < raw_input.size(); i++) {
		if (operators.find(raw_input[i]) != std::string::npos) {
			tokens.push_back(raw_input[i]);
		}
		else if (std::isdigit(raw_input[i])) {
			size_t from = i;
			while (i < raw_input.size() && (std::isdigit(raw_input[i]) || raw_input[i] == '.')) {
				if (raw_input[i] == '.') dots++;
				i++;
			}
			if (dots > 1) throw std::runtime_error("Invalid input");
			dots = 0;
			tokens.push_back(std::stod(raw_input.substr(from, i - from)));
			i--;
		}
	}
	return tokens;
}

double Calculator::eval_expression() {
	double value = eval_term();
	ch_d temp = current();
	auto op = std::get_if<char>(&temp);
	while (op && (*op == '+' || *op == '-')) {
		advance();
		double right = eval_term();
		
		if (*op == '+') {
			value += right;
		}
		else {
			value -= right;
		}
		if (end()) break;
		temp = current();
		op = std::get_if<char>(&temp);
	}
	return value;
}
double Calculator::eval_term() {
	double value = eval_factor();
	ch_d temp = current();
	auto op = std::get_if<char>(&temp);
	while (op && (*op == '*' || *op == '/')) {
		advance();
		double right = eval_factor();

		if (*op == '*') {
			value *= right;
		}
		else {
			if (right == 0) throw std::runtime_error("cant devide by 0");
			value /= right;
		}
		if (end()) break;
		temp = current();
		op = std::get_if<char>(&temp);
	}
	return value;
}

double Calculator::eval_factor() {
	ch_d temp = current();
	auto op = std::get_if<char>(&temp);
	auto num = std::get_if<double>(&temp);

	if (num) {
		advance();
		return *num;
	}
	else {
		if (*op == '-') {
			advance();
			return -eval_factor();
		}
		else if (*op == '+') {
			advance();
			return eval_factor();
		}
		else if (*op == '(') {
			advance();
			double value = eval_expression();
			op = std::get_if<char>(&temp);
			consume(')');
			return value;
		}
	}
	throw std::runtime_error("unexpected value");
}

ch_d Calculator::current() {
	if (m_curr_token < m_args.size()) {
		return m_args[m_curr_token];
	}
}

void Calculator::consume(ch_d t) {
	if (current() == t) {
		m_curr_token++;
	}
	else {
		throw std::runtime_error("right paren not found");
	}
	if (m_curr_token > m_args.size()) {
		m_curr_token = m_args.size();
	}
}

void Calculator::advance() {
	m_curr_token++;
	if (m_curr_token > m_args.size()) {
		m_curr_token = m_args.size();
	}
}

bool Calculator::end(){
	if (m_curr_token == m_args.size()) {
		return true;
	}
	return false;
}

double Calculator::calculate(const std::string &raw_input) {
	m_args = pre_process(raw_input);
	try {
		double value = eval_expression();

		if (m_curr_token != m_args.size()) {
			throw std::runtime_error("invalid expression");
		}
		return value;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what();
	}
	return 0;
}