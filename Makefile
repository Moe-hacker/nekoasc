SRC = src/main.c src/shared.c src/typewriter.c
BIN_TARGET = nekoasc
CHECKER = clang-tidy --use-color
CHECK_ARG = --checks=*,-clang-analyzer-security.insecureAPI.strcpy,-altera-unroll-loops,-cert-err33-c,-concurrency-mt-unsafe,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-function-cognitive-complexity,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-misc-no-recursion,-bugprone-easily-swappable-parameters,-readability-identifier-length,-cert-err34-c,-bugprone-assignment-in-if-condition,-altera*
all:
	clang -ggdb -O0 -z norelro -z execstack -no-pie -D_FORTIFY_SOURCE=3 -Og -Wall -Wextra -pedantic -Wconversion -std=c2x -Wno-newline-eof -fno-stack-protector -fno-omit-frame-pointer $(SRC) -o $(BIN_TARGET)
format:
	clang-format -i $(SRC) src/nekoasc.h
check :
	@printf "\033[1;38;2;254;228;208mCheck list:\n"
	@sleep 1.5s
	@$(CHECKER) $(CHECK_ARG) --list-checks $(SRC) -- 
	@printf ' \033[1;38;2;254;228;208mCHECK\033[0m \033[34;1m%b\033[0m\n' $(SRC)
	@$(CHECKER) $(CHECK_ARG) $(SRC) --
	@printf ' \033[1;38;2;254;228;208mDONE.\n'