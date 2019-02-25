/* 
 * @copyright (c) 2008, Hedspi, Hanoi University of Technology
 * @author Huu-Duc Nguyen
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include "error.h"

struct ErrorMessage {
  ErrorCode errorCode;
  char *message;
};

struct ErrorMessage errors[4] = {
  {ERR_ENDOFCOMMENT, "End of comment expected!"},
  {ERR_IDENTTOOLONG, "Identification too long!"},
  {ERR_INVALIDCHARCONSTANT, "Invalid const char!"},
  {ERR_INVALIDSYMBOL, "Invalid symbol!"}};

void error(ErrorCode err, int lineNo, int colNo) {
  int i;
  for (i = 0 ; i < NUM_OF_ERRORS; i ++) 
    if (errors[i].errorCode == err) {
      printf("%d-%d:%s\n", lineNo, colNo, errors[i].message);
      exit(0);
    }
}

