/* msg.x: Remote msg printing protocol */

/* links: http://www.eletrica.ufpr.br/pedroso/2009/TE090/Aulas/rpc.pdf , to compile: rpcgen msg.x */

program MESSAGEPROG {
    version PRINTMESSAGEVERS {
        int PRINTMESSAGE(string) = 1; 
    } = 1;
} = 0x20000001;