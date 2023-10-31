#define _GNU_SOURCE
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
// VSCode doesn't think bool is standard C keyword,
// make it happy.
#include <stdbool.h>
enum
{
  BUF_SIZE = (1024 * 1024)
};
bool is_pipe();
void error(char *msg);
void typewriter(char *buf, unsigned int rate);
void get_input(char *buf, int len);