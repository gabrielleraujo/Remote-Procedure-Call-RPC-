--------------------------------------------------------------------------------------------------------------------------
RPC rpcgen: a rpcgen fornece aos programadores uma maneira simples e direta de escrever aplicativos distribuídos.
--------------------------------------------------------------------------------------------------------------------------

Para compilar o exemplo de rprintmsg remoto:

compilar o protocolo definido em msg.x: rpcgen msg.x.
Isso gera os arquivos de cabeçalho(msg.h),o stub do cliente(msg_clnt.c)e o stub do servidor(msg_svc.c).

compilar o cliente executável:
 cc rprintmsg.c msg_clnt.c -o rprintmsg -lnsl
compilar o servidor executável:
 cc msg_proc.c msg_svc.c -o msg_server -lnsl
Os arquivos de objeto C devem ser vinculados à libnsl biblioteca, que contém todas as funções de rede, incluindo as de RPC e XDR.

Neste exemplo, nenhuma rotina de XDR foi gerada porque o aplicativo utiliza apenas os tipos básicos que estão incluídos no libnsl . Vamos considerar mais o que a Rpcgen fez com o arquivo de entrada msg.x:

Ele criou um arquivo de cabeçalho chamado msg.h que continha instruções para MESSAGEPROG, MESSAGEVERS e PRINTMESSAGE para uso nos outros módulos. Este arquivo deve ser incluído pelos módulos cliente e servidor. #define
Ele criou as rotinas de stub do cliente no arquivo msg_clnt.c. Aqui há apenas um, o printmessage_1 rotina, que foi chamado do programa cliente rprintmsg. Se o nome de um arquivo de entrada rpcgen for prog.x,o arquivo de saída do stub do cliente será chamado prog_clnt.c.
Ele criou o programa de servidor em msg_svc.c que chama printmessage_1 de msg_proc.c. A regra para nomear o arquivo de saída do servidor é semelhante à do cliente: para um arquivo de entrada chamado prog.x,o arquivo do servidor de saída é nomeado prog_svc.c.
Uma vez criado, o programa do servidor é instalado em uma máquina remota e executado. (Se as máquinas forem homogêneas, o binário do servidor pode ser copiado. Se não forem, os arquivos de origem do servidor devem ser copiados e compilados na máquina remota.)

remote$ msg_server
Processos de servidor gerados com sempre executados em segundo plano. Você não precisa acompanhar a invocação do servidor com um ampersand (&). Os servidores gerados também podem ser invocados por monitores de porta como e, em vez de da linha de comando. rpcgenrpcgenlisten()inetd()
./
Depois disso, um usuário no local pode imprimir uma mensagem no console do controle remoto da máquina da seguinte forma:

local$ rprintmsg remote "Hello, there."
Usando , o usuário pode imprimir uma mensagem em qualquer console do sistema, incluindo o console local, quando o servidor msg_server está sendo executado no sistema de destino. rprintmsg

--------------------------------------------------------------------------------------------------------------------------

A test example:
- You need to install a rpcbind
- and check if this is already running.
remote$ sudo rpcbind
remote$ ./msg_server

local$ ./rprintmsg localhost "Hello, there."

--------------------------------------------------------------------------------------------------------------------------