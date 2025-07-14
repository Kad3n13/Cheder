#include "13.h"

/* 
 * Simple helper to print a string and newline
 * Uses your custom puts-like function ps()
 */
static void print_line(const char *msg) {
    ps(msg);
    ps("\n");
}

/* Simple helper to print single char with label */
static void print_char_label(const char *label, char ch) {
    ps(label);
    pchr(ch);
    ps("\n");
}

/* Simple helper to print int as decimal */
static void print_int_label(const char *label, int n) {
    char buf[16];
    int i = 0, temp, start;
    if (n == 0) {
        ps(label);
        ps("0\n");
        return;
    }
    if (n < 0) {
        ps(label);
        pchr('-');
        n = -n;
    } else {
        ps(label);
    }
    // convert number to string in reverse order
    while (n > 0 && i < 15) {
        buf[i++] = (char)((n % 10) + '0');
        n /= 10;
    }
    // print digits in correct order
    for (start = i - 1; start >= 0; start--) {
        pchr(buf[start]);
    }
    pchr('\n');
}

int main() {
    void *file;
    int res, eof_check, err_check;
    char buffer[256];
    char line[128];
    char fmtbuf[128];
    char sscanfbuf[64];
    int scanned_int = 0;
    int ch;

    print_line("[+] Testing fopen (o): open file for write");
    file = o("testfile.txt", 1); /* mode 1 = write */
    if (!file) {
        print_line("[-] fopen failed");
        return 1;
    }
    print_line("[+] fopen success");

    print_line("[+] Testing fprintf stub (fp):");
    fp(file, "Hello %s %d\n", "world", 123);

    print_line("[+] Testing fputc (fpc): write 'X'");
    fpc(file, 'X');

    print_line("[+] Testing putc (pc): write 'Y' to stdout");
    pc('Y');
    pchr('\n');

    print_line("[+] Testing putchar (pchr): write 'Z' to stdout");
    pchr('Z');
    pchr('\n');

    print_line("[+] Testing fputs (fps): write string to file");
    fps(file, "This is a test line.\n");

    print_line("[+] Testing fwrite (fw): write raw data");
    fw(file, "RAWBLOCK", 8);

    print_line("[+] Testing fclose (c): close file");
    c(file);

    print_line("[+] Testing fopen (o): open file for read");
    file = o("testfile.txt", 0); /* mode 0 = read */
    if (!file) {
        print_line("[-] fopen for read failed");
        return 1;
    }
    print_line("[+] fopen success");

    print_line("[+] Testing fread (fr): read 255 bytes");
    res = fr(file, buffer, 255);
    if (res < 0) {
        print_line("[-] fread failed");
        c(file);
        return 1;
    }
    buffer[res] = 0;
    print_line("[+] fread success, data:");
    ps(buffer);
    pchr('\n');

    print_line("[+] Testing fseek (fsk): rewind to start");
    fsk(file, 0, 0);

    print_line("[+] Testing ftell (ft): get current position");
    res = ft(file);
    print_int_label("Position: ", res);

    print_line("[+] Testing fgets (getl): read one line");
    getl(file, line, 127);
    ps(line);
    pchr('\n');

    print_line("[+] Testing fgetc (gchr): read one char");
    ch = gchr(file);
    print_char_label("Char: ", (char)ch);

    print_line("[+] Testing getc (gct): alias for fgetc");
    ch = gct(file);
    print_char_label("Char: ", (char)ch);

    print_line("[+] Testing getchar (gc): type a char");
    ch = gc();
    print_char_label("You typed: ", (char)ch);

    print_line("[+] Testing feof (e) and ferror (err):");
    eof_check = e(res);
    err_check = err(res);
    ps(eof_check ? "EOF reached\n" : "Not EOF\n");
    ps(err_check ? "Error detected\n" : "No error\n");

    print_line("[+] Testing rewind (rw)");
    rw(file);

    print_line("[+] Testing fscanf stub (fs): read a word");
    fs(file, "%s", sscanfbuf);
    ps("Read with fscanf stub: ");
    ps(sscanfbuf);
    pchr('\n');

    print_line("[+] Testing fclose (c) again");
    c(file);

    print_line("[+] Testing remove (r): delete file");
    res = r("testfile.txt");
    ps(res == 0 ? "File removed\n" : "Remove failed\n");

    print_line("[+] Testing rename (rn): create and rename");
    file = o("oldname.txt", 1);
    fps(file, "Rename me\n");
    c(file);
    res = rn("oldname.txt", "newname.txt");
    ps(res == 0 ? "File renamed\n" : "Rename failed\n");
    r("newname.txt");

    print_line("[+] Testing snprintf (snp) stub");
    snp(fmtbuf, sizeof(fmtbuf), "Number: %d, String: %s", 42, "test");
    ps("snprintf result: ");
    ps(fmtbuf);
    pchr('\n');

    print_line("[+] Testing sprintf (sp) stub");
    sp(fmtbuf, "Hello %s!", "world");
    ps("sprintf result: ");
    ps(fmtbuf);
    pchr('\n');

    print_line("[+] Testing sscanf (ssf) stub");
    ssf("42", "%d", &scanned_int);
    print_int_label("sscanf read int: ", scanned_int);

    print_line("[+] All tests done.");

    return 0;
}
