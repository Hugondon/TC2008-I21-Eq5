/*
    Para derrotar al dragón de la Grieta del Invocador en el famosísimo League of Legends,
    es necesario que el jugador en jungla esté disponible para asegurarlo (BOTONAZO).
    Tendrá que llamar a bot (a través de un ping de ayuda) para así ayudar a completar el objetivo.
   
    De igual forma, para asegurar este objetivo es necesario que el área cerca del dragón esté
    despejada y esta solamente se encuentra en ese estado al estar jungla y bot ahí por 2 minutos.

    Una vez que jungla y bot estén disponibles y hayan despejado el área, el dragón podrá ser asegurado.

    Después de asegurarlo, ambos personajes dejarán de estar disponibles. 
    El dragón volverá a estar en la Grieta del Invocador después de los reglamentarios 6 minutos de haber sido derrotado.

*/

/* Programa principal */ 
main(){

    /* Semáforos */
    InitSemaphore(Sem_jungla_disponible, 0);        // Jungla está disponible
    InitSemaphore(Sem_bot_disponible, 0);           // Bot está disponible

    /* Banderas */
    bool zona_asegurada = false;
    bool dragon_disponible = true;

    /* Ejec. Concurr. */
    Parbegin{
        pedir_ayuda;
        asegurar_zona;
        matar_dragon;
    }
} 

/* Procesos */

Procedure pedir_ayuda{

    // Esperar botonazo
    V(Sem_jungla_disponible);
    V(Sem_bot_disponible);

}

Procedure asegurar_zona{
    P(Sem_jungla_disponible);
    P(Sem_bot_disponible);
    // Iniciar Timer

}

Procedure matar_dragon{
    if(zona_asegurada){
        // Matar
    }
    // Iniciar Timer
}
