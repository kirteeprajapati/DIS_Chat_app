#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg){
    perror(msg);
    exit(1);
}
int main(int argc, char *argv[]){
    if(argc<2){
        fprintf(stderr, "Port No not provided. Program terminated\n");
        exit(1);
    }
    int sockfd, newsockfd, portno, n;
    char buffer[256];

    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd<0)
        {
        error("Error opening Socket.");
        }
        bzero((char *)&serv_addr, sizeof(serv_addr));
        portno = atoi(argv[1]);

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(portno);

        if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))<0)
        error("Binding Failed");

        listen(sockfd, 5); //max no of client that can be connected
        clilen = sizeof(cli_addr);

        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

        if(newsockfd<0)
        error("Error on Accept");

        while(1)
        {
            //main code
            bzero(buffer, 255);
            n = read(newsockfd, buffer, 255);
            if(n<0)
                error("Error on reading.");
            printf("Client: %s", buffer);
            bzero(buffer, 255);
            fgets(buffer, 255, stdin);
            n = write(newsockfd, buffer, strlen(buffer));
            if(n<0)
                error("Error on writing.");
            int i = strncmp("Bye", buffer, 3);
            if(i==0)
                break;
        }

        // int num1, num2, num3, answer;
        // n = write(newsockfd, "Enter Number 1: ", strlen("Enter Number 1")); // Ask for Number 1
        // if(n<0)
        // error("Error Writing to socket");                         
        // read(newsockfd, &num1, sizeof(int));                      
        // printf("Client Number 1 is: %d\n", num1);                 // Read num 1

        // n = write(newsockfd, "Enter Number 2: ", strlen("Enter Number 2")); // Ask for Number 1
        // if (n < 0)
        // error("Error Writing to socket");
        // read(newsockfd, &num2, sizeof(int));
        // printf("Client Number 2 is: %d\n", num2); // Read num 1

        // n = write(newsockfd, "Enter Number 3: ", strlen("Enter Number 3")); // Ask for Number 1
        // if (n < 0)
        // error("Error Writing to socket");
        // read(newsockfd, &num3, sizeof(int));
        // printf("Client Number 3 is: %d\n", num3); // Read num 1

        // answer = (num1 + num2 + num3) / 3;

        // write(newsockfd, &answer, sizeof(int));

        close(newsockfd);
        close(sockfd);
        return 0;
}
