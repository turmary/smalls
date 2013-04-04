#include <stdio.h>

int main(int argc, char* argv[]) {
char *to, *from;
char s_to[0x200];
char s_from[] = "Hello World, My name is tary. ok, you will go there";
int count = sizeof s_from;
register int n = (count+7)/8; 

to = s_to;from = s_from;

switch (count % 8) { 
case 0: do { *to++ = *from++; 
case 7: *to++ = *from++; 
case 6: *to++ = *from++; 
case 5: *to++ = *from++; 
case 4: *to++ = *from++; 
case 3: *to++ = *from++; 
case 2: *to++ = *from++; 
case 1: *to++ = *from++; 
} while(--n>0);
}
printf("%s\n", s_to); 
return 0;
}
