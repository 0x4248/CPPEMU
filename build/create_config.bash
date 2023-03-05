#.config generator for the emulator
#This script is used to generate the .config file for the emulator
#It is called by make

# THis script will ask for the following 
# Debug mode
# Trace mode
# Version

# The script will then generate the .config file
# If the config file already exists, it will be overwritten


# When writing to the .config file write like this
# DEBUG_MODE = y
# TRACE_MODE = n
# VERSION = 1.0.0

# If the user does not want to overwrite the .config file, the script should exit

# The script will be called by make

# First check if the .config file exists
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
