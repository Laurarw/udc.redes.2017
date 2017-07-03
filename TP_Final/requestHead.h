#ifndef PG_REQHEAD_H
#define PG_REQHEAD_H


/*  Tipos definidos por el usuario  */

enum Req_Method { GET, HEAD, UNSUPPORTED };
enum Req_Type   { SIMPLE, FULL };

struct ReqInfo {
    enum Req_Method method;
    char           *type;
    char           *referer;
    char           *useragent;
    char           *resource;
    int             status;
};


/*  Variables globales  */

#define MAX_REQ_LINE         (1024)


/*  Declaracion de funciones de requestHead  */

int  Parse_HTTP_Header(char * buffer, struct ReqInfo * reqinfo);
int  Get_Request      (int conn, struct ReqInfo * reqinfo);
void InitReqInfo      (struct ReqInfo * reqinfo);
void FreeReqInfo      (struct ReqInfo * reqinfo);

#endif  /*  PG_REQHEAD_H  */
