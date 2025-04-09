#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
  int s = socket(AF_INET, SOCK_DGRAM, 0);
  struct sockaddr_in serv = {AF_INET, htons(7697), inet_addr("127.0.0.1")};

  char b[50];
  fgets(b, 50, stdin);  
  sendto(s, b, 50, 0, (void*)&serv, sizeof(serv));
  close(s);
}

