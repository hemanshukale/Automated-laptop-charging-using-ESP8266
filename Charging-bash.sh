#!/bin/bash


url=http://10.42.3.204:999/

h1=swi
hon=g
hoff=h

function compare
{
echo "$1 at $d"
        if [[ $2 == *Dis* ]] ; then 
     		if (($1<31)); then
		   echo "Starting charger";
		   start "$w"
		else echo "greater than 30";
		fi
	else
		if (($1>83)) ; then
		   echo "Shutting charger";
 		   shut "$w"
		else echo "less than 84";
		fi
	fi
}

function send
 {
   curl $1$2$3
 }


function shut
{
   send $url $h1 $hoff
}

function start
{	

   send $url $h1 $hon

}



###########################  LOOP STARTS  ###################################

while :
do

v1=$(acpi)
v2=$(acpi | grep -o -P "(?<=, ).*(?=%,)" | grep -oE '[0-9]+')

echo $v1 $v3
d=$(date +%T)

compare $v2 "$v1"

sleep 20;

done

###########################  LOOP STARTS  ###################################


