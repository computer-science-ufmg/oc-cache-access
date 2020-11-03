# make
if (( $# > 0 )) 
then
  ./tp3 $1
else
  ./tp3 input/in01.txt
fi