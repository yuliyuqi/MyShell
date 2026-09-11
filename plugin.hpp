#pragma once
/* ============================================================
 * plugin.hpp — 插件系统
 *
 * 插件 (.dll/.so) 需导出:
 *   const char* plugin_name();
 *   const char* plugin_help();
 *   int plugin_run(int argc, char** argv);  // 返回退出码
 *
 * 放在 plugins/ 目录，shell 启动时自动加载
 * ============================================================ */

void plugin_load_all();
int  plugin_exec(const char* name, int argc, char** argv);
void plugin_unload_all();
