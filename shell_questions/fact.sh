echo "Enter number:"
read number
fact=1
i=1
while(( i<=number ))
    do
    ((fact=fact*i))
    ((i=i+1))
    done
echo "The factorial is $fact."