#include "nekoasc.h"
bool is_pipe()
{
  /*
   * Simply check the file type of /proc/self/fd/0
   * and return true if it is a pipe.
   */
  struct stat statbuf;
  stat("/proc/self/fd/0", &statbuf);
  if (S_ISFIFO(statbuf.st_mode))
  {
    return true;
  }
  return false;
}
void error(char *msg)
{
  /*
   * Show error message and exit.
   */
  fprintf(stderr, "\033[31m%s\033[0m\n", msg);
  // A very cute catgirl nya~~
  fprintf(stderr, "\033[1;38;2;254;228;208m%s\033[0m\n", "  .^.   .^.");
  fprintf(stderr, "\033[1;38;2;254;228;208m%s\033[0m\n", "  /⋀\\_ﾉ_/⋀\\");
  fprintf(stderr, "\033[1;38;2;254;228;208m%s\033[0m\n", " /ﾉｿﾉ\\ﾉｿ丶)|");
  fprintf(stderr, "\033[1;38;2;254;228;208m%s\033[0m\n", " ﾙﾘﾘ >  x )ﾘ");
  fprintf(stderr, "\033[1;38;2;254;228;208m%s\033[0m\n", "ﾉノ㇏  ^ ﾉ|ﾉ");
  fprintf(stderr, "\033[1;38;2;254;228;208m%s\033[0m\n", "      ⠁⠁");
  fprintf(stderr, "\033[1;38;2;254;228;208m%s\033[0m\n", "If you think something is wrong, please report at:");
  fprintf(stderr, "\033[4;1;38;2;254;228;208m%s\033[0m\n", "https://github.com/Moe-hacker/mescii/issues");
  exit(1);
}
void get_input(char *buf, int len)
{
  /*
   * Simply use getchar() to get input
   * and write it to *buf.
   * We do not use read() because it causes bugs.
   */
  char input = 0;
  for (int i = 0; i < len; i++)
  {
    input = (char)getchar();
    if (input == EOF)
    {
      buf[i] = '\000';
      break;
    }
    buf[i] = input;
  }
}