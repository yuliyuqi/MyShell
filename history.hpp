#pragma once
#include <string>
#include <vector>

constexpr int HIST_MAX = 1000;

void   history_init();
void   history_restore();
bool   history_is_interactive();
void   history_add(const std::string& cmd);
void   history_save(const std::string& path);
void   history_load(const std::string& path);
std::string history_readline(const std::string& prompt);
const std::vector<std::string>& history_list();
