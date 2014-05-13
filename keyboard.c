#include <stdio.h>
#include <strings.h>
#include "2048.h"

int parse_input(char *line)
{
  // Chop CR or LF characters from end of line
  while (line[0]&&
	 ((line[strlen(line)-1]=='\n')
	  ||(line[strlen(line)-1]=='\r')))
    line[strlen(line)-1]=0;

 if (!strcasecmp(line,"l")) return GO_UP; // left
  if (!strcasecmp(line,"r")) return GO_DOWN; // right
  if (!strcasecmp(line,"u")) return GO_LEFT; // up
  if (!strcasecmp(line,"d")) return GO_RIGHT; // down
  if (line[0]==0) return GO_NOWHERE; // blank input
  return INVALID_INPUT; // invalid input
}

int read_input()
{
  // Read line of input from stdin
  char line[1024];
  line[0]=0; fgets(line,1024,stdin);

  return parse_input(line);
}
