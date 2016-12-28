<?
  function Myadd($a , $b)
  {
  	$c = $a + $b;
  	return $c;
  }
  
  function func1()
  {
  	static $a = 0;
  	$a++;
  	return $a++;
  }
  
  $lkqzzy = 1;
  $a = "abc";
  $b = $a."?";
  $c = func1();
  $m_aa = func1(Myadd(3,88));
  echo $m_aa;
?>
<font size = "3">fjslf</font>
<font color = 'red'>aa</font>

