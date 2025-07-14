| Custom Name | Standard Function  | Description                   |
| ----------- | ------------------ | ----------------------------- |
| c()         | fclose()           | Closes a file                 |
| e()         | feof()             | Checks end-of-file            |
| err()       | ferror()           | Checks file error             |
| gchr()      | fgetc()            | Gets a char from a file       |
| gc()        | getchar()          | Gets char from stdin          |
| getl()      | fgets()            | Reads a line from file        |
| o()         | fopen()            | Opens a file                  |
| fpc()       | fputc()            | Writes a char to a file       |
| pc()        | putc() / putchar() | Writes a char to stdout/file  |
| fps()       | fputs()            | Writes string to file         |
| fr()        | fread()            | Reads block from file         |
| fsk()       | fseek()            | Moves file pointer            |
| ft()        | ftell()            | Returns file pointer position |
| fw()        | fwrite()           | Writes block to file          |
| pchr()      | putchar()          | Outputs a char to stdout      |
| ps()        | puts()             | Outputs a string to stdout    |
| rn()        | rename()           | Renames a file                |
| rw()        | rewind()           | Resets file pointer to start  |
| rm()        | remove()           | Deletes a file                |

<br>
https://files.catbox.moe/b6m7nw.mp4

<!-- Social Links -->
<p align="center" style="margin-top: 0;">
  <a href="https://www.youtube.com/@kad3n470" title="YouTube" target="_blank" rel="noopener noreferrer">
    <img width="32" alt="YouTube" src="https://i.imgur.com/qiXu7b2.png" />
  </a>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <a href="https://www.linkedin.com/in/kaden-oberfeld/" title="LinkedIn" target="_blank" rel="noopener noreferrer">
    <img width="32" alt="LinkedIn" src="https://i.imgur.com/yRpa1dQ.png" />
  </a>
</p>

<!-- Typing SVG Headings -->
<p align="center">
  <img src="https://readme-typing-svg.demolab.com/?lines=Welcome%200xD&font=Fira%20Code&center=true&width=400&height=45&color=87CEEB&pause=0&speed=30&size=28&vCenter=true" alt="Welcome 0xD"/>
</p>
<p align="center">
  <img src="https://readme-typing-svg.demolab.com/?lines=(Cryptologist%2FRed-teamer%2FPentester%2FDeveloper)&font=Fira%20Code&center=true&width=600&height=45&color=708090&pause=0&speed=50&size=22&vCenter=true" alt="Cryptologist/Red-teamer/Pentester/Developer"/>
</p>
<p align="center">
  <img src="https://readme-typing-svg.demolab.com/?lines={Cypherpunk}&font=Fira%20Code&center=true&width=600&height=45&color=4682B4&pause=3000&speed=70&size=22&vCenter=true" alt="{Cypherpunk}"/>
</p>

<!-- GitHub Stats -->
<p align="center">
  <img src="https://github-readme-stats.vercel.app/api?username=Kad3n13&show_icons=true&theme=radical&bg_color=1F222E&title_color=87CEEB&icon_color=708090&hide_border=true"/>
  <img src="https://github-readme-stats.vercel.app/api/top-langs/?username=Kad3n13&layout=compact&theme=radical&bg_color=1F222E&title_color=708090&hide_border=true&langs_count=8"/>
  <img src="https://github-readme-streak-stats.herokuapp.com/?user=Kad3n13&theme=radical&background=1F222E&ring=87CEEB&fire=708090&currStreakNum=4682B4&sideNums=708090&currStreakLabel=87CEEB&sideLabels=708090&dates=87CEEB&hide_border=true"/>
</p>

---

## About My Custom Libraries & Projects

I am currently developing **low-level C libraries** that reimplement standard functionality from scratch to deepen my understanding of systems programming.  
Many of my current libraries are **stubs or minimal implementations**, serving as foundations for more complete tools in the future.

> 🚧 **Note:** These are work-in-progress and will expand over time to cover full functionality and additional low-level system components, all crafted in pure C with no external dependencies.

Examples include:
- Custom stdio functions (e.g., `fclose()`, `fopen()` replacements)
- Minimal string and memory management utilities
- Basic cryptographic primitives implemented manually  
- Modular building blocks for OS and security tooling

---

Skills Learned & Areas of Expertise

    Low-Level Systems Programming: Designing and implementing core C standard library functions from scratch

    File I/O Management: Building custom file handling operations (e.g., open, read, write, close) without relying on existing libraries

    Memory and Buffer Control: Managing buffers and pointers safely in pure C

    Minimalist API Design: Creating simple, readable, and reusable function interfaces tailored to project needs

    Code Obfuscation Techniques: Applying custom naming conventions for function and variable obfuscation

    Debugging & Testing: Verifying functionality and robustness of foundational C utilities without external dependencies

    Documentation & Code Clarity: Writing clear comments and consistent naming to explain low-level behaviors

