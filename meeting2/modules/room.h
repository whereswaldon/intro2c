#ifndef room_h_INCLUDED
#define room_h_INCLUDED

// define a type `room_t` that is equivalent to `struct room`
typedef struct room room_t;

struct room {
    char *name;
    char *description;
    // these room pointer fields represent exits.
    // if they are NULL, there is not an exit in that direction.
    room_t *north;
    room_t *south;
    room_t *east;
    room_t *west;
};

// allocates a new room on the heap, sets its name and description,
// sets all of the exits to NULL, and returns a pointer to it.
room_t *new_room(char *name, char *description);

// pretty-prints a description of the room including:
    // the name
    // the description
    // the list of visible exits
void print_room(room_t *room);

#endif // room_h_INCLUDED

