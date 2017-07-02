#ifndef PG_RESPHEAD_H
#define PG_RESPHEAD_H


#include "requestHead.h"  /*  se incluye para conocer la estructura ReqInfo  */


/*  Declaracion de las funciones de responseHead  */

int Output_HTTP_Headers(int conn, struct ReqInfo * reqinfo);


#endif  /*  PG_RESPHEAD_H  */
