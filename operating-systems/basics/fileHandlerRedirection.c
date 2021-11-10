// Wasim Adetunji

#include  <stdio.h> 

#include <fcntl.h> 

#include <unistd.h> 
int main(int argc, char *argv[]) 
{ 
   
    
    if(argc < 2){printf("Error: No filename passed! \n"); return -1;}
    // first argument is the program name so we need a minimum of two arguments
    
	int fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IROTH  | S_IRGRP );  
	
	// argv[1] accesses program name specified by user;
	// first set of flags specify that 
		// file will be opened with read/write permission; 
		// that file will be created if it does not exist;
		// and that the file will be truncated if it does exist.
    // second set of flags specify linux owner/group/other permissions
    
    dup2(fd, 1); 
          
    printf("Hello Wasim I’m being redirected to a file instead of the I/O display device! \n"); 
        
    return 0; 
} 
 
