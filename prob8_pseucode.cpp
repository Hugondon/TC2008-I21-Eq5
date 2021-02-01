/* Programa principal */
main(){
    
    /* Semáforos. */
    InitSemaphore(S_mesa_pedidos_ocupada, 0);           //
    InitSemaphore(S_mesa_pedidos_disponible, 0);        //
    InitSemaphore(S_mesa_hamburguesas_ocupada, 0);      //
    InitSemaphore(S_mesa_hamburguesas_disponible, 0);   //
    InitSemaphore(S_mesa_ordenes_ocupada, 0);           //
    InitSemaphore(S_mesa_ordenes_disponible, 0);        //

    InitSemaphore(S_orden, 0);                          //

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
Procedure p_despachador{
    // Todo el tiempo hay órdenes ?
    p(S_orden);
    p(S_mesa_ordenes_disponible);
    // Sección crítica (anotar y entregar orden)
    v(S_mesa_ordenes_ocupada);
}

Procedure p_empacador{
    p(S_mesa_ordenes_ocupada);
    p(S_mesa_hamburguesas_ocupada);
    p(S_mesa_pedidos_disponible);
    // Sección crítica (coger hamburguesa)
    v(S_mesa_hamburguesas_disponible);
    v(S_mesa_ordenes_disponible);
    v(S_mesa_pedidos_ocupados);
}

Procedure p_cocinero{
    p(S_mesa_hamburguesas_disponible);
    // Sección crítica (hacer hamburguesa y ponerla en la mesa)
    v(S_mesa_hamburguesas_ocupada);
}

Procedure p_cajero{
    p(S_mesa_pedidos_ocupada);
    // Sección crítica. Prender un LED
    v(S_mesa_pedidos_disponible);
}

Procedure p_cliente{
    // Botonazo
    v(S_orden);
}