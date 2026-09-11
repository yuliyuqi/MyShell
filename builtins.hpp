#pragma once
#include "shell.hpp"

/* 返回 true=已处理, should_exit 表示退出 shell */
bool exec_builtin(Command* cmd, bool& should_exit);

/* 别名 */
std::string resolve_alias(const std::string& name);
void load_aliases(const std::string& path);
void save_aliases(const std::string& path);
