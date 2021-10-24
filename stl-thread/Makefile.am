
bin_PROGRAMS = prime-thread prime-no-thread
LIBS = -lpthread

prime_thread_SOURCES = prime-thread.cc
prime_thread_CXXFLAGS = -DUSING_THREAD=1

prime_no_thread_SOURCES = prime-thread.cc
prime_no_thread_CXXFLAGS = -DUSING_THREAD=0

# UGLY approach
# prime_no_thread_LINK = $(CXXLD) -o $@
# prime_no_thread_LDADD = prime_no_threadX.o
#prime_no_threadX.o: prime-thread.cc
#	$(COMPILE.cc) -DUSING_THREAD=0 $(OUTPUT_OPTION) $<
