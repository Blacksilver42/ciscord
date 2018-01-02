#ifndef __CISCORD_TYPEDEFS_H__
#define __CISCORD_TYPEDEFS_H__



///////////////////////////////////////////////// STRUCTS



// holds the key and some other data.
typedef struct {
	char * key;
	CURL *curl;
	CURLcode lastcode;
	char * botname;
	char * user_agent;
	char * auth_header;
} ciscord_t;


// embedded thing
typedef struct {
	struct {
		int r,g,b;
	} color;
	char * content;
} embed_t;


// send context
typedef struct {
	guild_t * guild;
	chan_t * chan;
} ctx_t;


// User
typedef struct {
	char * id;
	char * nick;
	char * name;
	int tag;
	bool isbot;
} user_t;


// recieved message
typedef struct {
	char * raw_message;
	ctx_t * ctx;
	user_t * usr;
} recv_t;



typedef void (*listen_f)(const recv_t * recv); // function pointer like ``void f(const recv_t * recv)''


#endif /* ifndef __CISCORD_TYPEDEFS_H__*/
