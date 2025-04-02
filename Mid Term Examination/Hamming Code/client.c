#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

// Detect Error in Hamming Code
int detect_error(int ham[]) {
  int p1 = ham[1] ^ ham[3] ^ ham[5] ^ ham[7];
  int p2 = ham[2] ^ ham[3] ^ ham[6] ^ ham[7];
  int p4 = ham[4] ^ ham[5] ^ ham[6] ^ ham[7];

  return p4 * 4 + p2 * 2 + p1;
}

int main() {
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  struct sockaddr_in addr = {AF_INET, htons(8080)};
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  sendto(sockfd, NULL, 0, 0, (struct sockaddr*)&addr, sizeof(addr));

  int ham[8];
  socklen_t len = sizeof(addr);
  recvfrom(sockfd, ham, sizeof(ham), 0, (struct sockaddr*)&addr, &len);

  ham[3] = ham[3] ? 0 : 1;

  int error_pos = detect_error(ham);
  if (error_pos) {
    printf("Error at position: %d\n", error_pos);
    ham[error_pos] = ham[error_pos] ? 0 : 1;
  }

  printf("Data: %d%d%d%d\n", ham[3], ham[5], ham[6], ham[7]);

  return 0;
}

