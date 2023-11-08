SRC = src/main.c src/shared.c src/typewriter.c src/input.c src/blink.c
BIN_TARGET = nekoasc
CHECKER = clang-tidy --use-color
CHECK_ARG = --checks=*,-clang-analyzer-security.insecureAPI.strcpy,-altera-unroll-loops,-cert-err33-c,-concurrency-mt-unsafe,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-readability-function-cognitive-complexity,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-misc-no-recursion,-bugprone-easily-swappable-parameters,-readability-identifier-length,-cert-err34-c,-bugprone-assignment-in-if-condition,-altera*
COMMIT_ID = -DNEKOASC_COMMIT_ID=\"`git log --oneline|head -1|cut -d " " -f 1`\"
all:
	clang -ggdb -O0 -z norelro -z execstack -D_FORTIFY_SOURCE=3 -Og -Wall -Wextra -pedantic -Wconversion -std=c2x -Wno-newline-eof -fno-stack-protector -fno-omit-frame-pointer $(COMMIT_ID) $(SRC) -o $(BIN_TARGET)
format:
	clang-format -i src/*
check :
	@printf "\033[1;38;2;254;228;208mCheck list:\n"
	@sleep 1.5s
	@$(CHECKER) $(CHECK_ARG) --list-checks $(SRC) -- 
	@printf ' \033[1;38;2;254;228;208mCHECK\033[0m \033[34;1m%b\033[0m\n' $(SRC)
	@$(CHECKER) $(CHECK_ARG) $(SRC) -- $(COMMIT_ID)
	@printf ' \033[1;38;2;254;228;208mDONE.\n'