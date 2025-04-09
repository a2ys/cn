#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
  int s = socket(AF_INET, SOCK_DGRAM, 0);
  struct sockaddr_in a = {AF_INET, htons(7697), INADDR_ANY};
  bind(s, (void*)&a, sizeof(a));
  
  char b[50];
  struct sockaddr_in c;
  socklen_t l = sizeof(c);
  
  recvfrom(s, b, 50, 0, (void*)&c, &l);
  printf("%s", b);
  close(s);
}

