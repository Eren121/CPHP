#ifndef TESTS_ANSI_H
#define TESTS_ANSI_H

#define ANSI_ESCAPE(code) "\033[" #code "m"
#define CLEAR "\033[0m" "\033[39m"
#define BG_GREEN "\033[42m"
#define BG_RED "\033[41m"

#endif // TESTS_ANSI_H
