
#include <stdio.h>
#include <stdlib.h>

unsigned int test;

int test_shnadd(void);
int test_clz(void);

int main(int argc, char *argv[])
{  
  int failures=0;

  failures += test_shnadd();
  //failures += test_clz();

  if(failures == 0){
    return EXIT_SUCCESS;
  }
  else {
    return EXIT_FAILURE;
  }
}

/*
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
*/

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
