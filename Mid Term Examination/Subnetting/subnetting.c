#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
  int ip[4], cidr, subnets, hosts;
  int start_ip, first_ip, last_ip, broadcast;

  // Inputs
  printf("Enter IP Address (e.g. 127.0.0.0): ");
  scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
  printf("Enter CIDR Notation (e.g. 24): ");
  scanf("%d", &cidr);
  printf("Enter number of subnets required: ");
  scanf("%d", &subnets);
  printf("Enter number of hosts required: ");
  scanf("%d", &hosts);

  int bits = (int) ceil(log2(hosts + 2));
  int number_of_hosts = pow(2, bits);

  int subnet_bits = (int) ceil(log2(subnets));
  int mask = 0xFFFFFFFF << (32 - cidr - subnet_bits);
  int base_ip = (ip[0] << 24) | (ip[1] << 16) | (ip[2] << 8) | ip[3];

  for (int i = 0; i < subnets; i++) {
    start_ip = base_ip + (i * number_of_hosts);
    first_ip = start_ip + 1;
    last_ip = start_ip + number_of_hosts - 2;
    broadcast = start_ip + number_of_hosts - 1;

    printf("\nSubnet %d:\n", i + 1);
    printf("Subnet ID: %d.%d.%d.%d\n", (start_ip >> 24) & 0xFF, (start_ip >> 16) & 0xFF, (start_ip >> 8) & 0xFF, start_ip & 0xFF);
    printf("Subnet Mask: %d.%d.%d.%d\n", (mask >> 24) & 0xFF, (mask >> 16) & 0xFF, (mask >> 8) & 0xFF, mask & 0xFF);
    printf("First usable IP: %d.%d.%d.%d\n", (first_ip >> 24) & 0xFF, (first_ip >> 16) & 0xFF, (first_ip >> 8) & 0xFF, first_ip & 0xFF);
    printf("Last usable IP: %d.%d.%d.%d\n", (last_ip >> 24) & 0xFF, (last_ip >> 16) & 0xFF, (last_ip >> 8) & 0xFF, last_ip & 0xFF);
    printf("Broadcast IP: %d.%d.%d.%d\n", (broadcast >> 24) & 0xFF, (broadcast >> 16) & 0xFF, (broadcast >> 8) & 0xFF, broadcast & 0xFF);
    printf("Total Usable Hosts: %d\n", number_of_hosts - 2);
  }

  return 0;
}

