#include "proton/message.h"
#include "proton/messenger.h"

#include <getopt.h>
#include <proton/util.h>
#include <sys/time.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define check(messenger)                                                     \
  {                                                                          \
    if(pn_messenger_errno(messenger))                                        \
    {                                                                        \
      printf("check\n");                                                     \
      die(__FILE__, __LINE__, pn_error_text(pn_messenger_error(messenger))); \
    }                                                                        \
  }

pn_timestamp_t time_now(void)
{
  struct timeval now;
  if (gettimeofday(&now, NULL)) pn_fatal("gettimeofday failed\n");
  return ((pn_timestamp_t)now.tv_sec) * 1000 + (now.tv_usec / 1000);
}

void die(const char *file, int line, const char *message)
{
  printf("Dead\n");
  fprintf(stderr, "%s:%i: %s\n", file, line, message);
  exit(1);
}

int sendMessage(pn_messenger_t * messenger) {
    char * address = (char *) "amqps://{{1}}:{{2}}@{{3}}.servicebus.windows.net/{{4}}";
    char * msgtext = (char *) "Hello from C!";

    pn_message_t * message;
    pn_data_t * body;
    message = pn_message();

    pn_message_set_address(message, address);
    pn_message_set_content_type(message, (char*) "application/octect-stream");
    pn_message_set_inferred(message, true);

    body = pn_message_body(message);
    pn_data_put_binary(body, pn_bytes(strlen(msgtext), msgtext));

    pn_messenger_put(messenger, message);
    check(messenger);
    pn_messenger_send(messenger, 1);
    check(messenger);

    pn_message_free(message);
}

int main(int argc, char** argv) {
    printf("Press Ctrl-C to stop the sender process\n");

    pn_messenger_t *messenger = pn_messenger(NULL);
    pn_messenger_set_outgoing_window(messenger, 1);
    pn_messenger_start(messenger);

    while(true) {
        sendMessage(messenger);
        printf("Sent message\n");
        sleep(1);
    }

    // release messenger resources
    pn_messenger_stop(messenger);
    pn_messenger_free(messenger);

    return 0;
}
