if [[ -d "bash" ]]
then
    echo "Bash exists"
else
    echo "Does not exist"
    echo "Creating dir..."
    mkdir ./bash
    ls
fi