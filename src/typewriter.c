#include "nekoasc.h"
void typewriter(char *buf, unsigned int rate)
{
  /*
   * A simple animation that prints *buf
   * to the screen, and usleep() per-character
   * to make it a typewriter effect.
   * Control characters will not trigger usleep()
   * to make sure that the output speed is correct.
   * It can only recognize control characters
   * starts with `\033` and ends with `m`.
   */
  bool control_char = false;
  for (unsigned long i = 0; i < strlen(buf); i++)
  {
    printf("%c", buf[i]);
    fflush(stdout);
    if (!control_char)
    {
      usleep(rate);
    }
    if (buf[i] == '\033')
    {
      control_char = true;
    }
    else if (buf[i] == 'm')
    {
      control_char = false;
    }
  }
  printf("\n");
}