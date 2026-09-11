#pragma once
#include "shell.hpp"

std::unique_ptr<CmdList> parse_cmd(const std::string& input);
