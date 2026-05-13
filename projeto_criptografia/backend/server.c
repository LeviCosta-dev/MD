#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int server_fd, client_socket;

    struct sockaddr_in address;

    int addrlen = sizeof(address);

    // cria socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // configura endereço
    address.sin_family = AF_INET;

    address.sin_addr.s_addr = INADDR_ANY;

    address.sin_port = htons(8080);

    // liga socket à porta
    bind(server_fd,
         (struct sockaddr *)&address,
         sizeof(address));

    // coloca em modo servidor
    listen(server_fd, 3);

    printf("Servidor em http://localhost:8080\n");

    // espera cliente
    client_socket = accept(server_fd,
                           (struct sockaddr *)&address,
                           (socklen_t*)&addrlen);

    // resposta HTTP
    char *response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n\r\n"
        "<h1>Funcionou!</h1>";

    // envia
    send(client_socket,
         response,
         strlen(response),
         0);

    close(client_socket);
    close(server_fd);

    return 0;
}