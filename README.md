# <b>Jeu-OS</b>
##### made by Leon-Patrick Hammerich
<br>

## Summary
A little custom OS with kernel written in C++ supporting display output
through VGA driver and keyboard input through optical input.

## How to use:

<p>
I'd recommend using a Linux-like system or alternatively a Linux environment
like MinGW if you are on a Windows system. I would also strongly
advise to only run this on a virtual machine, as I can't guarantee that
this software will leave the hardware component intact.<br>

### How to compile:
#### Make sure to have the following software installed:</b>
</p>
<ul>
<li><b>Make</b> (build tool)</li>
<li><b>g++</b> (compiler)</li>
<li><b>ld</b> (linker (usually contained in the compiler))</li>
<li><b>basic programs for copying files via command line</b></li>
</ul>
These are the programs that I use for compilation, but feel free to
replace them with whatever you like, if you know what you are doing.

### How to run:
<p>
After compiling the project you will be left with a bin file, containing the
OS-binary. You can now put them at the start of a hard-drive to make
it bootable by the BIOS. It shouldn't matter if the hard-drive is physical
or simulated by a VM, but I'd advise using the latter.<br>
You may want to use an ISO file for running the OS, which is currently not
supported by my version of the OS, which means you have to do it yourself.
</p>


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


## Sources: