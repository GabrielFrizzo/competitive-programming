#!/usr/bin/zsh
for i in {2..10000}
do
	if [[ $(echo $i | ./a.out) != $(echo $i | ./b.out) ]]; then
		echo $i
	fi
	
done