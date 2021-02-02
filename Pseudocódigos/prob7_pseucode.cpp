/* Programa principal */
main(){
    InitSemaphore(Sd, 2);   // Lugares disponibles
    InitSemaphore(So, 0);   // Lugares ocupados

    /* Ejec. Concurr. */
    Parbegin{
        prod
        cons
    Parend
    } 
}


/* Procesos */
Procedure prod{
    while(1){
        p(Sd);
        // Sección crítica Producir
        v(So);
    }
}

Procedure cons{
    while(1){
        P(So);
        P(So);
        // Sección crítica Consumir
        V(Sd);
        V(Sd);
    }
}