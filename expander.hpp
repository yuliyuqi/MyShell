#pragma once
#include <string>
#include <vector>

/* 全局退出码 */
extern int g_last_status;

/* 展开单个 token: $VAR, ${VAR}, $?, ~, 通配符 */
std::string expand_word(const std::string& word);

/* 展开整个参数列表 */
std::vector<std::string> expand_argv(const std::vector<std::string>& in);
