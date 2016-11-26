a=0
while true; do
	sleep 30
	echo "[UPTIME]" > stats.txt
	uptime >> stats.txt
	echo "[MEMINFO]" >> stats.txt
	cat /proc/meminfo >> stats.txt
	echo "Refresh $a"
	ruby parser.rb stats.txt > output.txt
	cat output.txt
	((a++))
	mv output.txt /var/www/html/apps/statm/
done
