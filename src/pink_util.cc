#include "pink_util.h"
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include "pink_define.h"

namespace pink {

int Setnonblocking(int sockfd)
{
  int flags;
  if ((flags = fcntl(sockfd, F_GETFL, 0)) < 0) {
    close(sockfd);
    return -1;
  }
  flags |= O_NONBLOCK;
  if (fcntl(sockfd, F_SETFL, flags) < 0) {
    close(sockfd);
    return -1;
  }
  return flags;
}

}