---

## Tech Stack & Languages

| Language         | Level             | Notes                                      |
|------------------|-------------------|--------------------------------------------|
| C                | Intermediate      | Pure C from scratch, low-level libs        |
| Rust             | Beginner          | Secure, performant systems                 |
| Assembly (x86/ARM)| Beginner         | Embedded & OS kernel programming           |
| JavaScript       |  Beginner         | Web tooling, bootloader scripting          |
| Python           | Beginner          | Automation, scripting, testing             |
| Markdown & HTML   | Fluent           | Documentation, READMEs                     |


## Future Plans

- Complete and refine my custom C stdio and stdlib replacements  
- Expand cryptographic algorithms implemented purely in C  
- Build a small OS kernel with minimal dependencies  
- Contribute to open source projects emphasizing security and low-level programming  
- Share progress through YouTube tutorials and blog posts  

---
## stdio-like Implementation Status

### What I’ve Got Done So Far  
- Core file I/O:  
  `c()` (fclose), `o()` (fopen), `fr()` (fread), `fw()` (fwrite), `fsk()` (fseek), `ft()` (ftell), `rw()` (rewind)  
- Basic char I/O:  
  `gchr()` (fgetc), `gc()` (getchar), `fpc()` (fputc), `pc()` (putc), `pchr()` (putchar)  
- String I/O:  
  `getl()` (fgets), `fps()` (fputs), `ps()` (puts)  
- File management:  
  `r()` (remove), `rn()` (rename)  
- Error and EOF checks:  
  `e()` (feof), `err()` (ferror)  
- Aliases:  
  `gct()` (getc alias)  

### What’s Stubbed (Implemented but Not Fully Working)  
- Formatted I/O functions (just stubs returning -1):  
  `fp()` (fprintf), `pf()` (printf), `fs()` (fscanf), `snp()` (snprintf), `sp()` (sprintf), `ssf()` (sscanf)  

### What I’m Still Missing / Need to Add  
- Buffering stuff: `setbuf()`, `setvbuf()`, `fflush()`  
- Stream control: `freopen()`, `clearerr()`  
- Error reporting: `perror()`  
- Temporary files: `tmpfile()`, `tmpnam()`  
- Standard streams: `stdin`, `stdout`, `stderr`  
- Macros like `getc()`, `putc()`  

---
## MISSING 
I’m missing about 15 functions or features to fully cover stdio.h:

Buffering: setbuf(), setvbuf(), fflush()

Stream control: freopen(), clearerr()

Error reporting: perror()

Temporary files: tmpfile(), tmpnam()

Standard streams: stdin, stdout, stderr (global FILE pointers)

Macros: getc(), putc() (usually simple wrappers around existing functions)

That’s roughly 15 core things still needed beyond what I’ve implemented or stubbed so far.

### Summary

Right now, I have about **24** core functions either fully done or stubbed, covering the basic file and char I/O without buffering or formatting.

<details>
<summary><strong>Show Social Badges & More Info</strong></summary>

<!-- Social Badges -->
<p align="center">
  <a href="https://www.youtube.com/channel/UCxjgfIsIVTuHPeKE96vdKYg?sub_confirmation=1">
    <img alt="YouTube Subscribers" src="https://img.shields.io/youtube/channel/subscribers/UCxjgfIsIVTuHPeKE96vdKYg?style=for-the-badge&color=87CEEB&labelColor=708090" />
  </a>
  <a href="https://www.youtube.com/channel/UCxjgfIsIVTuHPeKE96vdKYg">
    <img alt="YouTube Views" src="https://img.shields.io/youtube/channel/views/UCxjgfIsIVTuHPeKE96vdKYg?style=for-the-badge&color=708090&labelColor=4682B4" />
  </a>
  <a href="https://github.com/Kad3n13?tab=repositories&sort=stargazers">
    <img alt="GitHub Stars" src="https://custom-icon-badges.demolab.com/github/stars/Kad3n13?color=4682B4&style=for-the-badge&labelColor=708090&logo=star" />
  </a>
  <a href="https://github.com/Kad3n13?tab=followers">
    <img alt="GitHub Followers" src="https://custom-icon-badges.demolab.com/github/followers/Kad3n13?color=87CEEB&labelColor=708090&style=for-the-badge&logo=person-add&label=Follow&logoColor=white" />
  </a>
</p>

</details>
