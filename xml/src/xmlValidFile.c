#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/lib/xmlparse.c"
#include <../include/lib/elements.h>

int main(int argc, char *argv[]){
  char buf[BUFSIZ];
  // File* fic = fopen("monfichier.xml","r");
  XML_Parser parser = XML_ParserCreate(NULL);
  int done;
  int depth = 0;
  (void)argc;
  (void)argv;

  XML_SetUserData(parser, &depth);
  XML_SetElementHandler(parser, startElement, endElement);
  do {
    size_t len = fread(buf, 1, sizeof(buf), stdin);
    done = len < sizeof(buf);
    if (XML_Parse(parser, buf, (int)len, done) == XML_STATUS_ERROR) {
      fprintf(stderr,
              "%" XML_FMT_STR " at line %" XML_FMT_INT_MOD "u\n",
              XML_ErrorString(XML_GetErrorCode(parser)),
              XML_GetCurrentLineNumber(parser));
      return 1;
    }
  } while (!done);
  XML_ParserFree(parser);
  return 0;
}