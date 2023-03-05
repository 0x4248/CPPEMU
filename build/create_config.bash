if [ -f .config ]; then
    echo "The .config file already exists, do you want to overwrite it? (y/n)"
    read overwrite
    if [ $overwrite == "n" ]; then
        exit
    fi
fi

echo "Do you want debug mode? (y/n)"
read debug_mode
echo "Do you want trace mode? (y/n)"
read trace_mode
echo "Enter the version"
read version

echo "DEBUG_MODE = $debug_mode" > .config
echo "TRACE_MODE = $trace_mode" >> .config
echo "VERSION = $version" >> .config
