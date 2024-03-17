/**
 *
 * File Name: utils.h
 *
 * Description:
 *      This header file consists of function used for
 *      debugging purposes
 *
 */

#pragma once

#include "Common.h"

#ifdef DEBUG
#define LOG_SYM     "[DEBUG LOG]"
#else
#define LOG_SYM     "[LOG]"
#endif

namespace AcerEngine {
    enum Color {
        RED,
        GREEN,
        YELLOW,
        CYAN,
        WHITE,
    };

    void SetConsoleColor(Color color);
    void DisplayLogMessage(Color color, const char *str);
}
