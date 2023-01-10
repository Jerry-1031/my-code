//Luogu P4718
//on linux
#include <iostream>

int main()
{
	system(R"(
	read a
	for i in `seq 1 $a`; do
	    read t
	    s=`factor $t`
	    ss=`echo $s | sed "s/[0-9:]//g"`
	    if [ ${#ss} -eq 1 ]; then
	        echo Prime
	    else
	        echo $s | sed "s/ /\n/g" | tail -n1
	    fi
	done
	)");
	return 0;
}
