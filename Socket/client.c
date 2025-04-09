#include<stdio.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main(){
  int s = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in serv = {AF_INET, htons(7697), inet_addr("127.0.0.1")};
  connect(s, (void*)&serv, sizeof(serv));

  char buf[20];
  printf("Enter: "); 
  fgets(buf, 20, stdin);
  write(s, buf, 20);

  close(s);
  return 0;
}

