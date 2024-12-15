#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <typeinfo>
#include <exception>
 
#include "Read_file.h"

class Config {

public:
	void InteractiveVarTask(const std::string& v_text) noexcept;

private:
	std::string number_task{ };
	bool exit = true;
	std::string text{};
	enum class Task;
	void VarTaskNumber() noexcept;
	bool ExitProgram() noexcept;
	void ConsolLang1251() noexcept;
};

#endif