<?
while(true)
{
	list($a0, $a1, list($a2, $a3)) = each($a);
}

while (list($obj_key, $obj_val) = each ($obj_vars))
{
	echo $obj_key;
}

list($b1, $b2, $b3) = $a[4];

while (list ($a1, $a2, $a3, list ($a4, $a5, list ($a6, $a7))) = each($a))
{
  $test = $a;
  echo 1;
}

list($b1, $b2, $b3) = array(1,2,3);
list($b1, $b2, $b3) = $c+$b;

$c[0] = $a[0];
$c[1] = $a[1][0];
$c[2] = $a[1][1];

if (list(list($c[0], $c[1]),$c[2], $c[3], $c[4], $c5) = each($a))
{
  echo 2;
}

list(list(list($c22)),$c3) = $a[0];


list($c1, list($c2, list($c20, $c21, list($c22)), $c3), list($c4), $c5, $c6) = $a[1][2];

list($a, $b, $c) = $d;

function f1($a = 2)
{
	return $a;
}

function f2($a, $b = 1)
{
	echo $a+$b;
}

$r = substr(30, strlen(50));
$a = f2(f1(20));

class aa
{
	var $c = true;
	var $d = array(1,2);
}

?>
