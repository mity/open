
# Readme


## Introduction

This is very simple Windows command line utility for opening applications. It
actually triggers the same actions as double-click on the corresponding file
in a folder window.

In some shells other than `cmd.com` (e.g. Cygwin, MSYS, MSYS2 and others),
launching a GUI application blocks the shell until the given application
is terminated.

In such environments, user can use this utility to open them indirectly:

```
$ open notepad.exe
```


## Word of Caution

This code is not really actively maintained. If you have any plans to expand
it in any significant way, please do it freely in your own fork but do not
bother creating pull requests or bug reports.
