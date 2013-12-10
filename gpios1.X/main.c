/*
 * parpadeo de un led (RA1) cada 50000 cuentas.
 * solo carga el programa y listo el led ya esta en tu tarjeta, conectado al pin RA1
 * por default la velocidad de ejecucion seria de 12MHz
 */

#include <p18cxxx.h>
#include "vectors.h"
#include "types.h"
#include "gpios/gpios.h"

#pragma code
void main(void)
{
    _U16 i;         /*declaramos variable para contar*/

    ANCON0 = 0XFF;  /*Desativamos las salidas analogicas*/
    ANCON1 = 0XFF;  /*Desativamos las salidas analogicas*/

    Gpios_PinDirection(GPIOS_PORTA, 1, GPIOS_OUTPUT);          /*puerto RA1 como salida*/

    while (1)
    {
        Gpios_TogglePin(GPIOS_PORTA, 1);        /*invierto el estado del led conectado al puerto A pin 1*/
        for(i=0;i<50000;i++);               /*ciclamos el procesador para observar el estado del led*/
    }
}


#pragma interrupt YourHighPriorityISRCode
void YourHighPriorityISRCode(void)
{
    /*coloca aqu� el c�digo que llevar� tu interrupci�n en caso de usarla*/
}

#pragma interruptlow YourLowPriorityISRCode
void YourLowPriorityISRCode(void)
{
    /*coloca aqu� el c�digo que llevar� tu interrupci�n de baja prioridad en caso de usarla*/
}
