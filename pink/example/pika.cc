#include <stdio.h>
#include <unistd.h>

#include "pink_thread.h"
#include "worker_thread.h"
#include "dispatch_thread.h"
#include "pika_thread.h"

using namespace pink;
int main()
{
  PikaThread *pikaThread[1];
  for (int i = 0; i < 1; i++) {
    pikaThread[i] = new PikaThread(1000);
  }
   Thread *t = new DispatchThread<PikaConn>(9211, 1, reinterpret_cast<WorkerThread<PikaConn> **>(pikaThread), 3000);

  t->StartThread();


  sleep(1000);
  return 0;
}
