--TEST--
mytext_test1() Basic test
--SKIPIF--
<?php
if (!extension_loaded('mytext')) {
	echo 'skip';
}
?>
--FILE--
<?php
$ret = mytext_test1();

var_dump($ret);
?>
--EXPECT--
The extension mytext is loaded and working!
NULL
