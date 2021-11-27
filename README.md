# pipex
Pipes and redirects in c

Objective is to code the Pipex program.
It should be executed in this way:
$> ./pipex file1 cmd1 cmd2 file2

Just in case: file1 and file2 are file names, cmd1 and cmd2 are shell commands with
their parameters.

The execution of the pipex program should do the same as the next shell command:
$> < file1 cmd1 | cmd2 > file2
