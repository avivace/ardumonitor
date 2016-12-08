+
<?php
$myfile = fopen("output.txt", "r") or die("Unable to open file");
echo fread($myfile,filesize("output.txt"));
fclose($myfile);
?>
