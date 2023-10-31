#include "nekoasc.h"
int main()
{
  if (!is_pipe())
  {
    error("This program only gets input with a pipe!");
  }
  char buf[BUF_SIZE] = {'\000'};
  get_input(buf, BUF_SIZE);
  typewriter(buf, 40000);
}