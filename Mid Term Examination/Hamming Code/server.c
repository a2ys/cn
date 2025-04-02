#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>

// 4-bit data with parity
void encode(int data[], int ham[]) {
  ham[3] = data[0];
  ham[5] = data[1];
  ham[6] = data[2];
  ham[7] = data[3];

  ham[1] = ham[3] ^ ham[5] ^ ham[7];
  ham[2] = ham[3] ^ ham[6] ^ ham[7];
  ham[4] = ham[5] ^ ham[6] ^ ham[7];
}

int main() {
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  struct sockaddr_in addr = {AF_INET, htons(8080), INADDR_ANY};
  bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));

  int data[4] = {1, 0, 1, 1};
  int ham[8] = {0};
  encode(data, ham);

  struct sockaddr_in client;
  socklen_t len = sizeof(client);
  recvfrom(sockfd, NULL, 0, MSG_PEEK, (struct sockaddr*)&client, &len);
  sendto(sockfd, ham, sizeof(ham), 0, (struct sockaddr*)&client, len);

  return 0;
}

