<?php
print("Problem Name => ");
$name = fgets(STDIN);
preg_match('/[0-9]+/', $name, $num);
preg_match('/[a-zA-Z]+\s?[a-zA-Z]+/', $name, $names);
$name = $num[0].' - '.$names[0].".cpp";
print($name . "\n");
if (@file_put_contents($name,file_get_contents('C:\Users\hp\eclipse-workspace\acm\src\acm.cpp')))
	print("File created \n");
echo shell_exec("git add -A")."\n";
echo shell_exec("git commit -m 'solved'")."\n";
echo shell_exec("git push -u -f origin master")."\n";
print('https://github.com/hsmfawaz/UVA-Solutions-cpp/blob/master/'.$name."\n");