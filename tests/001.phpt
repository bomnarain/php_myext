--TEST--
Check if mytext is loaded
--SKIPIF--
<?php
if (!extension_loaded('mytext')) {
	echo 'skip';
}
?>
--FILE--
<?php
echo 'The extension "mytext" is available';
?>
--EXPECT--
The extension "mytext" is available
