#pragma once
#include "shell.hpp"

std::string check_danger(Command* cmd);
int run_pipeline(Pipeline* pl);
int run_cmdlist(CmdList* list);
std::string path_search(const std::string& cmd);
