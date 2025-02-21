// #include <xinu.h>
// #include <stdio.h>


// shellcmd xsh_hello(int nargs, char *args[])
// {
//     printf("Hello World of XINUUU \n");
// }


















#include <xinu.h>
#include <stdio.h>


void prod2(sid32, sid32), cons2(sid32, sid32);
void prod(sid32, sid32 , pid32), cons(sid32, sid32);


int32 n = 0; /* Variable n has initial value zero */


// shellcmd xsh_hello(int nargs, char *args[])
// {
//     sid32 produced, consumed;
//     consumed = semcreate(0);
//     produced = semcreate(1);


//     resume( create(cons2, 1024, 20, "cons", 2, consumed, produced) );
//     resume( create(prod2, 1024, 20, "prod", 2, consumed, produced) );


//     //printf("Hello World\n");
//     return 0;
// }

// void prod2 ( sid32 consumed, sid32 produced )
// {
//     int32 i;
//     for( i=1 ; i<=3 ; i++ )
//     {
//         wait(consumed);
//         n++;
//         signal(produced);
//     }
// }

// void cons2( sid32 consumed, sid32 produced )
// {
//     int32 i;
//     for( i=1 ; i<=3 ; i++ )
//     {
//         wait(produced);
//         printf("n is %d \n", n);
//         signal(consumed);
//     }
// }



shellcmd xsh_hello(int nargs, char *args[]){ 
    sid32 p, c; 
    c = semcreate(0); 
    p = semcreate(1); 
    pid32 cp = create(cons, 700, 22, "cons", 2, p, c) ;
    printf("pid = %d\n", cp);
    resume( create(prod, 500, 21, "prod", 3, p, c , cp) );
    resume( cp); 
} 
void prod(sid32 p, sid32 c , pid32 pid) { 
    wait(p);
    printf("in prod :\n");
    send(pid, 'P');
    signal(c);
} 

void cons(sid32 p, sid32 c) {
    wait(c);
    char msg = receive();
    printf("in cons : received message '%c'\n", msg);
    signal(p);
}



/*


    // sender receiver .. 

    // with global declaration;..

    





*/
