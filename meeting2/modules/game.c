#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include "room.h"

#define BUF_SIZE 256

char *quit_cmd = "quit";
char *north_cmd = "north";
char *south_cmd = "south";
char *east_cmd = "east";
char *west_cmd = "west";

room_t *handleCommand(char * command, room_t *current_room) {
    // `man 3 strncasecmp` for info
    if (! strncasecmp(quit_cmd, command, strlen(quit_cmd))) {
        printf("Bye!");
        return NULL;
    } else if (! strncasecmp(north_cmd, command, strlen(north_cmd))) {
        printf("You walk north\n");
        print_room(current_room->north);
        return current_room->north;
    } else if (! strncasecmp(south_cmd, command, strlen(south_cmd))) {
        printf("You walk south\n");
        print_room(current_room->south);
        return current_room->south;
    } else if (! strncasecmp(east_cmd, command, strlen(east_cmd))) {
        printf("You walk east\n");
        print_room(current_room->east);
        return current_room->east;
    } else if (! strncasecmp(west_cmd, command, strlen(west_cmd))) {
        printf("You walk west\n");
        print_room(current_room->west);
        return current_room->west;
    } else {
        printf("Unrecognized command.\n");
        return current_room;
    }
}

char * start_name = "The origin of all things";
char * start_description = "The binary is null and void, and darkness is on the face of the bytes.";
char * second_name = "The gateway";
char * second_description = "An archway into reality, filled with possibilities.";
char * world_name = "The mundane world";
char * world_description = "You've returned to our world. At least now you know some C.";

int main() {
    // stack-allocate a character array
    char input[BUF_SIZE];
    room_t *first = new_room(start_name, start_description);
    room_t *second = new_room(second_name, second_description);
    room_t *third = new_room(world_name, world_description);
    first->north = second;
    second->south = first;
    first->east = third;
    third->west = first;

    room_t *current_room = first;
    print_room(current_room);
    // `man 3 fgets` and `man 3 stdin` for info
    while (fgets(input, BUF_SIZE, stdin) != NULL) {
        current_room = handleCommand(input, current_room);
        if (current_room == NULL) {
            break;
        }
    }
    free(first);
    free(second);
    free(third);
}
