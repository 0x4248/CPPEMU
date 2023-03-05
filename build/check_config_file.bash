# checks if .config exists
if [ -f .config ]; then
exit 0
fi
echo "The .config file does not exist you need to run make config to crate it."
exit 1
