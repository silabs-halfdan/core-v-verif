
#include <stdio.h>
#include <stdlib.h>

unsigned int test;

int test_shnadd(void);
int test_clz(void);
int test_ctz(void);
int test_cpop(void);
int test_rol(void);
int test_ror(void);
int test_rori(void);
int test_max(void);
int test_min(void);
int test_maxu(void);
int test_minu(void);
int test_or_c(void);
int test_orn(void);
int test_rev8(void);
int test_bclr(void);

int main(int argc, char *argv[])
{  
  int failures=0;

  failures += test_shnadd();
  failures += test_clz();
  failures += test_ctz();
  failures += test_cpop();
  failures += test_rol();
  failures += test_ror();
  failures += test_rori();
  failures += test_max();
  failures += test_min();
  failures += test_maxu();
  failures += test_minu();
  failures += test_or_c();
  failures += test_orn();
  failures += test_rev8();

  if(failures == 0){
    return EXIT_SUCCESS;
  }
  else {
    return EXIT_FAILURE;
  }
}

int test_clz(void){
  
  int failures = 0;
  
  // Store 8 in t3
  __asm__ volatile("addi t3, zero, 8");

  // Store CLZ result in t5
  __asm__ volatile("clz t5, t3");

  // Store t5 to test
  __asm__ volatile("sw t5, test, t0");

  if (test != 28) {
    printf("ERROR, CLZ result not as expected\n");
    failures++;
  }
  
  return failures;
}

int test_ctz(void){
 int failures = 0;

  __asm__ volatile("addi t4, zero, 32"); // Store 32 in t4
  __asm__ volatile("ctz t5, t4");        // Store CLZ result in t5
  __asm__ volatile("sw t5, test, t0");   // Store t5 to test

  if (test != 5 ) {
    printf("ERROR, CTZ result not as expected\n");
    failures++;
  }

  return failures;
}

int test_cpop(void){
 int failures = 0;

  __asm__ volatile("addi t3, zero, 5"); // Store 5 in t3
  __asm__ volatile("cpop t5, t3");      // Store cpop result in t5
  __asm__ volatile("sw t5, test, t0");  // Store t5 to test

  if (test != 2 ) {
    printf("ERROR, CPOP result not as expected\n");
    failures++;
  }

  return failures;
}

int test_max(void){
 int failures = 0;

  __asm__ volatile("addi t3, zero, -7"); // Store 5 in t3
  __asm__ volatile("addi t4, zero, 1"); // Store 1 in t4
  __asm__ volatile("max t5, t3, t4");   // Find max
  __asm__ volatile("sw t5, test, t0");  // Store t5 to test

  if (test != 1 ) {
    printf("ERROR, MAX result not as expected\n");
    failures++;
  }

  return failures;
}

int test_min(void){
 int failures = 0;

  __asm__ volatile("addi t3, zero, -7"); // Store 5 in t3
  __asm__ volatile("addi t4, zero, 1"); // Store 1 in t4
  __asm__ volatile("min t5, t3, t4");   // Find min
  __asm__ volatile("sw t5, test, t0");  // Store t5 to test

  if (test != -7 ) {
    printf("ERROR, MIN result not as expected\n");
    failures++;
  }

  return failures;
}

int test_maxu(void){
 int failures = 0;

  __asm__ volatile("addi t3, zero, -7"); // Store 5 in t3
  __asm__ volatile("addi t4, zero, 1"); // Store 1 in t4
  __asm__ volatile("maxu t5, t3, t4");   // Find unsigned max
  __asm__ volatile("sw t5, test, t0");  // Store t5 to test

  if (test != -7 ) {
    printf("ERROR, MAXU result not as expected\n");
    failures++;
  }

  return failures;
}

int test_minu(void){
 int failures = 0;

  __asm__ volatile("addi t3, zero, -7"); // Store 5 in t3
  __asm__ volatile("addi t4, zero, 1"); // Store 1 in t4
  __asm__ volatile("minu t5, t3, t4");   // Find unsigned min
  __asm__ volatile("sw t5, test, t0");  // Store t5 to test

  if (test != 1 ) {
    printf("ERROR, MINU result not as expected\n");
    failures++;
  }

  return failures;
}

