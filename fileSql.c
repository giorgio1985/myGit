#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

/*
Ricordarsi di far riconoscere al compilatore gcc la libreria libpq-fe.
*/


void esci(PGconn *conn) {
    
    PQfinish(conn);
    exit(1);
}

int main() {
    
    PGconn *conn = PQconnectdb("dbname=data host=localhost user=postgres password=post");

    if (PQstatus(conn) == CONNECTION_BAD) {
        
        fprintf(stderr, "Connessione al database non riuscita! : %s\n",
            PQerrorMessage(conn));
        esci(conn);
    }
    
    char *user = PQuser(conn);
    char *dbNome = PQdb(conn);
    char *psw = PQpass(conn);
    printf("Parametri di connessione utilizzando sia peer che md5 modificabili nel file di configurazione pg_hba.conf\n");
    printf("User: %s\n", user);
    printf("Database name: %s\n", dbNome);
    printf("Password: %s\n", psw);
    printf("Se qualcosa dovesse andare storto spesso bisogna controllare l\' ordine dei parametri della funzione PQconnectdb:\n"); 
    
    PQfinish(conn);

    return 0;
}
