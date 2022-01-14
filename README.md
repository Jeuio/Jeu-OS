# <b>Jeu-OS</b>
##### made by Leon-Patrick Hammerich
<br>

## Contents:
[Summary](#summary)<br>
[How to use](#how-to-use)<br>
[Questions you might have](#questions-you-might-have)<br>
[License](#license)
[Sources](#sources)
<br>

<a id = "summary"></a>
## Summary
A little custom OS with kernel written in C++ supporting display output
through VGA driver and keyboard input through the optical input channel.
<br>

<a id = "how-to-use"></a>
## How to use
<p>
I'd recommend using a Linux-like system or alternatively a Linux environment
like MinGW if you are on a Windows system. I would also strongly
advise to only run this on a virtual machine, as I can't guarantee that
this software will leave the hardware components intact.
<br>

### How to compile:
#### Make sure to have the following software installed:
</p>
<ul>
<li><b>Make</b> (build tool)</li>
<li><b>g++</b> (compiler)</li>
<li><b>ld</b> (linker (usually contained in the compiler))</li>
<li><b>basic programs for copying files via command line</b></li>
</ul>
These are the programs that I use for compilation, but feel free to
replace them with whatever you like, if you know what you are doing.
<br>

### How to run:
<p>
After compiling the project you will be left with a bin file, containing the
OS-binary. You can now put them at the start of a hard-drive to make
it bootable by the BIOS. It shouldn't matter if the hard-drive is physical
or simulated by a VM, but I'd advise using the latter.<br>
You may want to use an ISO file for running the OS, which is currently not
supported by my version of the OS, which means you have to do it yourself.
</p>
<br>


<a id = "questions-you-might-have"></a>
## Questions you might have

### What is the purpose of this project?
<p>
This project is meant to be a standalone operating system currently
specialized in providing an interface to the user that allows them to
play a simple version of chess without any rules, except that the pieces
are unable to commit suicide. It was created in the context of a computer
science class project.
</p>
<br>

### Why go through the effort of writing an OS?
<p>
Creating an OS requires knowledge about how computers work on the most
fundamental level, providing a learning challenge and paving the way
for future projects requiring these skills, like custom programming
languages.
</p><p>
Additionally, since I have control over all the processes taking place
throughout the execution, the OS can be optimised for a specific purpose
(chess in this case)
</p>
<br>

<a id = "license"></a>
## License information
Please mind the license: <a href = "LICENSE">License</a>
<br>

<a id = "sources"></a>
## Sources:
<ul>
<li><a href="https://wiki.osdev.org/Main_Page">OSDev.org</a></li>
<li><a href="https://www.cs.bham.ac.uk/~exr/lectures/opsys/10_11/lectures/os-dev.pdf">Writing a Simple Operating System — from Scratch</a></li>
</ul>
<br>
Many thanks to the authors of these sources for providing such detailed
explanations!