int test_or_c(void){
 int failures = 0;

  __asm__ volatile("addi t3, zero, 1"); // Store 1 in t3
  __asm__ volatile("orc.b t5, t3");   // Run orc.b
  __asm__ volatile("sw t5, test, t0");  // Store t5 to test

  if (test != 0xFF ) {
    printf("ERROR, ORC.B result not as expected: %x\n", test);
    failures++;
  }

  return failures;
}


int test_orn(void){
 int failures = 0;

  __asm__ volatile("addi t3, zero, 10"); // Store 1 in t3
  __asm__ volatile("addi t4, zero, -4"); // Store 1 in t4
  __asm__ volatile("orn t5, t3, t4");   // ORN
  __asm__ volatile("sw t5, test, t0");  // Store t5 to test

  if (test != 0xB ) {
    printf("ERROR, ORN result not as expected: %x\n", test);
    failures++;
  }

  return failures;
}

int test_rev8(void){
 int failures = 0;

  __asm__ volatile("addi t3, zero, 15"); // Store 1 in t3
  __asm__ volatile("rev8 t5, t3");       //Reverse bytes
  __asm__ volatile("sw t5, test, t0");   // Store t5 to test

  if (test != 0x0F000000 ) {
    printf("ERROR, REV8 result not as expected: %x\n", test);
    failures++;
  }

  return failures;
}

int test_rol(void){
 int failures = 0;

  __asm__ volatile("addi t3, zero, 7"); // Store 5 in t3
  __asm__ volatile("addi t4, zero, 1"); // Store 1 in t4
  __asm__ volatile("rol t5, t3, t4");   // Rotate Left
  __asm__ volatile("sw t5, test, t0");  // Store t5 to test

  if (test != 14 ) {
    printf("ERROR, ROL result not as expected\n");
    failures++;
  }

  return failures;
}


int test_ror(void){
 int failures = 0;

  __asm__ volatile("addi t3, zero, 10"); // Store 5 in t3
  __asm__ volatile("addi t4, zero, 1"); // Store 1 in t4
  __asm__ volatile("ror t5, t3, t4");      //
  __asm__ volatile("sw t5, test, t0");  // Store t5 to test

  if (test != 5 ) {
    printf("ERROR, ROR result not as expected\n");
    failures++;
  }

  return failures;
}


int test_rori(void){
 int failures = 0;

  __asm__ volatile("addi t3, zero, 10"); // Store 5 in t3
  __asm__ volatile("rori t5, t3, 1");    // Rotate right
  __asm__ volatile("sw t5, test, t0");  // Store t5 to test

  if (test != 5 ) {
    printf("ERROR, RORI result not as expected %x\n", test);
    failures++;
  }

  return failures;
}


int test_shnadd(void){
  
  int failures = 0;

  
  printf("Testing SHnADD\n");

  // Store 5 and 7 in t3, t4
  __asm__ volatile("addi t3, zero, 5");
  __asm__ volatile("addi t4, zero, 7");
  
  // t5 = (t4 << 1) + t3
  __asm__ volatile("sh1add t5, t4, t3");
  
  // Store t5 to test
  __asm__ volatile("sw t5, test, t0");
    
  if(test != (7<<1) + 5){
    printf("ERROR, SH1ADD result not as expected\n");
    failures++;
  }
  else {
    printf("INFO, SH1ADD result as expected\n");
  }
  
  printf("test: 0x%x\n", test);

  // Store 5 and 7 in t3, t4
  __asm__ volatile("addi t3, zero, 5");
  __asm__ volatile("addi t4, zero, 7");
  // t5 = (t4 << 2) + t3
  __asm__ volatile("sh2add t5, t4, t3");
  // Store t5 to test
  __asm__ volatile("sw t5, test, t0");
    
  if(test != (7<<2) + 5){
    printf("ERROR, SH2ADD result not as expected\n");
    failures++;
  }
  else {
    printf("INFO, SH2ADD result as expected\n");
  }
  printf("test: 0x%x\n", test);
    
  // Store 5 and 7 in t3, t4
  __asm__ volatile("addi t3, zero, 5");
  __asm__ volatile("addi t4, zero, 7");
  // t5 = (t4 << 3) + t3
  __asm__ volatile("sh3add t5, t4, t3");
  // Store t5 to test
  __asm__ volatile("sw t5, test, t0");
    
  if(test != (7<<3) + 5){
    printf("ERROR, SH3ADD result not as expected\n");
    failures++;
  }
  else {
    printf("INFO, SH3ADD result as expected\n");
  }
  printf("test: 0x%x\n", test);


  return failures;
}
