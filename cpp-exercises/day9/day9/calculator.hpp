#pragma once
#include <vector>
#include <variant>
#include <iostream>
using ch_d = std::variant<double, char>;

class Calculator {
	std::vector<ch_d> m_args;
	std::size_t m_curr_token{};

	std::vector<ch_d> pre_process(const std::string& raw_input);

	ch_d current();
	void consume(ch_d t);
	void advance();
	bool end();

	double eval();
	double eval_expression();
	double eval_term();
	double eval_factor();

public:
	double calculate(const std::string&);
};