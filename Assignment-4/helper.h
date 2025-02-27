#ifndef HELPER_H
#define HELPER_H

// Ref: file sharing https://stackoverflow.com/questions/11952898/c-send-and-receive-file
#define KEY "BA67C85F805DB78A9E01812383348483"
#include <unistd.h> 
#include <iostream>
#include <sys/socket.h> 
#include <cstring>
#include <stdlib.h> 
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/time.h>
#include <cstdlib>
#include <pthread.h>   
#include <iterator> 
#include <map> 
#include <openssl/evp.h>
#include <time.h>
#include <list> 
#include <iterator> 
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <sys/xattr.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/aes.h>
#include <openssl/rsa.h>
#include <openssl/crypto.h>
#include <openssl/x509.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <stdlib.h>
#include <errno.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include <netdb.h>
#include <memory.h>

#define KDC_PORT 5555
#define CHAT_PORT 6666
#define FILE_PORT 7777
#define BUFSIZE 5024
#define CONNECTIONS 6

// Server functions
void * KDC_Server(void * argv);
void * ConnectionHandler(void * argv);
int do_enc(const unsigned char * input, std::string username, int encdec, unsigned char * out);
int do_dec(const unsigned char * input, std::string username, int encdec, unsigned char * out);
void getKeyIv(std::string username, unsigned char * key, unsigned char * iv);
void do_crypt(const unsigned char * input, std::string username, int encdec, unsigned char * out);

// Client functions
void * SendMessage(void * argv);

// Helper.cpp
// void String2Char(string input, char * output);
int checkFilePermissions(const char * filename, std::string user);
void encdec(const unsigned char * input, std::string username, int encdec, unsigned char * out);
void getPass(char *prompt, int show_asterisk, char * password);
int checkUsername(char * username);
void init_diffi(std::string user, std::string &gobar);

#endif