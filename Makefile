include config.mk 

LIBCORTEX_OBJECTS = $(patsubst %.c,%.o, $(wildcard src/*.c))
LIBCORTEX_OUT = libcortex.a
all: options ${LIBCORTEX_OUT} 

options:
	@echo libcortex build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"


%.o: %.c
	@echo -n Compiling $< into $@...
	@${CC} ${CFLAGS} -c $< -o $@
	@echo done.

${LIBCORTEX_OUT}: ${LIBCORTEX_OBJECTS}
	@echo -n Building ${LIBCORTEX_OUT} out of $^...
	@${AR} rcs ${LIBCORTEX_OUT}  $^
	@echo done

clean:
	@echo -n Cleaning...
	@rm -f ${LIBCORTEX_OUT} ${LIBCORTEX_OBJECTS}
	@echo done.
