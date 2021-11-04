#include <linux/tty.h>

static void print_string(char *str)

{

    /* Declarem un punter a l'estructura tty_struct , si el procés no té un terminal assignat aquest valor apuntarà a NULL indicant que no té cap terminal per poder escriure. Per exemple, si fos un dimoni no tindrà tty i no es podria realitzar.*/

    struct tty_struct *my_tty;

    my_tty = current->signal->tty;

    if (my_tty != NULL)
    {

        / *

            *my_tty->driver és una estructura que manté les funcions del tty,
            un dels quals(write) s'utilitza per escriure cadenes al tty.

                    *Es pot utilitzar per agafar una cadena de l'usuari o segment de memòria del nucli.

                        *Arguments :

            *(1)tty on volem escriure.

                *(2)punter a una cadena.

                    *(3)la longitud de la cadena.

                        * /

                (my_tty->driver->ops->write)(my_tty, str, strlen(str));

        (my_tty->driver->ops->write)(my_tty, "\015\012", 2); //*******
    }
}