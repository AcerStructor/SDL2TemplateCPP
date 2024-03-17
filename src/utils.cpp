#include "utils.h"

namespace AcerEngine {
    void SetConsoleColor(Color color) {
        switch(color) {
            case RED:
                printf("\033[0;31m");
                break;

            case GREEN:
                printf("\033[0;32m");
                break;

            case YELLOW:
                printf("\033[0;33m");
                break;

            case CYAN:
                printf("\033[0;36m");
                break;

            case WHITE:
                printf("\033[0m");
                break;
        }
    }

    void DisplayLogMessage(Color color, const char *str) {
        SetConsoleColor(color);
        printf("%s %s\n", LOG_SYM, str);
        SetConsoleColor(WHITE);
    }
}
