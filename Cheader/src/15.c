/* 15.c - pure C syscalls and minimal stubs */
/* No typedefs, no macros, no stdlib */
/* Linux x86_64 ABI */

/* Helper syscall wrapper for openat (used in o) */
int o(const char *path, int mode) {
    int flags = 0;
    if (mode == 0) flags = 0;         /* O_RDONLY */
    else if (mode == 1) flags = 577;  /* O_WRONLY | O_CREAT | O_TRUNC */
    else if (mode == 2) flags = 578;  /* O_RDWR | O_CREAT */

    long ret;
    int dirfd = -100;   /* AT_FDCWD */
    int perm = 420;     /* 0644 octal */

    asm volatile (
        "movq $257, %%rax\n\t"
        "movq %1, %%rdi\n\t"
        "movq %2, %%rsi\n\t"
        "movq %3, %%rdx\n\t"
        "movq %4, %%r10\n\t"
        "syscall\n\t"
        "movq %%rax, %0\n\t"
        : "=r"(ret)
        : "r"((long)dirfd), "r"(path), "r"((long)flags), "r"((long)perm)
        : "rax", "rdi", "rsi", "rdx", "r10", "rcx", "r11", "memory"
    );
    return (int)ret;
}

/* close */
int c(void *file) {
    int fd = (int)(long)file;
    long ret;
    asm volatile (
        "movq $3, %%rax\n\t"
        "movq %1, %%rdi\n\t"
        "syscall\n\t"
        "movq %%rax, %0\n\t"
        : "=r"(ret)
        : "r"((long)fd)
        : "rax", "rdi", "rcx", "r11", "memory"
    );
    return (int)ret;
}

/* read */
int fr(void *file, void *buf, int size) {
    int fd = (int)(long)file;
    long ret;
    asm volatile (
        "movq $0, %%rax\n\t"
        "movq %1, %%rdi\n\t"
        "movq %2, %%rsi\n\t"
        "movq %3, %%rdx\n\t"
        "syscall\n\t"
        "movq %%rax, %0\n\t"
        : "=r"(ret)
        : "r"((long)fd), "r"(buf), "r"((long)size)
        : "rax", "rdi", "rsi", "rdx", "rcx", "r11", "memory"
    );
    return (int)ret;
}

/* write */
int fw(void *file, const void *buf, int size) {
    int fd = (int)(long)file;
    long ret;
    asm volatile (
        "movq $1, %%rax\n\t"
        "movq %1, %%rdi\n\t"
        "movq %2, %%rsi\n\t"
        "movq %3, %%rdx\n\t"
        "syscall\n\t"
        "movq %%rax, %0\n\t"
        : "=r"(ret)
        : "r"((long)fd), "r"(buf), "r"((long)size)
        : "rax", "rdi", "rsi", "rdx", "rcx", "r11", "memory"
    );
    return (int)ret;
}

/* fgetc - read 1 char */
int gchr(void *file) {
    unsigned char ch;
    int ret = fr(file, &ch, 1);
    if (ret <= 0) return -1;
    return (int)ch;
}

/* getc alias (renamed to gct) */
int gct(void *file) {
    return gchr(file);
}

/* getchar - read 1 char from stdin (fd=0) */
int gc(void) {
    unsigned char ch;
    long ret;
    asm volatile (
        "movq $0, %%rax\n\t"
        "movq $0, %%rdi\n\t"
        "movq %1, %%rsi\n\t"
        "movq $1, %%rdx\n\t"
        "syscall\n\t"
        "movq %%rax, %0\n\t"
        : "=r"(ret)
        : "r"(&ch)
        : "rax", "rdi", "rsi", "rdx", "rcx", "r11", "memory"
    );
    if (ret <= 0) return -1;
    return (int)ch;
}

/* fputc */
int fpc(void *file, char ch) {
    return fw(file, &ch, 1);
}

/* putc to stdout (fd=1) */
int pc(char ch) {
    long ret;
    asm volatile (
        "movq $1, %%rax\n\t"
        "movq $1, %%rdi\n\t"
        "movq %1, %%rsi\n\t"
        "movq $1, %%rdx\n\t"
        "syscall\n\t"
        "movq %%rax, %0\n\t"
        : "=r"(ret)
        : "r"(&ch)
        : "rax", "rdi", "rsi", "rdx", "rcx", "r11", "memory"
    );
    return (int)ret;
}

