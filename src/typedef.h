#ifndef __CISCORD_TYPEDEFS_H__
#define __CISCORD_TYPEDEFS_H__


///////////////////////////////////////////////// SHORTHANDS



typedef (const char *) msg_t;
typedef void (*listen_f)(const recv_t * recv); // function pointer like ``void f(char * msg)''



///////////////////////////////////////////////// STRUCTS



// holds the key and some other data.
typedef struct {
	char * key;
} ciscord_t;


// guild (server)
typedef struct {
	char * name;
	char * id;
} guild_t;


// channel
typedef struct {
	char * name;
	char * id;
} chan_t;


// embedded thing
typedef struct {
	struct {
		int r,g,b;
	} color;
	char * content;
}


// send context
typedef struct {
	guild_t guild;
	chan_t chan;
} ctx_t;


// User
typedef struct {
	char * id;
	char * nick;
	char * name;
	bool isbot;
} user_t;


// recieved message
typedef struct {
	char * raw_message;
	ctx_t * ctx;
	user_t * usr;
} recv_t;





#endif /* ifndef __CISCORD_TYPEDEFS_H__*/
