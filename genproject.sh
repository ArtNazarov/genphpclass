while read line
 do   
   echo -e "$line\n"
   ./genphpclass $line
done < $1
