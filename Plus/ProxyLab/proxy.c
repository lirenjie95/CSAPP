#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csapp.h"
/* Recommended max cache and object sizes */
#define MAX_CACHE_SIZE 1049000
#define MAX_OBJECT_SIZE 102400
/* You won't lose style points for including this long line in your code */
static const char *user_agent_hdr = "User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:10.0.3) Gecko/20120305 Firefox/10.0.3\r\n";

void parse(char *uri, char *hostname, char *path, char *port)
{
    int httplen = (strlen("http://"));
    int i = httplen;
    int port_position = 0;
    int path_position = 0;
    while (i < strlen(uri) && uri[i]- ':' != 0) {
        i++;
    }
    /* if: found port, else: not found */
    if (i < strlen(uri) - 1) {
        port_position = i;
        while (uri[i]- '/' != 0) {
            i++;
            if (i == strlen(uri)) {
                break;
            }
        }
        path_position = i;
    } else {
        i = strlen("http://");
        while (uri[i]- '/' != 0) {
            i++;
            if (i == strlen(uri)) {
                break;
            }
        }
        path_position = i;
    }
    /* if found port */
    if (port_position > 0) {
        strncpy (hostname, uri+httplen, port_position-httplen);
        if (path_position != strlen(uri)) {
            strncpy (port, uri+port_position+1, path_position-port_position-1);
        } else {
            strncpy (port, uri+port_position+1, strlen(uri)-port_position-1);
        }
    } else {
        strncpy (hostname, uri+httplen, path_position-httplen);
        strncpy(port, "80", 2);
    }
    /* if found path */
    if (path_position != strlen(uri)) {
        strncpy (path, uri+path_position, strlen(uri)-path_position);
    } else {
        strncpy (path, "/", strlen("/"));
    }
    return;
}
void doit (int fd)
{
    char tempbuf[MAXLINE], buf[MAXLINE], webbuf[MAXLINE], request_buf[MAXLINE];
    char method[MAXLINE], uri[MAXLINE], version[MAXLINE];
    char hostname[MAXLINE], request_port[MAXLINE], path[MAXLINE];
    char uri_check[7];
    int clientfd;
    int sethost = 1;
    rio_t rio_toclient, rio_toserver;
    rio_readinitb(&rio_toclient, fd);
    if (rio_readlineb(&rio_toclient, request_buf, MAXLINE) <= 0) {
        printf ("Invalid Request.\n");
        return;
    }
    sscanf (request_buf, "%s %s %s", method, uri, version);
    /* checking method */
    if (strcmp(method, "GET") != 0) {
        rio_writen(fd, "Method Invalid.\n", strlen("Method Invalid.\n"));
        return;
    }
    /* checking URI */
    if (strcmp(strncpy(uri_check, uri, 7), "http://") != 0) {
        rio_writen(fd, "URI Invalid.\n", strlen("URI Invalid.\n"));
        return;
    }
    /* set zeros */
    memset(path, 0, strlen(path));
    memset(hostname, 0, strlen(hostname));
    memset(request_port, 0, strlen(request_port));
    parse (uri, hostname, path, request_port);
    sprintf(buf, "GET %s HTTP/1.0\r\n", path);
    sprintf(buf, "%sConnection: close\r\n", buf);
    sprintf(buf, "%sProxy-Connection: close\r\n", buf);
    while (rio_readlineb(&rio_toclient, request_buf, MAXLINE) > 2) {
        memset(tempbuf, 0, strlen(tempbuf));
        strncpy(tempbuf, request_buf, strlen("Connection"));
        /* ignoring Connection header */
        if (strcmp(tempbuf, "Connection") != 0) {
            memset(tempbuf, 0, strlen(tempbuf));
            strncpy(tempbuf, request_buf, strlen("Proxy-Connection"));
            /* ignoring Proxy-Connection header */
            if (strcmp(tempbuf, "Proxy-Connection") != 0) {
                memset(tempbuf, 0, strlen(tempbuf));
                strncpy(tempbuf, request_buf, strlen("Host:"));
                /* if header contains host, don't add host header */
                if (strcmp(tempbuf, "Host:") == 0) {
                    sethost = 0;
                }
                sprintf(buf, "%s%s", buf, request_buf);
            }
        }
    }
    if (sethost) {
        sprintf(buf, "%sHost: %s\r\n", buf, hostname);
    }
    sprintf(buf, "%s\r\n", buf);
    clientfd = open_clientfd(hostname, request_port);
    rio_readinitb(&rio_toserver, clientfd);
    rio_writen(clientfd, buf, strlen(buf));
    size_t n;
    while((n = rio_readnb(&rio_toserver, webbuf, MAXLINE)) > 0) {
        rio_writen(fd, webbuf, n);
    }
}
void *thread(void *vargp)
{
    int connfd = *((int *)vargp);
    Pthread_detach(pthread_self());
    Free(vargp);
    doit(connfd);
    close(connfd);
    return NULL;
}

int main(int argc, char **argv)
{
    int listenfd;
    int port;
    int *connfdp;
    struct sockaddr_in clientaddr;
    int clientlen = sizeof (clientaddr);
    pthread_t tid;

    signal (SIGPIPE, SIG_IGN);

    if (argc != 2) {
        printf("Invalid argument.\n");
	exit(0);
    }
    listenfd = open_listenfd(argv[1]);
    while (1) {
        connfdp = malloc(sizeof(int));
        *connfdp = accept(listenfd, (SA*) &clientaddr, (socklen_t*) &clientlen);
        pthread_create(&tid, NULL, thread, connfdp);
    }
    printf("%d\n",port);
    printf("%s", user_agent_hdr);
    return 0;
}
