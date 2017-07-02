#ifndef PG_RESOURCE_H
#define PG_RESOURCE_H


#include "requestHead.h"         /*  se incluye para conocer la estructura ReqInfo  */


/*  Declaracion de las funciones brindadas por resource  */

int Return_Resource (int conn, int resource, struct ReqInfo * reqinfo);
int Check_Resource  (struct ReqInfo * reqinfo);
int Return_Error_Msg(int conn, struct ReqInfo * reqinfo);


#endif  /*  PG_RESOURCE_H  */
