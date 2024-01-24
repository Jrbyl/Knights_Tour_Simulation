

all: beltzhoover_jon-assignment0

beltzhoover_jon-assignment0: beltzhoover_jon-assignment0.c
		gcc beltzhoover_jon-assignment0.c -o beltzhoover_jon-assignment0

clean:
		rm -f beltzhoover_jon-assignment0 *~ core