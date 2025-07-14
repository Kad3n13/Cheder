/* 13.h - pure C declarations for custom stdio-like functions */

/* fclose */
int c(void *file);

/* feof */
int e(int last_read_result);

/* ferror */
int err(int syscall_result);

/* fgetc */
int gchr(void *file);

/* getchar (reads from stdin) */
int gc(void);

/* fgets */
int getl(void *file, char *buf, int size);

/* fopen */
void *o(const char *path, int mode);

/* fprintf (stub) */
int fp(void *file, const char *fmt, ...);

/* fputc */
int fpc(void *file, char ch);

/* putc */
int pc(char ch);

/* fputs */
int fps(void *file, const char *str);

/* fread */
int fr(void *file, void *buf, int size);

/* fscanf (stub) */
int fs(void *file, const char *fmt, ...);

/* fseek */
int fsk(void *file, int offset, int whence);

/* ftell */
int ft(void *file);

/* fwrite */
int fw(void *file, const void *buf, int size);

/* getc (alias for fgetc) */
int gct(void *file);  /* renamed to avoid conflict, alias for gchr */

/* printf (stub) */
int pf(const char *fmt, ...);

/* putchar */
int pchr(char ch);

/* puts */
int ps(const char *str);

/* remove */
int r(const char *path);

/* rename */
int rn(const char *oldname, const char *newname);

/* rewind */
void rw(void *file);

/* snprintf (stub) */
int snp(char *buf, int size, const char *fmt, ...);

/* sprintf (stub) */
int sp(char *buf, const char *fmt, ...);

/* sscanf (stub) */
int ssf(const char *buf, const char *fmt, ...);

