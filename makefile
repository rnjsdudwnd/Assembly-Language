TARGET1 =test_static
  2 TARGET2 =test_dynamic
  3 OBJS = bit8.o bit32.o
  4 CC = gcc
  5 CFLAGS = -Wall -O2
  6 CFLAGS += -I./include
  7 
  8 all: $(TARGET1) $(TARGET2)
  9 
 10 ##################### STATIC ############################
 11 $(TARGET1): $(OBJS) libbit.a
 12         $(CC) -o $(TARGET1) main.c $(CFLAGS) -L./lib -lbit -static
 13         ./$(TARGET1)
 14 bit8.o: bit8.c
 15         $(CC) -c -o bit8.o $^ $(CFLAGS)
 16 bit32.o: bit32.c
 17         $(CC) -c -o bit32.o $^ $(CFLAGS)
 18 libbit.a: bit8.o bit32.o
 19         ar rscv libbit.a bit8.o bit32.o
 20         mkdir lib
 21         mv libbit.a lib/
 22 
 23 
 24 
 25 #################### DYNAMIC ###########################
 26 $(TARGET2): $(OBJS) libbit.so.0.0.0
 27                 $(CC) -o $(TARGET2) main.c $(CFLAGS) -L./lib -lbit
 28                 ./$(TARGET2)
 29 bit8.o:bit8.c
 30                 $(CC) -c -o bit8.o bit8.c -fPIC
 31 bit32.o:bit32.c
 32                 $(CC) -c -o bit32.o bit32.c -fPIC
 33 libbit.so.0.0.0: bit8.o bit32.o
 34                 $(CC) -shared -Wl,-soname,libbit.so.0 -o libbit.so.0.0.0 bit8.o bit32.o
 35                 mv libbit.so.0.0.0 lib
 36                 cd lib && ln -s libbit.so.0.0.0 libbit.so
 37                 cd lib && ln -s libbit.so.0.0.0 libbit.so.0
 38                 cd lib && pwd >> /etc/ld.so.conf
 39                 ldconfig                
 40 
 41 clean:
 42         rm -rf lib
 43         sed -i '/test/d' /etc/ld.so.conf
 44         $(RM) $(TARGET1) $(OBJS)
 45         $(RM) $(TARGET2) $(OBJS)
~                                                                                                            
"makefile" 45L, 1136C                                           
