/* Programa principal */
main(){
    
    /* Semáforos. */
    InitSemaphore(S_mesa_pedidos_disponible, 1);        //
    InitSemaphore(S_mesa_hamburguesas_disponible, 1);   //
    InitSemaphore(S_mesa_ordenes_disponible, 1);        //

    InitSemaphore(S_mesa_pedidos_ocupada, 0);           //
    InitSemaphore(S_mesa_hamburguesas_ocupada, 0);      //
    InitSemaphore(S_mesa_ordenes_ocupada, 0);           //

    InitSemaphore(S_orden, 0);                          //
    InitSemaphore(S_cocinar_hamburguesas, 0);           //

    /* Ejec. Concurr. */
    Parbegin{
        p_despachador       //      Producir órdenes
        p_empacador         /*      Sacar órdenes de mesa.
                            *       Obtener hamburguesa de mesa de hamburguesas
                            *       Poner en mesa de pedidos.     
                            */  
        p_cocinero          //      Poner hambuguesas en mesa de hamburgesas.
        p_cajero            //      Entregar pedidos
        p_cliente           //      Generar órdenes
    Parend
    } 
}

/* Procesos */

Procedure p_cliente{
    // Botonazo
    v(S_orden);
}

Procedure p_despachador{

    p(S_orden);
    p(S_mesa_ordenes_disponible);

    /* Sección crítica */

    v(S_cocinar_hamburguesas);
    v(S_mesa_ordenes_ocupada);
}

Procedure p_cocinero{


    p(S_cocinar_hamburguesas);
    
    p(S_mesa_hamburguesas_disponible);

    /* Sección crítica */

    v(S_mesa_hamburguesas_ocupada);
}

Procedure p_empacador{


    p(S_mesa_ordenes_ocupada);
    p(S_mesa_hamburguesas_ocupada);

    P(S_mesa_pedidos_disponible);

    // Sección crítica 

    v(S_mesa_hamburguesas_disponible);
    v(S_mesa_ordenes_disponible);
    v(S_mesa_pedidos_ocupados);
}

Procedure p_cajero{
    p(S_mesa_pedidos_ocupada);

    // Sección crítica

    v(S_mesa_pedidos_disponible);
}





