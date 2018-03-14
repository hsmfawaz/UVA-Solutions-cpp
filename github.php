<?php
print("Problem Name => ");
fscanf(STDIN, "%s\n", $name);
$bad = array_merge(
    array_map('chr', range(0, 31)),
    array("<", ">", ":", '"', "/", "\\", "|", "?", "*"));
$name = str_replace($bad, "", $name) . ".cpp";
print($name . "\n");
$cppfile = file_get_contents('C:\Users\hp\eclipse-workspace\acm\src\acm.cpp');
if (@file_put_contents($name,$cppfile))
	print("File created \n");
echo exec("git add -A")."\n";
echo shell_exec("git commit -m 'Solved'")."\n";
echo shell_exec("git push -u -f origin master")."\n";
print('https://github.com/hsmfawaz/UVA-Solutions-cpp/blob/master/'.$name."\n");