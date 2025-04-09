#include<stdio.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

int main(){
  int s = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in serv = {AF_INET, htons(7697), INADDR_ANY}, cli;

  bind(s, (void*)&serv, sizeof(serv));
  listen(s, 1);

  int c, len = sizeof(cli);
  c = accept(s, (void*)&cli, &len);

  char buf[20] = "";
  read(c, buf, 20);

  printf("Reg No: 12345678\nMsg: %s", buf);

  close(s);
  return 0;
}

