#!/usr/bin/ruby env

file_rows = File.readlines(ARGV[0])

memTotal_re = /MemTotal:\s*([^\b]+)/
memAval_re = /MemAvailable:\s*([^\b]+)/
loadAvg_re = /load average:\s*([^\b]+)/


file_rows.each do |line|
	if line =~ memTotal_re
		$memTotal_raw = $1
	end
	if line =~ memAval_re
		$memAval_raw = $1
	end
	if line =~ loadAvg_re
		$loadAvg_raw = $1
	end
end

memTotal = $memTotal_raw.to_i/1024
memAval = $memAval_raw.to_i/1024
memUsed = memTotal - memAval
loadAvg = $loadAvg_raw.split(/\s*,\s*/)
loadAvg_15 = (loadAvg[0].to_f * 100).to_i

print memUsed.to_s + "/" + memTotal.to_s + " " + loadAvg[1].to_s