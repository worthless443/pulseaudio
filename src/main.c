#include<pulse/error.h>
#include<pulse/proplist.h>
#include<pulsecore/iochannel.h>
#include<pulse/mainloop.h>
#include<pulse/context.h>
#include<pulse/internal.h>
#include<pulsecore/tagstruct.h>

#include<stdio.h>
#include<assert.h>

// basically examples

#define nigger__ 0

#define F(a) ({ \
		int b = a; \
		while((b)<10) { \
		b+=1; }\
		b & 0xff; \
		})

pa_context *__get_context(const char *file) {
	pa_mainloop_api *mapi = pa_mainloop_get_api(pa_mainloop_new()); // = malloc(sizeof(pa_mainloop_api));
	FILE *fd = fopen(file, "w");
	pa_iochannel *io_ch = pa_iochannel_new(mapi,fd->_fileno,fd->_fileno);
	pa_proplist *plist = pa_proplist_new();
	return  pa_context_new_with_proplist(mapi, "nigger", plist);
}

void explore_ctx(pa_context *pa_ctx) {
	printf("\n%d\n", pa_ctx->version);
}

int main() {
	pa_context *pa_ctx  = NULL, *pa_ctx_ref = NULL;
	pa_ctx = __get_context("nigger.txt") ;
	pa_ctx_ref = pa_context_ref(pa_ctx);
	assert(pa_ctx!=NULL);
	assert(pa_ctx_ref!=NULL);
	pa_tagstruct *tagstruct = NULL ;
	tagstruct = pa_tagstruct_new_fixed((uint8_t*)pa_ctx, sizeof(*pa_ctx));
	
}

