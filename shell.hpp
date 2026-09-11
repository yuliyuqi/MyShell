#pragma once
/* ============================================================
 * shell.hpp — 公共常量 & 类型
 * ============================================================ */

#include <string>
#include <vector>
#include <memory>
#include <cstdint>

/* ---- 缓冲区大小 ---- */
constexpr int BUFF_SIZE  = 1024;
constexpr int PATH_SIZE  = 512;

/* ---- Token 类型 ---- */
enum class TokenType : uint8_t {
    Word, Pipe, RedirOut, RedirAppend, RedirIn, Background, And, Or, End
};

/* ---- 逻辑连接符 ---- */
enum class Connector : uint8_t {
    None, And, Or, Background
};

/* ---- 单段命令 ---- */
struct Command {
    std::vector<std::string> args;
    std::string infile;
    std::string outfile;
    bool append = false;
    std::unique_ptr<Command> next;  /* | 管道下一段 */
};

/* ---- 管道 ---- */
struct Pipeline {
    std::unique_ptr<Command> head;
    bool background = false;
};

/* ---- 逻辑命令链 (&&, ||, &) ---- */
struct CmdList {
    std::unique_ptr<Pipeline> pl;
    Connector connector = Connector::None;
    std::unique_ptr<CmdList> next;
};

/* ---- 颜色 ---- */
inline const char* CLR_GREEN  = "\033[1;32m";
inline const char* CLR_BLUE   = "\033[1;34m";
inline const char* CLR_YELLOW = "\033[1;33m";
inline const char* CLR_RED    = "\033[1;31m";
inline const char* CLR_RESET  = "\033[0m";