/* putchar - alias for putc */
int pchr(char ch) {
    return pc(ch);
}

/* fputs */
int fps(void *file, const char *str) {
    int i = 0;
    int res = 0;
    while (str[i] != 0) {
        int r = fpc(file, str[i]);
        if (r <= 0) return r;
        res += r;
        i++;
    }
    return res;
}

/* puts to stdout with newline */
int ps(const char *str) {
    int r = fps((void *)(long)1, str);
    if (r < 0) return r;
    int w = pc('\n');
    if (w < 0) return w;
    return r + w;
}

/* feof: returns 1 if last_read_result == 0 (EOF) else 0 */
int e(int last_read_result) {
    return last_read_result == 0 ? 1 : 0;
}

/* ferror: returns -1 if syscall_result < 0 else 0 */
int err(int syscall_result) {
    return syscall_result < 0 ? -1 : 0;
}

/* fseek - uses sys_lseek (8) */
int fsk(void *file, int offset, int whence) {
    int fd = (int)(long)file;
    long ret;
    asm volatile (
        "movq $8, %%rax\n\t"
        "movq %1, %%rdi\n\t"
        "movq %2, %%rsi\n\t"
        "movq %3, %%rdx\n\t"
        "syscall\n\t"
        "movq %%rax, %0\n\t"
        : "=r"(ret)
        : "r"((long)fd), "r"((long)offset), "r"((long)whence)
        : "rax", "rdi", "rsi", "rdx", "rcx", "r11", "memory"
    );
    return (int)ret;
}

/* ftell - get current offset with sys_lseek offset=0, whence=1(SEEK_CUR) */
int ft(void *file) {
    return fsk(file, 0, 1);
}

/* rewind - seek to 0 with SEEK_SET(0) */
void rw(void *file) {
    fsk(file, 0, 0);
}

/* remove - unlink syscall (87) */
int r(const char *path) {
    long ret;
    asm volatile (
        "movq $87, %%rax\n\t"
        "movq %1, %%rdi\n\t"
        "syscall\n\t"
        "movq %%rax, %0\n\t"
        : "=r"(ret)
        : "r"(path)
        : "rax", "rdi", "rcx", "r11", "memory"
    );
    return (int)ret;
}

/* rename - rename syscall (82) */
int rn(const char *oldname, const char *newname) {
    long ret;
    asm volatile (
        "movq $82, %%rax\n\t"
        "movq %1, %%rdi\n\t"
        "movq %2, %%rsi\n\t"
        "syscall\n\t"
        "movq %%rax, %0\n\t"
        : "=r"(ret)
        : "r"(oldname), "r"(newname)
        : "rax", "rdi", "rsi", "rcx", "r11", "memory"
    );
    return (int)ret;
}

/* Stubs for varargs functions (fprintf, printf, fscanf, snprintf, sprintf, sscanf) */
/* Just returns -1 because no formatting without stdlib */

int fp(void *file, const char *fmt, ...) {
    (void)file; (void)fmt;
    return -1;
}

int pf(const char *fmt, ...) {
    (void)fmt;
    return -1;
}

int fs(void *file, const char *fmt, ...) {
    (void)file; (void)fmt;
    return -1;
}

int snp(char *buf, int size, const char *fmt, ...) {
    (void)buf; (void)size; (void)fmt;
    return -1;
}

int sp(char *buf, const char *fmt, ...) {
    (void)buf; (void)fmt;
    return -1;
}

int ssf(const char *buf, const char *fmt, ...) {
    (void)buf; (void)fmt;
    return -1;
}

/* fgets: read up to size-1 chars or until newline */
/* simple version: reads bytes one by one */

int getl(void *file, char *buf, int size) {
    if (size <= 0) return -1;
    int i = 0;
    for (; i < size - 1; i++) {
        int c = gchr(file);
        if (c < 0) break;
        buf[i] = (char)c;
        if (c == '\n') {
            i++;
            break;
        }
    }
    buf[i] = 0;
    return i;
}

